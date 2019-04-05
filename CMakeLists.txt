cmake_minimum_required(VERSION 2.8.3)
project(ros_button)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        rospy
        std_msgs
        genmsg
        message_generation
)

add_message_files(
        DIRECTORY msg
        FILES push_button.msg
)

generate_messages(DEPENDENCIES std_msgs)

catkin_package()


include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(button src/button.cpp)
target_link_libraries(button ${catkin_LIBRARIES})
add_dependencies(button row_button_generate_messages_cpp)
