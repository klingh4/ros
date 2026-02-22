#include "ros/ros.h"
//#include "std_msgs/String.h" tog bort för att vi ska ha costum msgs
#include "ros/person_data.h"
int main(int argc, char **argv) {
    ros::init(argc, argv, "Publisher"); //INITFILE
    ros::NodeHandle nh; //OUT NODE HANDLE, start the node

    //advertiser that specifise the msg type (string) and name of topic (ros) and the buffert size (1000)
    ros::Publisher topic_pub = nh.advertise<ros::person_data>("ros", 1000);
    ros::Rate loop_rate(1); //How often we will send a message (pbulishes every second (1))

    while(ros::ok()) {//works as long as the node is ok or we dont end the programe
        ros::person_data person_data; //our message
        //our data fo the msg object

        person_data.name = "Samuel Henningsson Kling";
        person_data.age = 21;
        person_data.color = "Pink";

        topic_pub.publish(person_data); //Publishes data
        ros::spinOnce(); //checks for callbacks or other things we need to check
        loop_rate.sleep();
    }

    return 0;
}