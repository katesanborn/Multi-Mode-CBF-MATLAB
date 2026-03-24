#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "cruisecontrol_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block cruisecontrol/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_cruisecontrol_std_msgs_Float64> Sub_cruisecontrol_53;

// For Block cruisecontrol/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_cruisecontrol_std_msgs_Float64> Pub_cruisecontrol_49;

// For Block cruisecontrol/Get Parameter1
extern SimulinkParameterGetter<real64_T, double> ParamGet_cruisecontrol_96;

void slros_node_init(int argc, char** argv);

#endif
