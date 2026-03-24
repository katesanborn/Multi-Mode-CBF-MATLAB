#ifndef HEAVISIDECBF__VISIBILITY_CONTROL_H_
#define HEAVISIDECBF__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define HEAVISIDECBF_EXPORT __attribute__ ((dllexport))
    #define HEAVISIDECBF_IMPORT __attribute__ ((dllimport))
  #else
    #define HEAVISIDECBF_EXPORT __declspec(dllexport)
    #define HEAVISIDECBF_IMPORT __declspec(dllimport)
  #endif
  #ifdef HEAVISIDECBF_BUILDING_LIBRARY
    #define HEAVISIDECBF_PUBLIC HEAVISIDECBF_EXPORT
  #else
    #define HEAVISIDECBF_PUBLIC HEAVISIDECBF_IMPORT
  #endif
  #define HEAVISIDECBF_PUBLIC_TYPE HEAVISIDECBF_PUBLIC
  #define HEAVISIDECBF_LOCAL
#else
  #define HEAVISIDECBF_EXPORT __attribute__ ((visibility("default")))
  #define HEAVISIDECBF_IMPORT
  #if __GNUC__ >= 4
    #define HEAVISIDECBF_PUBLIC __attribute__ ((visibility("default")))
    #define HEAVISIDECBF_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define HEAVISIDECBF_PUBLIC
    #define HEAVISIDECBF_LOCAL
  #endif
  #define HEAVISIDECBF_PUBLIC_TYPE
#endif
#endif  // HEAVISIDECBF__VISIBILITY_CONTROL_H_
// Generated 07-Jan-2026 15:46:50
// Copyright 2019-2020 The MathWorks, Inc.
