#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "Publisher"); //INITFILE
    ros::NodeHandle nh; //OUT NODE HANDLE, start the node

    //advertiser that specifise the msg type (string) and name of topic (ros) and the buffert size (1000)
    ros::Publisher topic_pub = nh.advertise<std_msgs::String>("ros", 1000);
    ros::Rate loop_rate(1); //How often we will send a message (pbulishes every second (1))

    while(ros::ok()) {//works as long as the node is ok or we dont end the programe
        std_msgs::String msg; //our message
        msg.data = "Hello world"; //our data fo the msg object

        topic_pub.publish(msg); //Publishes data
        ros::spinOnce(); //checks for callbacks or other things we need to check
        loop_rate.sleep();
    }

    return 0;
}