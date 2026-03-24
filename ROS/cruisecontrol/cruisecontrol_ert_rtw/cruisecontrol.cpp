//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: cruisecontrol.cpp
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
#include "cruisecontrol.h"
#include "rtwtypes.h"
#include "cruisecontrol_types.h"

// Block signals (default storage)
B_cruisecontrol_T cruisecontrol_B;

// Block states (default storage)
DW_cruisecontrol_T cruisecontrol_DW;

// Real-time model
RT_MODEL_cruisecontrol_T cruisecontrol_M_ = RT_MODEL_cruisecontrol_T();
RT_MODEL_cruisecontrol_T *const cruisecontrol_M = &cruisecontrol_M_;

// Model step function
void cruisecontrol_step(void)
{
  SL_Bus_cruisecontrol_std_msgs_Float64 rtb_BusAssignment1;
  SL_Bus_cruisecontrol_std_msgs_Float64 rtb_SourceBlock_o2_0;
  real_T b_value;
  boolean_T b_varargout_1;

  // MATLABSystem: '<Root>/Get Parameter1'
  ParamGet_cruisecontrol_96.get_parameter(&b_value);

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S3>/SourceBlock'
  b_varargout_1 = Sub_cruisecontrol_53.getLatestMessage(&rtb_SourceBlock_o2_0);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S5>/Enable'

  // Start for MATLABSystem: '<S3>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S5>/In1'
    cruisecontrol_B.In1 = rtb_SourceBlock_o2_0;
  }

  // End of Start for MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Gain: '<S4>/Gain'
  //   MATLABSystem: '<Root>/Get Parameter1'
  //   Sum: '<S4>/Subtract'
  //
  rtb_BusAssignment1.Data = (b_value - cruisecontrol_B.In1.Data) * 0.8;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_cruisecontrol_49.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'
}

// Model initialize function
void cruisecontrol_initialize(void)
{
  {
    int32_T i;
    char_T b_zeroDelimName[17];
    char_T b_zeroDelimTopic[16];
    char_T b_zeroDelimTopic_0[10];
    static const char_T b_zeroDelimTopic_1[16] = "car/state/vel_x";
    static const char_T b_zeroDelimTopic_2[10] = "cmd_accel";
    static const char_T b_zeroDelimName_0[17] = "desired_velocity";

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S3>/SourceBlock'
    cruisecontrol_DW.obj_p.matlabCodegenIsDeleted = false;
    cruisecontrol_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_1[i];
    }

    Sub_cruisecontrol_53.createSubscriber(&b_zeroDelimTopic[0], 1);
    cruisecontrol_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    cruisecontrol_DW.obj_a.matlabCodegenIsDeleted = false;
    cruisecontrol_DW.obj_a.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_2[i];
    }

    Pub_cruisecontrol_49.createPublisher(&b_zeroDelimTopic_0[0], 1);
    cruisecontrol_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // Start for MATLABSystem: '<Root>/Get Parameter1'
    cruisecontrol_DW.obj.matlabCodegenIsDeleted = false;
    cruisecontrol_DW.obj.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      b_zeroDelimName[i] = b_zeroDelimName_0[i];
    }

    ParamGet_cruisecontrol_96.initialize(&b_zeroDelimName[0]);
    ParamGet_cruisecontrol_96.initialize_error_codes(0, 1, 2, 3);
    ParamGet_cruisecontrol_96.set_initial_value(40.0);
    cruisecontrol_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter1'
  }
}

// Model terminate function
void cruisecontrol_terminate(void)
{
  // Terminate for MATLABSystem: '<Root>/Get Parameter1'
  if (!cruisecontrol_DW.obj.matlabCodegenIsDeleted) {
    cruisecontrol_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!cruisecontrol_DW.obj_p.matlabCodegenIsDeleted) {
    cruisecontrol_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  if (!cruisecontrol_DW.obj_a.matlabCodegenIsDeleted) {
    cruisecontrol_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'
}

const char_T* RT_MODEL_cruisecontrol_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_cruisecontrol_T::setErrorStatus(const char_T* const volatile
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
