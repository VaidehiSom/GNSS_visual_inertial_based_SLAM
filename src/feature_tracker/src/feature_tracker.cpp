#include "feature_tracker.h"

int FeatureTracker::m_n_id = 0;

bool inBorder(const cv::Point2f &pt)
{
    const int BORDER_SIZE = 1;
    int img_x = cvRound(pt.x);
    int img_y = cvRound(pt.y);
    return BORDER_SIZE <= img_x && img_x < COL - BORDER_SIZE && BORDER_SIZE <= img_y && img_y < ROW - BORDER_SIZE;
}

void reduceVector(vector<cv::Point2f> &v, vector<uchar> status)
{
    int j = 0;
    for (int i = 0; i < int(v.size()); i++)
        if (status[i])
            v[j++] = v[i];
    v.resize(j);
}

void reduceVector(vector<int> &v, vector<uchar> status)
{
    int j = 0;
    for (int i = 0; i < int(v.size()); i++)
        if (status[i])
            v[j++] = v[i];
    v.resize(j);
}


FeatureTracker::FeatureTracker()
{
}

void FeatureTracker::setMask()
{
    if(FISHEYE)
        mask = m_fisheye_mask.clone();
    else
        mask = cv::Mat(ROW, COL, CV_8UC1, cv::Scalar(255));
    

    // prefer to keep features that are tracked for long time
    vector<pair<int, pair<cv::Point2f, int>>> cnt_pts_id;

    for (unsigned int i = 0; i < m_forw_pts.size(); i++)
        cnt_pts_id.push_back(make_pair(m_track_cnt[i], make_pair(m_forw_pts[i], m_ids[i])));

    sort(cnt_pts_id.begin(), cnt_pts_id.end(), [](const pair<int, pair<cv::Point2f, int>> &a, const pair<int, pair<cv::Point2f, int>> &b)
         {
            return a.first > b.first;
         });

    m_forw_pts.clear();
    m_ids.clear();
    m_track_cnt.clear();

    for (auto &it : cnt_pts_id)
    {
        if (mask.at<uchar>(it.second.first) == 255)
        {
            m_forw_pts.push_back(it.second.first);
            m_ids.push_back(it.second.second);
            m_track_cnt.push_back(it.first);
            cv::circle(mask, it.second.first, MIN_DIST, 0, -1);
        }
    }
}

void FeatureTracker::addPoints()
{
    for (auto &p : m_n_pts)
    {
        m_forw_pts.push_back(p);
        m_ids.push_back(-1);
        m_track_cnt.push_back(1);
    }
}

void FeatureTracker::readImage(const cv::Mat &_img, double _cur_time) // feature tracker node
{
    cv::Mat img;
    m_cur_time = _cur_time;

    if (EQUALIZE)
    {
        cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE(3.0, cv::Size(8, 8));
        clahe->apply(_img, img);
    }
    else
        img = _img;

    if (m_forw_img.empty())
    {
        m_prev_img = m_cur_img = m_forw_img = img;
    }
    else
    {
        m_forw_img = img;
    }

    m_forw_pts.clear();

    if (m_cur_pts.size() > 0)
    {
        vector<uchar> status;
        vector<float> err;
        cv::calcOpticalFlowPyrLK(m_cur_img, m_forw_img, m_cur_pts, m_forw_pts, status, err, cv::Size(21, 21), 3);

        for (int i = 0; i < int(m_forw_pts.size()); i++)
            if (status[i] && !inBorder(m_forw_pts[i]))
                status[i] = 0;
        reduceVector(m_prev_pts, status);
        reduceVector(m_cur_pts, status);
        reduceVector(m_forw_pts, status);
        reduceVector(m_ids, status);
        reduceVector(m_cur_un_pts, status);
        reduceVector(m_track_cnt, status);
    }

    for (auto &n : m_track_cnt)
        n++;

    if (PUB_THIS_FRAME)
    {
        rejectWithF();
        setMask();
        // detect feature begins
        int n_max_cnt = MAX_CNT - static_cast<int>(m_forw_pts.size());
        if (n_max_cnt > 0)
        {
            if(mask.empty())
                cout << "mask is empty " << endl;
            if (mask.type() != CV_8UC1)
                cout << "mask type wrong " << endl;
            if (mask.size() != m_forw_img.size())
                cout << "wrong size " << endl;
            cv::goodFeaturesToTrack(m_forw_img, m_n_pts, MAX_CNT - m_forw_pts.size(), 0.01, MIN_DIST, mask); //! check the function
        }
        else
            m_n_pts.clear();
        addPoints(); // add feature begins
    }
    m_prev_img = m_cur_img;
    m_prev_pts = m_cur_pts;
    m_prev_un_pts = m_cur_un_pts;
    m_cur_img = m_forw_img;
    m_cur_pts = m_forw_pts;
    undistortedPoints();
    m_prev_time = m_cur_time;
}

