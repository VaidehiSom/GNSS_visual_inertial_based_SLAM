# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "gvins: 1 messages, 0 services")

set(MSG_I_FLAGS "-Igvins:/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(gvins_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg/LocalSensorExternalTrigger.msg" NAME_WE)
add_custom_target(_gvins_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "gvins" "/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg/LocalSensorExternalTrigger.msg" "std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(gvins
  "/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg/LocalSensorExternalTrigger.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gvins
)

### Generating Services

### Generating Module File
_generate_module_cpp(gvins
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gvins
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(gvins_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(gvins_generate_messages gvins_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg/LocalSensorExternalTrigger.msg" NAME_WE)
add_dependencies(gvins_generate_messages_cpp _gvins_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(gvins_gencpp)
add_dependencies(gvins_gencpp gvins_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS gvins_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(gvins
  "/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg/LocalSensorExternalTrigger.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/gvins
)

### Generating Services

### Generating Module File
_generate_module_eus(gvins
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/gvins
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(gvins_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(gvins_generate_messages gvins_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg/LocalSensorExternalTrigger.msg" NAME_WE)
add_dependencies(gvins_generate_messages_eus _gvins_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(gvins_geneus)
add_dependencies(gvins_geneus gvins_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS gvins_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(gvins
  "/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg/LocalSensorExternalTrigger.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gvins
)

### Generating Services

### Generating Module File
_generate_module_lisp(gvins
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gvins
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(gvins_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(gvins_generate_messages gvins_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg/LocalSensorExternalTrigger.msg" NAME_WE)
add_dependencies(gvins_generate_messages_lisp _gvins_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(gvins_genlisp)
add_dependencies(gvins_genlisp gvins_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS gvins_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(gvins
  "/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg/LocalSensorExternalTrigger.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/gvins
)

### Generating Services

### Generating Module File
_generate_module_nodejs(gvins
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/gvins
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(gvins_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(gvins_generate_messages gvins_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg/LocalSensorExternalTrigger.msg" NAME_WE)
add_dependencies(gvins_generate_messages_nodejs _gvins_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(gvins_gennodejs)
add_dependencies(gvins_gennodejs gvins_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS gvins_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(gvins
  "/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg/LocalSensorExternalTrigger.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gvins
)

### Generating Services

### Generating Module File
_generate_module_py(gvins
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gvins
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(gvins_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(gvins_generate_messages gvins_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vaidehi/Downloads/github/GNSS_visual_inertial_based_SLAM/src/GVINS/estimator/msg/LocalSensorExternalTrigger.msg" NAME_WE)
add_dependencies(gvins_generate_messages_py _gvins_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(gvins_genpy)
add_dependencies(gvins_genpy gvins_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS gvins_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gvins)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gvins
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(gvins_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/gvins)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/gvins
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(gvins_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gvins)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gvins
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(gvins_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/gvins)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/gvins
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(gvins_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gvins)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gvins\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gvins
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(gvins_generate_messages_py std_msgs_generate_messages_py)
endif()
