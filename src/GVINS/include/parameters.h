#pragma once

#include <cstdlib>
#include <ros/ros.h>
#include <vector>
#include <eigen3/Eigen/Dense>
#include "utility/utility.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include <fstream>
#include <opencv2/highgui/highgui.hpp>

const double FOCAL_LENGTH = 460.0;
const int WINDOW_SIZE = 10;
const int NUM_OF_CAM = 1;
const int NUM_OF_F = 1000;
//#define UNIT_SPHERE_ERROR

extern double INIT_DEPTH;
extern double MIN_PARALLAX;

extern double ACC_N, ACC_W;
extern double GYR_N, GYR_W;

extern std::vector<Eigen::Matrix3d> RIC;
extern std::vector<Eigen::Vector3d> TIC;
extern Eigen::Vector3d G;

extern double BIAS_ACC_THRESHOLD;
extern double BIAS_GYR_THRESHOLD;
extern double SOLVER_TIME;
extern int NUM_ITERATIONS;
extern std::string VINS_RESULT_PATH;
extern std::string FACTOR_GRAPH_RESULT_PATH;
extern std::string IMU_TOPIC;
extern double TD;
extern int ESTIMATE_TD;
extern double ROW, COL;

extern std::string GNSS_EPHEM_TOPIC;
extern std::string GNSS_GLO_EPHEM_TOPIC;
extern std::string GNSS_MEAS_TOPIC;
extern std::string GNSS_IONO_PARAMS_TOPIC;
extern std::string GNSS_TP_INFO_TOPIC;
extern std::vector<double> GNSS_IONO_DEFAULT_PARAMS;
extern std::string LOCAL_TRIGGER_INFO_TOPIC;
extern double GNSS_LOCAL_TIME_DIFF;
extern double GNSS_ELEVATION_THRES;
extern double GNSS_PSR_STD_THRES;
extern double GNSS_DOPP_STD_THRES;
extern uint32_t GNSS_TRACK_NUM_THRES;
extern double GNSS_DDT_WEIGHT;
extern std::string GNSS_RESULT_PATH;

extern int ROW;
extern int COL;
extern int FOCAL_LENGTH;
const int NUM_OF_CAM = 1;

extern std::string IMAGE_TOPIC;
extern std::string IMU_TOPIC;
extern std::string FISHEYE_MASK;
extern std::vector<std::string> CAM_NAMES;
extern int MAX_CNT;
extern int MIN_DIST;
extern int WINDOW_SIZE;
extern int FREQ;
extern double F_THRESHOLD;
extern int SHOW_TRACK;
extern int STEREO_TRACK;
extern int EQUALIZE;
extern int FISHEYE;
extern bool PUB_THIS_FRAME;

void readParameters(ros::NodeHandle &n);

enum SIZE_PARAMETERIZATION
{
    SIZE_POSE = 7,
    SIZE_SPEEDBIAS = 9,
    SIZE_FEATURE = 1
};

enum StateOrder
{
    O_P = 0,
    O_R = 3,
    O_V = 6,
    O_BA = 9,
    O_BG = 12
};

enum NoiseOrder
{
    O_AN = 0,
    O_GN = 3,
    O_AW = 6,
    O_GW = 9
};
