cmake_minimum_required(VERSION 2.8.3)
project(idmind_msgs)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    genmsg
    nav_msgs
    std_msgs
    geometry_msgs
    actionlib_msgs
    message_generation
)

add_message_files(
  FILES
  Bumpers.msg
  Leds.msg
  Obstacles.msg
  ClosestObstacles.msg
  SystemStatus.msg
  Voltages.msg
  Encoders.msg
  Log.msg  
  HubMotorState.msg
)

add_service_files(
  FILES
  CreateTask.srv
  SetInt.srv
)

## Generate actions in the 'action' folder
add_action_files(
  FILES
  NavControl.action  
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs  # Or other packages containing msgs
  nav_msgs
  geometry_msgs
  actionlib_msgs
)

catkin_package(
  CATKIN_DEPENDS rospy message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
