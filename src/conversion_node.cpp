/*
 * This node is the example of converting Quaternion to Euler Angle (ZYX order)
 *
 */

#include <tf/tf.h>
#include <geometry_msgs/PoseStamped.h>
#include <fstream>

void pose_cb(const geometry_msgs::PoseStamped::ConstPtr msg) {
    
    tf::Quaternion q(
        msg->pose.orientation.x,
        msg->pose.orientation.y,
        msg->pose.orientation.z,
        msg->pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);

    std::cout << "roll: " << roll << std::endl;
    std::cout << "pitch: " << pitch << std::endl;
    std::cout << "yaw: " << yaw << std::endl << std::endl;



}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "conversion_node");
    
    ros::NodeHandle nh;
    
    // the number 1 is tthe size of the queue (LIFO), meaning no buffer.
    ros::Subscriber sub_odom = nh.subscribe("pose", 1, pose_cb);
    
    ros::spin();
    
    return 0;
}