#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "vehicle_dual";

// For Block vehicle_dual/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_vehicle_dual_geometry_msgs_Twist> Sub_vehicle_dual_2;

// For Block vehicle_dual/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_vehicle_dual_geometry_msgs_Twist> Pub_vehicle_dual_11;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

