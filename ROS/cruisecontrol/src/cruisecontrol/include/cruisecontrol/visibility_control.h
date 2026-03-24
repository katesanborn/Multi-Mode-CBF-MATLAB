#ifndef CRUISECONTROL__VISIBILITY_CONTROL_H_
#define CRUISECONTROL__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CRUISECONTROL_EXPORT __attribute__ ((dllexport))
    #define CRUISECONTROL_IMPORT __attribute__ ((dllimport))
  #else
    #define CRUISECONTROL_EXPORT __declspec(dllexport)
    #define CRUISECONTROL_IMPORT __declspec(dllimport)
  #endif
  #ifdef CRUISECONTROL_BUILDING_LIBRARY
    #define CRUISECONTROL_PUBLIC CRUISECONTROL_EXPORT
  #else
    #define CRUISECONTROL_PUBLIC CRUISECONTROL_IMPORT
  #endif
  #define CRUISECONTROL_PUBLIC_TYPE CRUISECONTROL_PUBLIC
  #define CRUISECONTROL_LOCAL
#else
  #define CRUISECONTROL_EXPORT __attribute__ ((visibility("default")))
  #define CRUISECONTROL_IMPORT
  #if __GNUC__ >= 4
    #define CRUISECONTROL_PUBLIC __attribute__ ((visibility("default")))
    #define CRUISECONTROL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CRUISECONTROL_PUBLIC
    #define CRUISECONTROL_LOCAL
  #endif
  #define CRUISECONTROL_PUBLIC_TYPE
#endif
#endif  // CRUISECONTROL__VISIBILITY_CONTROL_H_
// Generated 07-Jan-2026 15:46:00
// Copyright 2019-2020 The MathWorks, Inc.
