//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: cruisecontrol.h
//
// Code generated for Simulink model 'cruisecontrol'.
//
// Model version                  : 1.34
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Wed Jan  7 15:45:55 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef cruisecontrol_h_
#define cruisecontrol_h_
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "cruisecontrol_types.h"
#include <stddef.h>

// Block signals (default storage)
struct B_cruisecontrol_T {
  SL_Bus_cruisecontrol_std_msgs_Float64 In1;// '<S5>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_cruisecontrol_T {
  ros_slros_internal_block_GetP_T obj; // '<Root>/Get Parameter1'
  ros_slroscpp_internal_block_P_T obj_a;// '<S2>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_p;// '<S3>/SourceBlock'
};

// Real-time Model Data Structure
struct tag_RTM_cruisecontrol_T {
  const char_T * volatile errorStatus;
  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const volatile aErrorStatus);
};

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_cruisecontrol_T cruisecontrol_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_cruisecontrol_T cruisecontrol_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void cruisecontrol_initialize(void);
  extern void cruisecontrol_step(void);
  extern void cruisecontrol_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_cruisecontrol_T *const cruisecontrol_M;

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
//  '<Root>' : 'cruisecontrol'
//  '<S1>'   : 'cruisecontrol/Blank Message1'
//  '<S2>'   : 'cruisecontrol/Publish1'
//  '<S3>'   : 'cruisecontrol/Subscribe1'
//  '<S4>'   : 'cruisecontrol/Subsystem Reference'
//  '<S5>'   : 'cruisecontrol/Subscribe1/Enabled Subsystem'

#endif                                 // cruisecontrol_h_

//
// File trailer for generated code.
//
// [EOF]
//
