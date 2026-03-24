#ifndef ORIGINALCBF__VISIBILITY_CONTROL_H_
#define ORIGINALCBF__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ORIGINALCBF_EXPORT __attribute__ ((dllexport))
    #define ORIGINALCBF_IMPORT __attribute__ ((dllimport))
  #else
    #define ORIGINALCBF_EXPORT __declspec(dllexport)
    #define ORIGINALCBF_IMPORT __declspec(dllimport)
  #endif
  #ifdef ORIGINALCBF_BUILDING_LIBRARY
    #define ORIGINALCBF_PUBLIC ORIGINALCBF_EXPORT
  #else
    #define ORIGINALCBF_PUBLIC ORIGINALCBF_IMPORT
  #endif
  #define ORIGINALCBF_PUBLIC_TYPE ORIGINALCBF_PUBLIC
  #define ORIGINALCBF_LOCAL
#else
  #define ORIGINALCBF_EXPORT __attribute__ ((visibility("default")))
  #define ORIGINALCBF_IMPORT
  #if __GNUC__ >= 4
    #define ORIGINALCBF_PUBLIC __attribute__ ((visibility("default")))
    #define ORIGINALCBF_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ORIGINALCBF_PUBLIC
    #define ORIGINALCBF_LOCAL
  #endif
  #define ORIGINALCBF_PUBLIC_TYPE
#endif
#endif  // ORIGINALCBF__VISIBILITY_CONTROL_H_
// Generated 08-Jan-2026 11:18:31
// Copyright 2019-2020 The MathWorks, Inc.
