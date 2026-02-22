#include "ros/ros.h"
//#include "std_msgs/String.h"
#include "ros/person_data.h"

//Function that is called from s
//the value that is called with is of type std_msgs and we take that value and point msg to it
void writeMsgToLog(const ros::person_data &person_data) {
    //functions like a print statement and this will print the message to the console
    ROS_INFO("Name: %s \n", person_data.name.c_str());
    ROS_INFO("Age: %i \n", person_data.age);
    ROS_INFO("Color: %s \n", person_data.color.c_str());

}


int main(int argc, char **argv) {
    ros::init(argc, argv, "Subscriber"); //INITFILE
    ros::NodeHandle nh; //OUT NODE HANDLE, start the node

    //Subscribes to the ros pkg and has a bugger of 1000 before throwing data away
    //the thrid value is the function that is called with the data
    ros::Subscriber s = nh.subscribe("ros", 1000, writeMsgToLog);

    //Spin up subcsriber
    ros::spin();

    return 0;
}