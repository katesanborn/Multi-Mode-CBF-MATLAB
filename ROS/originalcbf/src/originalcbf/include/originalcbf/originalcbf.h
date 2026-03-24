//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: originalcbf.h
//
// Code generated for Simulink model 'originalcbf'.
//
// Model version                  : 1.32
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Thu Jan  8 11:18:07 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef originalcbf_h_
#define originalcbf_h_
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "originalcbf_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stddef.h>

// Block signals (default storage)
struct B_originalcbf_T {
  SL_Bus_originalcbf_std_msgs_Float64 In1;// '<S13>/In1'
  SL_Bus_originalcbf_std_msgs_Float64 In1_e;// '<S12>/In1'
  SL_Bus_originalcbf_std_msgs_Float64 In1_b;// '<S11>/In1'
  SL_Bus_originalcbf_std_msgs_Float64 In1_bg;// '<S10>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_originalcbf_T {
  ros_slroscpp_internal_block_P_T obj; // '<S4>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_a;// '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S8>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_m;// '<S7>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_p;// '<S6>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_e;// '<S5>/SourceBlock'
};

// Invariant block signals (default storage)
struct ConstB_originalcbf_T {
  SL_Bus_originalcbf_std_msgs_Float64 BusAssignment2;// '<Root>/Bus Assignment2' 
};

// Real-time Model Data Structure
struct tag_RTM_originalcbf_T {
  const char_T * volatile errorStatus;
  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const volatile aErrorStatus);
};

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_originalcbf_T originalcbf_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_originalcbf_T originalcbf_DW;
extern const ConstB_originalcbf_T originalcbf_ConstB;// constant block i/o

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void originalcbf_initialize(void);
  extern void originalcbf_step(void);
  extern void originalcbf_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_originalcbf_T *const originalcbf_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'originalcbf'
//  '<S1>'   : 'originalcbf/Blank Message1'
//  '<S2>'   : 'originalcbf/Blank Message2'
//  '<S3>'   : 'originalcbf/Publish1'
//  '<S4>'   : 'originalcbf/Publish2'
//  '<S5>'   : 'originalcbf/Subscribe'
//  '<S6>'   : 'originalcbf/Subscribe1'
//  '<S7>'   : 'originalcbf/Subscribe4'
//  '<S8>'   : 'originalcbf/Subscribe6'
//  '<S9>'   : 'originalcbf/Subsystem Reference'
//  '<S10>'  : 'originalcbf/Subscribe/Enabled Subsystem'
//  '<S11>'  : 'originalcbf/Subscribe1/Enabled Subsystem'
//  '<S12>'  : 'originalcbf/Subscribe4/Enabled Subsystem'
//  '<S13>'  : 'originalcbf/Subscribe6/Enabled Subsystem'
//  '<S14>'  : 'originalcbf/Subsystem Reference/cbf_filter'
//  '<S15>'  : 'originalcbf/Subsystem Reference/cbf_filter/MATLAB Function1'

#endif                                 // originalcbf_h_

//
// File trailer for generated code.
//
// [EOF]
//