void FeatureTracker::rejectWithF()
{
    if (m_forw_pts.size() >= 8)
    {
        // FM ransac begins
        vector<cv::Point2f> un_cur_pts(m_cur_pts.size()), un_forw_pts(m_forw_pts.size());
        for (unsigned int i = 0; i < m_cur_pts.size(); i++)
        {
            Eigen::Vector3d tmp_p;
            //! check const Eigen::Vector2d how is this passing into func being not const
            m_camera->liftProjective(Eigen::Vector2d(m_cur_pts[i].x, m_cur_pts[i].y), tmp_p); // Lifts a point from the image plane to its projective ray
            tmp_p.x() = FOCAL_LENGTH * tmp_p.x() / tmp_p.z() + COL / 2.0; //! exactly what is the equation
            tmp_p.y() = FOCAL_LENGTH * tmp_p.y() / tmp_p.z() + ROW / 2.0; // normalizing and accounting for u,v
            un_cur_pts[i] = cv::Point2f(tmp_p.x(), tmp_p.y());

            m_camera->liftProjective(Eigen::Vector2d(m_forw_pts[i].x, m_forw_pts[i].y), tmp_p);
            tmp_p.x() = FOCAL_LENGTH * tmp_p.x() / tmp_p.z() + COL / 2.0;
            tmp_p.y() = FOCAL_LENGTH * tmp_p.y() / tmp_p.z() + ROW / 2.0;
            un_forw_pts[i] = cv::Point2f(tmp_p.x(), tmp_p.y());
        }

        vector<uchar> status;
        cv::findFundamentalMat(un_cur_pts, un_forw_pts, cv::FM_RANSAC, F_THRESHOLD, 0.99, status);
        int size_a = m_cur_pts.size();
        reduceVector(m_prev_pts, status);
        reduceVector(m_cur_pts, status);
        reduceVector(m_forw_pts, status);
        reduceVector(m_cur_un_pts, status);
        reduceVector(m_ids, status);
        reduceVector(m_track_cnt, status);
        ROS_DEBUG("FM ransac: %d -> %lu: %f", size_a, m_forw_pts.size(), 1.0 * m_forw_pts.size() / size_a);
    }
}

bool FeatureTracker::updateID(unsigned int i) // feature tracker node
{
    if (i < m_ids.size())
    {
        if (m_ids[i] == -1)
            m_ids[i] = m_n_id++;
        return true;
    }
    else
        return false;
}

void FeatureTracker::readIntrinsicParameter(const string &calib_file) // feature tracker node
{
    ROS_INFO("reading paramerter of camera %s", calib_file.c_str());
    m_camera = CameraFactory::instance()->generateCameraFromYamlFile(calib_file);
}

