#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "cruisecontrol";

// For Block cruisecontrol/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_cruisecontrol_std_msgs_Float64> Sub_cruisecontrol_53;

// For Block cruisecontrol/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_cruisecontrol_std_msgs_Float64> Pub_cruisecontrol_49;

// For Block cruisecontrol/Get Parameter1
SimulinkParameterGetter<real64_T, double> ParamGet_cruisecontrol_96;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

