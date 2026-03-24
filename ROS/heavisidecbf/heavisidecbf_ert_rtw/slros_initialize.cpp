#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "heavisidecbf";

// For Block heavisidecbf/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_heavisidecbf_std_msgs_Float64> Sub_heavisidecbf_52;

// For Block heavisidecbf/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_heavisidecbf_std_msgs_Float64> Sub_heavisidecbf_53;

// For Block heavisidecbf/Subscribe4
SimulinkSubscriber<std_msgs::Float64, SL_Bus_heavisidecbf_std_msgs_Float64> Sub_heavisidecbf_54;

// For Block heavisidecbf/Subscribe6
SimulinkSubscriber<std_msgs::Float64, SL_Bus_heavisidecbf_std_msgs_Float64> Sub_heavisidecbf_55;

// For Block heavisidecbf/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_heavisidecbf_std_msgs_Float64> Pub_heavisidecbf_49;

// For Block heavisidecbf/Publish2
SimulinkPublisher<std_msgs::Float64, SL_Bus_heavisidecbf_std_msgs_Float64> Pub_heavisidecbf_94;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

