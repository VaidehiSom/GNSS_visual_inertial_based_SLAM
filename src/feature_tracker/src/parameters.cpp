#include "parameters.h"

std::string IMAGE_TOPIC;
std::string IMU_TOPIC;
std::vector<std::string> CAM_NAMES;
std::string FISHEYE_MASK;
int MAX_CNT;
int MIN_DIST;
int WINDOW_SIZE;
int FREQ;
double F_THRESHOLD;
int SHOW_TRACK;
int STEREO_TRACK;
int EQUALIZE;
int ROW;
int COL;
int FOCAL_LENGTH;
int FISHEYE;
bool PUB_THIS_FRAME;

template <typename T>
T readParam(ros::NodeHandle &n, std::string name)
{
    T ans;
    if (n.getParam(name, ans))
    {
        ROS_INFO_STREAM("Loaded " << name << ": " << ans);
    }
    else
    {
        ROS_ERROR_STREAM("Failed to load " << name);
        n.shutdown();
    }
    return ans;
}

void readParameters(ros::NodeHandle &n)
{
    std::string config_file;
    config_file = readParam<std::string>(n, "config_file"); // loaded config file
    cv::FileStorage fsSettings(config_file, cv::FileStorage::READ); // reading from config file
    if(!fsSettings.isOpened()) // check if file exists
    {
        std::cerr << "ERROR: Wrong path to settings" << std::endl;
    }
    std::string GVINS_FOLDER_PATH = readParam<std::string>(n, "gvins_folder"); // loading gvins pkg folder path

    fsSettings["image_topic"] >> IMAGE_TOPIC; // reading image topic
    fsSettings["imu_topic"] >> IMU_TOPIC; // reading imu topic
    MAX_CNT = fsSettings["max_cnt"]; // max feature number in feature tracking
    MIN_DIST = fsSettings["min_dist"]; // min distance between two features
    ROW = fsSettings["image_height"];
    COL = fsSettings["image_width"];
    FREQ = fsSettings["freq"]; // frequence (Hz) of publish tracking result. At least 10Hz for good estimation. If set 0, the frequence will be same as raw image
    F_THRESHOLD = fsSettings["F_threshold"]; // ransac threshold (pixel)
    SHOW_TRACK = fsSettings["show_track"]; // publish tracking image as topic
    EQUALIZE = fsSettings["equalize"]; // if image is too dark or light, trun on equalize to find enough features
    FISHEYE = fsSettings["fisheye"]; // if using fisheye
    if (FISHEYE == 1)
        FISHEYE_MASK = GVINS_FOLDER_PATH + "config/fisheye_mask.jpg"; //! where is this file?
    CAM_NAMES.push_back(config_file);

    WINDOW_SIZE = 20;
    STEREO_TRACK = false; //! what is this?
    FOCAL_LENGTH = 460;
    PUB_THIS_FRAME = false;

    if (FREQ == 0)
        FREQ = 100;

    fsSettings.release();
}