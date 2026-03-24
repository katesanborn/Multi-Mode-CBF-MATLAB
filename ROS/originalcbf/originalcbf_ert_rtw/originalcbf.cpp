//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: originalcbf.cpp
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
#include "originalcbf.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtwtypes.h"
#include "originalcbf_types.h"

// Block signals (default storage)
B_originalcbf_T originalcbf_B;

// Block states (default storage)
DW_originalcbf_T originalcbf_DW;

// Real-time model
RT_MODEL_originalcbf_T originalcbf_M_ = RT_MODEL_originalcbf_T();
RT_MODEL_originalcbf_T *const originalcbf_M = &originalcbf_M_;

// Model step function
void originalcbf_step(void)
{
  SL_Bus_originalcbf_std_msgs_Float64 rtb_BusAssignment1;
  SL_Bus_originalcbf_std_msgs_Float64 rtb_SourceBlock_o2_p_0;
  real_T u0;
  real_T u1;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S5>/SourceBlock'
  b_varargout_1 = Sub_originalcbf_52.getLatestMessage(&rtb_SourceBlock_o2_p_0);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S10>/Enable'

  // Start for MATLABSystem: '<S5>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S10>/In1'
    originalcbf_B.In1_bg = rtb_SourceBlock_o2_p_0;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe4'
  // MATLABSystem: '<S7>/SourceBlock'
  b_varargout_1 = Sub_originalcbf_54.getLatestMessage(&rtb_SourceBlock_o2_p_0);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  // Start for MATLABSystem: '<S7>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S12>/In1'
    originalcbf_B.In1_e = rtb_SourceBlock_o2_p_0;
  }

  // End of Start for MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe4'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = Sub_originalcbf_53.getLatestMessage(&rtb_SourceBlock_o2_p_0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  // Start for MATLABSystem: '<S6>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S11>/In1'
    originalcbf_B.In1_b = rtb_SourceBlock_o2_p_0;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe6'
  // MATLABSystem: '<S8>/SourceBlock'
  b_varargout_1 = Sub_originalcbf_55.getLatestMessage(&rtb_SourceBlock_o2_p_0);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  // Start for MATLABSystem: '<S8>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S13>/In1'
    originalcbf_B.In1 = rtb_SourceBlock_o2_p_0;
  }

  // End of Start for MATLABSystem: '<S8>/SourceBlock'
  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe6'

  // MATLAB Function: '<S14>/MATLAB Function1' incorporates:
  //   Constant: '<S14>/k1'
  //   Constant: '<S14>/k2'
  //   Constant: '<S14>/k_timegap'
  //   Constant: '<S14>/s_min'
  //   Constant: '<S14>/timegap'

  u0 = ((originalcbf_B.In1_bg.Data - 2.0 * originalcbf_B.In1_b.Data) - 15.0) *
    0.05 + 0.5 * originalcbf_B.In1_e.Data;
  u1 = (originalcbf_B.In1_bg.Data - 15.0) * 0.25 + originalcbf_B.In1_e.Data;
  if ((u0 <= u1) || rtIsNaN(u1)) {
    u1 = u0;
  }

  // End of MATLAB Function: '<S14>/MATLAB Function1'

  // MinMax: '<Root>/MinMax'
  if ((!(u1 <= originalcbf_B.In1.Data)) && (!rtIsNaN(originalcbf_B.In1.Data))) {
    u1 = originalcbf_B.In1.Data;
  }

  // End of MinMax: '<Root>/MinMax'

  // Saturate: '<Root>/min//max 1.5//-3.0'
  if (u1 > 1.5) {
    // BusAssignment: '<Root>/Bus Assignment1'
    rtb_BusAssignment1.Data = 1.5;
  } else if (u1 < -3.0) {
    // BusAssignment: '<Root>/Bus Assignment1'
    rtb_BusAssignment1.Data = -3.0;
  } else {
    // BusAssignment: '<Root>/Bus Assignment1'
    rtb_BusAssignment1.Data = u1;
  }

  // End of Saturate: '<Root>/min//max 1.5//-3.0'

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_originalcbf_49.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'
}

// Model initialize function
void originalcbf_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic_1[16];
    char_T b_zeroDelimTopic_2[14];
    char_T b_zeroDelimTopic[10];
    char_T b_zeroDelimTopic_3[9];
    char_T b_zeroDelimTopic_0[8];
    static const char_T b_zeroDelimTopic_4[10] = "lead_dist";
    static const char_T b_zeroDelimTopic_5[10] = "cmd_accel";
    static const char_T b_zeroDelimTopic_6[8] = "rel_vel";
    static const char_T b_zeroDelimTopic_7[16] = "car/state/vel_x";
    static const char_T b_zeroDelimTopic_8[14] = "cmd_accel_pre";
    static const char_T b_zeroDelimTopic_9[9] = "cbf_mode";

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    originalcbf_DW.obj_e.matlabCodegenIsDeleted = false;
    originalcbf_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_4[i];
    }

    Sub_originalcbf_52.createSubscriber(&b_zeroDelimTopic[0], 1);
    originalcbf_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    originalcbf_DW.obj_a.matlabCodegenIsDeleted = false;
    originalcbf_DW.obj_a.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_5[i];
    }

    Pub_originalcbf_49.createPublisher(&b_zeroDelimTopic[0], 1);
    originalcbf_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe4'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    originalcbf_DW.obj_m.matlabCodegenIsDeleted = false;
    originalcbf_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_6[i];
    }

    Sub_originalcbf_54.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    originalcbf_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe4'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    originalcbf_DW.obj_p.matlabCodegenIsDeleted = false;
    originalcbf_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_7[i];
    }

    Sub_originalcbf_53.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    originalcbf_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe6'
    // Start for MATLABSystem: '<S8>/SourceBlock'
    originalcbf_DW.obj_n.matlabCodegenIsDeleted = false;
    originalcbf_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      b_zeroDelimTopic_2[i] = b_zeroDelimTopic_8[i];
    }

    Sub_originalcbf_55.createSubscriber(&b_zeroDelimTopic_2[0], 1);
    originalcbf_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe6'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    originalcbf_DW.obj.matlabCodegenIsDeleted = false;
    originalcbf_DW.obj.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_3[i] = b_zeroDelimTopic_9[i];
    }

    Pub_originalcbf_94.createPublisher(&b_zeroDelimTopic_3[0], 1);
    originalcbf_DW.obj.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // ConstCode for Atomic SubSystem: '<Root>/Publish2'
    // ConstCode for MATLABSystem: '<S4>/SinkBlock'
    Pub_originalcbf_94.publish(&originalcbf_ConstB.BusAssignment2);

    // End of ConstCode for SubSystem: '<Root>/Publish2'
  }
}

// Model terminate function
void originalcbf_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!originalcbf_DW.obj.matlabCodegenIsDeleted) {
    originalcbf_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!originalcbf_DW.obj_e.matlabCodegenIsDeleted) {
    originalcbf_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe4'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!originalcbf_DW.obj_m.matlabCodegenIsDeleted) {
    originalcbf_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe4'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!originalcbf_DW.obj_p.matlabCodegenIsDeleted) {
    originalcbf_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe6'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!originalcbf_DW.obj_n.matlabCodegenIsDeleted) {
    originalcbf_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe6'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!originalcbf_DW.obj_a.matlabCodegenIsDeleted) {
    originalcbf_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'
}

const char_T* RT_MODEL_originalcbf_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_originalcbf_T::setErrorStatus(const char_T* const volatile
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
