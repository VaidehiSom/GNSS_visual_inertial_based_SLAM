#pragma once

#include <cstdio>
#include <iostream>
#include <queue>
#include <execinfo.h>
#include <csignal>

#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Dense>

#include "camodocal/camera_models/CameraFactory.h"
#include "camodocal/camera_models/CataCamera.h"
#include "camodocal/camera_models/PinholeCamera.h"

#include "parameters.h"
#include "tic_toc.h"

using namespace std;
using namespace camodocal;
using namespace Eigen;

bool inBorder(const cv::Point2f &pt);

void reduceVector(vector<cv::Point2f> &v, vector<uchar> status);
void reduceVector(vector<int> &v, vector<uchar> status);

class FeatureTracker
{
  public:
    FeatureTracker();

    void readImage(const cv::Mat &_img,double _cur_time);

    void setMask();

    void addPoints();

    bool updateID(unsigned int i);

    void readIntrinsicParameter(const string &calib_file);

    void showUndistortion(const string &name);

    void rejectWithF();

    void undistortedPoints();

    cv::Mat m_mask;
    cv::Mat m_fisheye_mask;
    cv::Mat m_prev_img, m_cur_img, m_forw_img;
    vector<cv::Point2f> m_n_pts;
    vector<cv::Point2f> m_prev_pts, m_cur_pts, m_forw_pts;
    vector<cv::Point2f> m_prev_un_pts, m_cur_un_pts;
    vector<cv::Point2f> m_pts_velocity;
    vector<int> m_ids;
    vector<int> m_track_cnt;
    map<int, cv::Point2f> m_cur_un_pts_map;
    map<int, cv::Point2f> m_prev_un_pts_map;
    camodocal::CameraPtr m_camera;
    double m_cur_time;
    double m_prev_time;

    static int m_n_id;
};
