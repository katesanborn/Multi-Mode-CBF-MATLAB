#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "originalcbf";

// For Block originalcbf/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_originalcbf_std_msgs_Float64> Sub_originalcbf_52;

// For Block originalcbf/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_originalcbf_std_msgs_Float64> Sub_originalcbf_53;

// For Block originalcbf/Subscribe4
SimulinkSubscriber<std_msgs::Float64, SL_Bus_originalcbf_std_msgs_Float64> Sub_originalcbf_54;

// For Block originalcbf/Subscribe6
SimulinkSubscriber<std_msgs::Float64, SL_Bus_originalcbf_std_msgs_Float64> Sub_originalcbf_55;

// For Block originalcbf/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_originalcbf_std_msgs_Float64> Pub_originalcbf_49;

// For Block originalcbf/Publish2
SimulinkPublisher<std_msgs::Float64, SL_Bus_originalcbf_std_msgs_Float64> Pub_originalcbf_94;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

