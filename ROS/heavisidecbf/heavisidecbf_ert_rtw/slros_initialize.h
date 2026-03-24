#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "heavisidecbf_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block heavisidecbf/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_heavisidecbf_std_msgs_Float64> Sub_heavisidecbf_52;

// For Block heavisidecbf/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_heavisidecbf_std_msgs_Float64> Sub_heavisidecbf_53;

// For Block heavisidecbf/Subscribe4
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_heavisidecbf_std_msgs_Float64> Sub_heavisidecbf_54;

// For Block heavisidecbf/Subscribe6
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_heavisidecbf_std_msgs_Float64> Sub_heavisidecbf_55;

// For Block heavisidecbf/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_heavisidecbf_std_msgs_Float64> Pub_heavisidecbf_49;

// For Block heavisidecbf/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_heavisidecbf_std_msgs_Float64> Pub_heavisidecbf_94;

void slros_node_init(int argc, char** argv);

#endif