void FeatureTracker::showUndistortion(const string &name) // feature tracker node
{
    cv::Mat undistortedImg(ROW + 600, COL + 600, CV_8UC1, cv::Scalar(0));
    vector<Eigen::Vector2d> distortedp, undistortedp;
    for (int i = 0; i < COL; i++)
        for (int j = 0; j < ROW; j++)
        {
            Eigen::Vector2d a(i, j);
            Eigen::Vector3d b;
            m_camera->liftProjective(a, b);
            distortedp.push_back(a);
            undistortedp.push_back(Eigen::Vector2d(b.x() / b.z(), b.y() / b.z()));
            //printf("%f,%f->%f,%f,%f\n)\n", a.x(), a.y(), b.x(), b.y(), b.z());
        }
    for (int i = 0; i < int(undistortedp.size()); i++)
    {
        cv::Mat pp(3, 1, CV_32FC1);
        pp.at<float>(0, 0) = undistortedp[i].x() * FOCAL_LENGTH + COL / 2;
        pp.at<float>(1, 0) = undistortedp[i].y() * FOCAL_LENGTH + ROW / 2;
        pp.at<float>(2, 0) = 1.0;
        //cout << trackerData[0].K << endl;
        //printf("%lf %lf\n", p.at<float>(1, 0), p.at<float>(0, 0));
        //printf("%lf %lf\n", pp.at<float>(1, 0), pp.at<float>(0, 0));
        if (pp.at<float>(1, 0) + 300 >= 0 && pp.at<float>(1, 0) + 300 < ROW + 600 && pp.at<float>(0, 0) + 300 >= 0 && pp.at<float>(0, 0) + 300 < COL + 600)
        {
            undistortedImg.at<uchar>(pp.at<float>(1, 0) + 300, pp.at<float>(0, 0) + 300) = m_cur_img.at<uchar>(distortedp[i].y(), distortedp[i].x());
        }
        else
        {
            //ROS_ERROR("(%f %f) -> (%f %f)", distortedp[i].y, distortedp[i].x, pp.at<float>(1, 0), pp.at<float>(0, 0));
        }
    }
    cv::imshow(name, undistortedImg);
    cv::waitKey(0);
}

void FeatureTracker::undistortedPoints()
{
    m_cur_un_pts.clear();
    m_cur_un_pts_map.clear();
    //cv::undistortPoints(cur_pts, un_pts, K, cv::Mat());
    for (unsigned int i = 0; i < m_cur_pts.size(); i++)
    {
        Eigen::Vector2d a(m_cur_pts[i].x, m_cur_pts[i].y);
        Eigen::Vector3d b;
        m_camera->liftProjective(a, b);
        m_cur_un_pts.push_back(cv::Point2f(b.x() / b.z(), b.y() / b.z()));
        m_cur_un_pts_map.insert(make_pair(m_ids[i], cv::Point2f(b.x() / b.z(), b.y() / b.z())));
    }
    // caculate points velocity
    if (!m_prev_un_pts_map.empty())
    {
        double dt = m_cur_time - m_prev_time;
        m_pts_velocity.clear();
        for (unsigned int i = 0; i < m_cur_un_pts.size(); i++)
        {
            if (m_ids[i] != -1)
            {
                std::map<int, cv::Point2f>::iterator it;
                it = m_prev_un_pts_map.find(m_ids[i]);
                if (it != m_prev_un_pts_map.end())
                {
                    double v_x = (m_cur_un_pts[i].x - it->second.x) / dt;
                    double v_y = (m_cur_un_pts[i].y - it->second.y) / dt;
                    m_pts_velocity.push_back(cv::Point2f(v_x, v_y));
                }
                else
                    m_pts_velocity.push_back(cv::Point2f(0, 0));
            }
            else
            {
                m_pts_velocity.push_back(cv::Point2f(0, 0));
            }
        }
    }
    else
    {
        for (unsigned int i = 0; i < m_cur_pts.size(); i++)
        {
            m_pts_velocity.push_back(cv::Point2f(0, 0));
        }
    }
    m_prev_un_pts_map = m_cur_un_pts_map;
}
