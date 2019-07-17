#include <iostream>
#include "ros/ros.h"
#include "ros_button/push_button.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "ros_button");
    ros::NodeHandle n;
    ros::Publisher button_pub = n.advertise<ros_button::push_button>("button", 1000);

    ros::Rate loop_rate(10);
    while (ros::ok()) {
        ros_button::push_button button_pressed;
        button_pressed.pressed = true;
        std::cin.ignore();
        button_pub.publish(button_pressed);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}