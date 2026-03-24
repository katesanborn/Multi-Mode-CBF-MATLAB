#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "originalcbf_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block originalcbf/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_originalcbf_std_msgs_Float64> Sub_originalcbf_52;

// For Block originalcbf/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_originalcbf_std_msgs_Float64> Sub_originalcbf_53;

// For Block originalcbf/Subscribe4
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_originalcbf_std_msgs_Float64> Sub_originalcbf_54;

// For Block originalcbf/Subscribe6
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_originalcbf_std_msgs_Float64> Sub_originalcbf_55;

// For Block originalcbf/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_originalcbf_std_msgs_Float64> Pub_originalcbf_49;

// For Block originalcbf/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_originalcbf_std_msgs_Float64> Pub_originalcbf_94;

void slros_node_init(int argc, char** argv);

#endif
