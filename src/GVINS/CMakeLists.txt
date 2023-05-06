cmake_minimum_required(VERSION 2.8.3)
project(gvins_camera_model)

set(CMAKE_BUILD_TYPE "release")
set(CMAKE_CXX_FLAGS "-std=c++11 ")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -fPIC")

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    geometry_msgs
    nav_msgs
    tf
    cv_bridge
    rosbag
    message_generation
    gnss_comm
    sensor_msgs
    gvins_camera_model
    )

file(GLOB_RECURSE message_files ${PROJECT_SOURCE_DIR}/msg/*.msg)

add_message_files(
  DIRECTORY msg
  FILES 
  LocalSensorExternalTrigger.msg
  GnssTimeMsg.msg
  GnssEphemMsg.msg
  GnssGloEphemMsg.msg
  GnssMeasMsg.msg
  GnssObsMsg.msg
  GnssBestXYZMsg.msg
  GnssPVTSolnMsg.msg
  GnssSvsMsg.msg
  GnssTimePulseInfoMsg.msg
  StampedFloat64Array.msg
)

generate_messages(DEPENDENCIES std_msgs)

find_package(Boost REQUIRED COMPONENTS filesystem program_options system)
include_directories(${Boost_INCLUDE_DIRS})

find_package(OpenCV REQUIRED)
find_package(Ceres REQUIRED)
include_directories(${catkin_INCLUDE_DIRS} ${CERES_INCLUDE_DIRS})

catkin_package(
    INCLUDE_DIRS include
    CATKIN_DEPENDS roscpp std_msgs message_generation
    )

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(Eigen3 REQUIRED)
find_package(Glog REQUIRED)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
  ${GLOG_INCLUDE_DIR}
  ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/
)

file(GLOB_RECURSE source_files ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(${PROJECT_NAME} ${source_files})
target_include_directories(${PROJECT_NAME} PUBLIC
  ${EIGEN3_INCLUDE_DIR}
  ${catkin_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/
)

include_directories("include")


add_executable(${PROJECT_NAME} 
    # src/intrinsic_calib.cc
    # src/chessboard/Chessboard.cc
    src/calib/CameraCalibration.cc
    src/camera_models/Camera.cc
    src/camera_models/CameraFactory.cc
    src/camera_models/CostFunctionFactory.cc
    src/camera_models/PinholeCamera.cc
    src/camera_models/CataCamera.cc
    src/camera_models/EquidistantCamera.cc
    src/camera_models/ScaramuzzaCamera.cc
    src/sparse_graph/Transform.cc
    src/gpl/gpl.cc
    src/gpl/EigenQuaternionParameterization.cc
    
    src/estimator_node.cpp
    src/parameters.cpp
    src/estimator.cpp
    src/feature_manager.cpp
    src/factor/pose_local_parameterization.cpp
    src/factor/projection_factor.cpp
    src/factor/projection_td_factor.cpp
    src/factor/marginalization_factor.cpp
    src/factor/gnss_psr_dopp_factor.cpp
    src/factor/gnss_dt_ddt_factor.cpp
    src/factor/gnss_dt_anchor_factor.cpp
    src/factor/gnss_ddt_smooth_factor.cpp
    src/factor/pos_vel_factor.cpp
    src/factor/pose_anchor_factor.cpp
    src/utility/utility.cpp
    src/utility/visualization.cpp
    src/utility/CameraPoseVisualization.cpp
    src/initial/solve_5pts.cpp
    src/initial/initial_aligment.cpp
    src/initial/initial_sfm.cpp
    src/initial/initial_ex_rotation.cpp
    src/initial/gnss_vi_initializer.cpp
    
    src/feature_tracker_node.cpp
    src/parameters.cpp
    src/feature_tracker.cpp)

add_library(gvins_camera_model
    # src/chessboard/Chessboard.cc
    src/calib/CameraCalibration.cc
    src/camera_models/Camera.cc
    src/camera_models/CameraFactory.cc
    src/camera_models/CostFunctionFactory.cc
    src/camera_models/PinholeCamera.cc
    src/camera_models/CataCamera.cc
    src/camera_models/EquidistantCamera.cc
    src/camera_models/ScaramuzzaCamera.cc
    src/sparse_graph/Transform.cc
    src/gpl/gpl.cc
    src/gpl/EigenQuaternionParameterization.cc)

target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${OpenCV_LIBS} ${CERES_LIBRARIES} ${GLOG_LIBRARIES})
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_generate_messages_cpp)