#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block vehicle_dual/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_vehicle_dual_geometry_msgs_Twist> Sub_vehicle_dual_2;

// For Block vehicle_dual/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_vehicle_dual_geometry_msgs_Twist> Pub_vehicle_dual_11;

void slros_node_init(int argc, char** argv);

#endif
