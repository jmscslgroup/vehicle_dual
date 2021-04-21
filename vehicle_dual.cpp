//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: vehicle_dual.cpp
//
// Code generated for Simulink model 'vehicle_dual'.
//
// Model version                  : 1.8
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Wed Apr 21 01:23:58 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "vehicle_dual.h"
#include "vehicle_dual_private.h"

// Block signals (default storage)
B_vehicle_dual_T vehicle_dual_B;

// Continuous states
X_vehicle_dual_T vehicle_dual_X;

// Block states (default storage)
DW_vehicle_dual_T vehicle_dual_DW;

// Real-time model
RT_MODEL_vehicle_dual_T vehicle_dual_M_ = RT_MODEL_vehicle_dual_T();
RT_MODEL_vehicle_dual_T *const vehicle_dual_M = &vehicle_dual_M_;

// Forward declaration for local functions
static void vehicle_du_automlvehdynftiresat(real_T Ftire_y, real_T b_Fxtire_sat,
  real_T b_Fytire_sat, real_T *Ftire_xs, real_T *Ftire_ys);
static void matlabCodegenHandle_matlabCod_b(ros_slros_internal_block_Subs_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);
real_T look1_binlcpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Clip'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Clip'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0;
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  vehicle_dual_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  vehicle_dual_step();
  vehicle_dual_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  vehicle_dual_step();
  vehicle_dual_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Function for MATLAB Function: '<S4>/vehicle model'
static void vehicle_du_automlvehdynftiresat(real_T Ftire_y, real_T b_Fxtire_sat,
  real_T b_Fytire_sat, real_T *Ftire_xs, real_T *Ftire_ys)
{
  real_T theta_Ftire;
  real_T Ftire_y_max;
  real_T b_a;
  theta_Ftire = rt_atan2d_snf(0.0, Ftire_y);
  Ftire_y_max = cos(theta_Ftire);
  b_a = b_Fxtire_sat * Ftire_y_max;
  theta_Ftire = b_Fytire_sat * sin(theta_Ftire);
  Ftire_y_max *= b_Fxtire_sat * b_Fytire_sat / sqrt(b_a * b_a + theta_Ftire *
    theta_Ftire);
  *Ftire_xs = 0.0;
  *Ftire_ys = Ftire_y;
  if (fabs(Ftire_y) > fabs(Ftire_y_max)) {
    *Ftire_ys = Ftire_y_max;
  }
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T yEq;
  real_T q;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else {
      if ((u0 < 0.0) != (u1 < 0.0)) {
        y += u1;
      }
    }
  }

  return y;
}

static void matlabCodegenHandle_matlabCod_b(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void vehicle_dual_step(void)
{
  boolean_T b_varargout_1;
  int32_T i;
  int32_T i_0;
  real_T rtb_Product_idx_0;
  real_T c_a_tmp;
  if (rtmIsMajorTimeStep(vehicle_dual_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&vehicle_dual_M->solverInfo,
                          ((vehicle_dual_M->Timing.clockTick0+1)*
      vehicle_dual_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(vehicle_dual_M)) {
    vehicle_dual_M->Timing.t[0] = rtsiGetT(&vehicle_dual_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(vehicle_dual_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S3>/SourceBlock' incorporates:
    //   Inport: '<S5>/In1'

    b_varargout_1 = Sub_vehicle_dual_2.getLatestMessage
      (&vehicle_dual_B.BusAssignment);

    // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S5>/Enable'

    if (b_varargout_1) {
      vehicle_dual_B.In1 = vehicle_dual_B.BusAssignment;
    }

    // End of MATLABSystem: '<S3>/SourceBlock'
    // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // UnitConversion: '<S79>/Unit Conversion6'
    // Unit Conversion - from: m/s to: m/s
    // Expression: output = (1*input) + (0)
    vehicle_dual_B.UnitConversion6 = vehicle_dual_B.In1.Linear.X;

    // SignalConversion generated from: '<S79>/Vector Concatenate'
    vehicle_dual_B.VectorConcatenate[0] = vehicle_dual_B.UnitConversion6;

    // SignalConversion generated from: '<S79>/Vector Concatenate' incorporates:
    //   Constant: '<S4>/psi_oConstant'
    //   Constant: '<S4>/r_oConstant'
    //   Constant: '<S4>/ydot_oConstant'

    vehicle_dual_B.VectorConcatenate[1] =
      vehicle_dual_P.VehicleBody3DOFDualTrack_ydot_o;
    vehicle_dual_B.VectorConcatenate[2] =
      vehicle_dual_P.VehicleBody3DOFDualTrack_psi_o;
    vehicle_dual_B.VectorConcatenate[3] =
      vehicle_dual_P.VehicleBody3DOFDualTrack_r_o;
  }

  // Integrator: '<S79>/Integrator'
  if (vehicle_dual_DW.Integrator_IWORK != 0) {
    vehicle_dual_X.Integrator_CSTATE[0] = vehicle_dual_B.VectorConcatenate[0];
    vehicle_dual_X.Integrator_CSTATE[1] = vehicle_dual_B.VectorConcatenate[1];
    vehicle_dual_X.Integrator_CSTATE[2] = vehicle_dual_B.VectorConcatenate[2];
    vehicle_dual_X.Integrator_CSTATE[3] = vehicle_dual_B.VectorConcatenate[3];
  }

  // SignalConversion generated from: '<S79>/Vector Concatenate1' incorporates:
  //   Integrator: '<S79>/Integrator'

  vehicle_dual_B.rtb_VectorConcatenate1_idx_3 =
    vehicle_dual_X.Integrator_CSTATE[3];

  // SignalConversion generated from: '<S7>/Vector Concatenate1' incorporates:
  //   SignalConversion generated from: '<S79>/Vector Concatenate1'

  vehicle_dual_B.VectorConcatenate1[0] = vehicle_dual_B.UnitConversion6;

  // SignalConversion generated from: '<S7>/Vector Concatenate1' incorporates:
  //   Integrator: '<S79>/Integrator'

  vehicle_dual_B.VectorConcatenate1[1] = vehicle_dual_X.Integrator_CSTATE[1];
  if (rtmIsMajorTimeStep(vehicle_dual_M)) {
    // Constant: '<S7>/Constant'
    vehicle_dual_B.VectorConcatenate1[2] = vehicle_dual_P.Constant_Value_f;

    // SignalConversion generated from: '<S80>/Vector Concatenate1'
    vehicle_dual_B.VectorConcatenate1_o[0] = 0.0;

    // SignalConversion generated from: '<S80>/Vector Concatenate1'
    vehicle_dual_B.VectorConcatenate1_o[1] = 0.0;

    // SignalConversion generated from: '<S80>/Vector Concatenate1'
    vehicle_dual_B.VectorConcatenate1_o[2] = 0.0;

    // Constant: '<S19>/Constant'
    vehicle_dual_B.VectorConcatenate_c[0] =
      vehicle_dual_P.VehicleBody3DOFDualTrack_Cd;
  }

  // Trigonometry: '<S20>/Trigonometric Function' incorporates:
  //   Integrator: '<S79>/Integrator'
  //   MATLAB Function: '<S26>/COMB2I'

  vehicle_dual_B.rtb_Product_o_tmp = sin(vehicle_dual_X.Integrator_CSTATE[2]);
  vehicle_dual_B.rtb_Product2_g_tmp = cos(vehicle_dual_X.Integrator_CSTATE[2]);

  // Sum: '<S19>/Add1' incorporates:
  //   Product: '<S20>/Product1'
  //   Product: '<S20>/Product3'
  //   Sum: '<S20>/Add'
  //   Trigonometry: '<S20>/Trigonometric Function'

  vehicle_dual_B.rtb_VectorConcatenate2_j_m = vehicle_dual_B.VectorConcatenate1
    [0] - (vehicle_dual_B.rtb_Product2_g_tmp *
           vehicle_dual_B.VectorConcatenate1_o[0] +
           vehicle_dual_B.rtb_Product_o_tmp *
           vehicle_dual_B.VectorConcatenate1_o[1]);

  // Product: '<S19>/Product'
  rtb_Product_idx_0 = vehicle_dual_B.rtb_VectorConcatenate2_j_m *
    vehicle_dual_B.rtb_VectorConcatenate2_j_m;

  // Sum: '<S19>/Add1' incorporates:
  //   Product: '<S20>/Product'
  //   Product: '<S20>/Product2'
  //   Sum: '<S20>/Add1'
  //   Trigonometry: '<S20>/Trigonometric Function'

  vehicle_dual_B.rtb_VectorConcatenate2_j_idx_0 =
    vehicle_dual_B.rtb_VectorConcatenate2_j_m;
  vehicle_dual_B.rtb_VectorConcatenate2_j_m = vehicle_dual_B.VectorConcatenate1
    [1] - (vehicle_dual_B.rtb_Product2_g_tmp *
           vehicle_dual_B.VectorConcatenate1_o[1] -
           vehicle_dual_B.rtb_Product_o_tmp *
           vehicle_dual_B.VectorConcatenate1_o[0]);

  // Product: '<S19>/Product'
  vehicle_dual_B.rtb_Product_idx_1 = vehicle_dual_B.rtb_VectorConcatenate2_j_m *
    vehicle_dual_B.rtb_VectorConcatenate2_j_m;

  // Sum: '<S19>/Add1' incorporates:
  //   SignalConversion generated from: '<S20>/Vector Concatenate2'

  vehicle_dual_B.rtb_VectorConcatenate2_j_idx_1 =
    vehicle_dual_B.rtb_VectorConcatenate2_j_m;
  vehicle_dual_B.rtb_VectorConcatenate2_j_m = vehicle_dual_B.VectorConcatenate1
    [2] - vehicle_dual_B.VectorConcatenate1_o[2];

  // Sqrt: '<S19>/Sqrt' incorporates:
  //   Product: '<S19>/Product'
  //   Sum: '<S19>/Sum of Elements'

  vehicle_dual_B.rtb_Product_idx_1 = sqrt((rtb_Product_idx_0 +
    vehicle_dual_B.rtb_Product_idx_1) +
    vehicle_dual_B.rtb_VectorConcatenate2_j_m *
    vehicle_dual_B.rtb_VectorConcatenate2_j_m);

  // Product: '<S19>/Product2'
  rtb_Product_idx_0 = vehicle_dual_B.rtb_Product_idx_1 *
    vehicle_dual_B.rtb_Product_idx_1;

  // Trigonometry: '<S19>/Trigonometric Function'
  vehicle_dual_B.rtb_Product_idx_1 = rt_atan2d_snf
    (vehicle_dual_B.rtb_VectorConcatenate2_j_idx_1,
     vehicle_dual_B.rtb_VectorConcatenate2_j_idx_0);

  // Lookup_n-D: '<S19>/Cs'
  vehicle_dual_B.VectorConcatenate_c[1] = look1_binlcpw
    (vehicle_dual_B.rtb_Product_idx_1,
     vehicle_dual_P.VehicleBody3DOFDualTrack_beta_w,
     vehicle_dual_P.VehicleBody3DOFDualTrack_Cs, 30U);
  if (rtmIsMajorTimeStep(vehicle_dual_M)) {
    // Constant: '<S19>/Constant1'
    vehicle_dual_B.VectorConcatenate_c[2] =
      vehicle_dual_P.VehicleBody3DOFDualTrack_Cl;

    // UnaryMinus: '<S19>/Unary Minus' incorporates:
    //   Constant: '<S19>/Constant4'

    vehicle_dual_B.UnaryMinus[0] = -vehicle_dual_P.Constant4_Value[0];
    vehicle_dual_B.UnaryMinus[1] = -vehicle_dual_P.Constant4_Value[1];
    vehicle_dual_B.UnaryMinus[2] = -vehicle_dual_P.Constant4_Value[2];
  }

  // Lookup_n-D: '<S19>/Crm'
  vehicle_dual_B.VectorConcatenate_c[3] = look1_binlxpw
    (vehicle_dual_B.rtb_Product_idx_1, vehicle_dual_P.Crm_bp01Data,
     vehicle_dual_P.Crm_tableData, 1U);

  // Switch: '<S19>/Switch' incorporates:
  //   Constant: '<S19>/Constant4'

  if (vehicle_dual_B.rtb_VectorConcatenate2_j_idx_0 >=
      vehicle_dual_P.Switch_Threshold) {
    vehicle_dual_B.rtb_VectorConcatenate2_j_idx_0 =
      vehicle_dual_P.Constant4_Value[0];
  } else {
    vehicle_dual_B.rtb_VectorConcatenate2_j_idx_0 = vehicle_dual_B.UnaryMinus[0];
  }

  if (vehicle_dual_B.rtb_VectorConcatenate2_j_idx_1 >=
      vehicle_dual_P.Switch_Threshold) {
    vehicle_dual_B.rtb_VectorConcatenate2_j_idx_1 =
      vehicle_dual_P.Constant4_Value[1];
  } else {
    vehicle_dual_B.rtb_VectorConcatenate2_j_idx_1 = vehicle_dual_B.UnaryMinus[1];
  }

  // Product: '<S19>/Product5' incorporates:
  //   Constant: '<S19>/Constant2'

  vehicle_dual_B.VectorConcatenate_c[4] =
    vehicle_dual_B.rtb_VectorConcatenate2_j_idx_0 *
    vehicle_dual_P.VehicleBody3DOFDualTrack_Cpm;

  // Lookup_n-D: '<S19>/Cym'
  vehicle_dual_B.VectorConcatenate_c[5] = look1_binlxpw
    (vehicle_dual_B.rtb_Product_idx_1,
     vehicle_dual_P.VehicleBody3DOFDualTrack_beta_w,
     vehicle_dual_P.VehicleBody3DOFDualTrack_Cym, 30U);

  // Gain: '<S19>/.5.*A.*Pabs.//R.//T' incorporates:
  //   Constant: '<S4>/AirTempConstant'
  //   Product: '<S19>/Product1'

  vehicle_dual_B.d = 0.5 * vehicle_dual_P.VehicleBody3DOFDualTrack_Af *
    vehicle_dual_P.VehicleBody3DOFDualTrack_Pabs / vehicle_dual_P.DragForce_R;
  for (i = 0; i < 6; i++) {
    vehicle_dual_B.uAPabsRT[i] = rtb_Product_idx_0 *
      vehicle_dual_B.VectorConcatenate_c[i] /
      vehicle_dual_P.VehicleBody3DOFDualTrack_Tair * vehicle_dual_B.d;
  }

  // End of Gain: '<S19>/.5.*A.*Pabs.//R.//T'

  // Product: '<S19>/Product4' incorporates:
  //   Constant: '<S19>/Constant3'
  //   MATLAB Function: '<S4>/vehicle model'

  vehicle_dual_B.d = vehicle_dual_P.VehicleBody3DOFDualTrack_a +
    vehicle_dual_P.VehicleBody3DOFDualTrack_b;

  // Product: '<S19>/Product3' incorporates:
  //   UnaryMinus: '<S7>/Unary Minus'

  vehicle_dual_B.rtb_VectorConcatenate2_j_idx_0 =
    -(vehicle_dual_B.rtb_VectorConcatenate2_j_idx_0 * vehicle_dual_B.uAPabsRT[0]);

  // Sum: '<S4>/Add' incorporates:
  //   Constant: '<S19>/Constant3'
  //   Product: '<S19>/Product4'
  //   UnaryMinus: '<S7>/Unary Minus1'

  vehicle_dual_B.rtb_Product_idx_1 = -(vehicle_dual_B.uAPabsRT[4] *
    vehicle_dual_B.d);

  // Product: '<S19>/Product3' incorporates:
  //   UnaryMinus: '<S7>/Unary Minus'

  vehicle_dual_B.rtb_VectorConcatenate2_j_idx_1 =
    -(vehicle_dual_B.rtb_VectorConcatenate2_j_idx_1 * vehicle_dual_B.uAPabsRT[1]);

  // Sum: '<S4>/Add' incorporates:
  //   Constant: '<S19>/Constant3'
  //   Product: '<S19>/Product4'
  //   UnaryMinus: '<S7>/Unary Minus1'

  vehicle_dual_B.rtb_Product_idx_2 = -(vehicle_dual_B.uAPabsRT[5] *
    vehicle_dual_B.d);

  // Switch: '<S19>/Switch' incorporates:
  //   Constant: '<S19>/Constant4'

  if (vehicle_dual_B.rtb_VectorConcatenate2_j_m >=
      vehicle_dual_P.Switch_Threshold) {
    vehicle_dual_B.rtb_VectorConcatenate2_j_m = vehicle_dual_P.Constant4_Value[2];
  } else {
    vehicle_dual_B.rtb_VectorConcatenate2_j_m = vehicle_dual_B.UnaryMinus[2];
  }

  // UnaryMinus: '<S7>/Unary Minus' incorporates:
  //   Product: '<S19>/Product3'

  vehicle_dual_B.rtb_VectorConcatenate2_j_m =
    -(vehicle_dual_B.rtb_VectorConcatenate2_j_m * vehicle_dual_B.uAPabsRT[2]);
  if (rtmIsMajorTimeStep(vehicle_dual_M)) {
    // UnitConversion: '<S73>/Unit Conversion1'
    // Unit Conversion - from: rad to: rad
    // Expression: output = (1*input) + (0)
    vehicle_dual_B.UnitConversion1 = vehicle_dual_B.In1.Angular.Z;

    // SignalConversion generated from: '<S71>/Vector Concatenate1' incorporates:
    //   Constant: '<S71>/Constant'

    vehicle_dual_B.VectorConcatenate1_d[0] =
      vehicle_dual_P.VehicleBody3DOFDualTrack_mu;

    // SignalConversion generated from: '<S71>/Vector Concatenate1' incorporates:
    //   Constant: '<S71>/Constant'

    vehicle_dual_B.VectorConcatenate1_d[1] =
      vehicle_dual_P.VehicleBody3DOFDualTrack_mu;
  }

  // MATLAB Function: '<S4>/vehicle model' incorporates:
  //   Constant: '<S18>/Cyf'
  //   Constant: '<S18>/Cyr'
  //   Integrator: '<S79>/Integrator'
  //   SignalConversion generated from: '<S79>/Vector Concatenate1'

  c_a_tmp = vehicle_dual_P.VehicleBody3DOFDualTrack_a *
    vehicle_dual_X.Integrator_CSTATE[3] + vehicle_dual_X.Integrator_CSTATE[1];
  rtb_Product_idx_0 = vehicle_dual_X.Integrator_CSTATE[1] -
    vehicle_dual_P.VehicleBody3DOFDualTrack_b *
    vehicle_dual_X.Integrator_CSTATE[3];
  vehicle_dual_B.alfa_r = fabs(vehicle_dual_B.UnitConversion6);
  i = 0;
  if (vehicle_dual_B.alfa_r < vehicle_dual_P.VehicleBody3DOFDualTrack_xdot_t) {
    i = 1;
  }

  if (0 <= i - 1) {
    vehicle_dual_B.z_data = vehicle_dual_B.alfa_r /
      vehicle_dual_P.VehicleBody3DOFDualTrack_xdot_t;
    vehicle_dual_B.z1_data = vehicle_dual_B.z_data;
  }

  if (0 <= i - 1) {
    vehicle_dual_B.z1_data = vehicle_dual_B.z_data * vehicle_dual_B.z_data;
  }

  i--;
  for (i_0 = 0; i_0 <= i; i_0++) {
    vehicle_dual_B.z1_data = 2.0 *
      vehicle_dual_P.VehicleBody3DOFDualTrack_xdot_t / (3.0 -
      vehicle_dual_B.z1_data);
  }

  if (vehicle_dual_B.alfa_r < vehicle_dual_P.VehicleBody3DOFDualTrack_xdot_t) {
    vehicle_dual_B.alfa_r = vehicle_dual_B.z1_data;
  }

  vehicle_dual_B.alfa_f_tmp = tanh(4.0 * vehicle_dual_B.UnitConversion6);
  vehicle_dual_B.alfa_f = rt_atan2d_snf(c_a_tmp, vehicle_dual_B.alfa_r) -
    vehicle_dual_B.UnitConversion1 * vehicle_dual_B.alfa_f_tmp;
  vehicle_dual_B.alfa_r = rt_atan2d_snf(rtb_Product_idx_0, vehicle_dual_B.alfa_r)
    - 0.0 * vehicle_dual_B.alfa_f_tmp;
  vehicle_dual_B.Fz_idx_0 = 0.0;
  vehicle_dual_B.Fz_idx_1 = 0.0;
  vehicle_dual_B.alfa_f_tmp = sin(vehicle_dual_B.UnitConversion1);
  vehicle_dual_B.Fy_f_tmp = cos(vehicle_dual_B.UnitConversion1);
  for (i = 0; i < 6; i++) {
    if (i == 0) {
      vehicle_dual_B.Fz_idx_1 = vehicle_dual_B.rtb_VectorConcatenate2_j_idx_0 *
        vehicle_dual_P.VehicleBody3DOFDualTrack_h;
      vehicle_dual_B.Fz_idx_0 = (((vehicle_dual_P.VehicleBody3DOFDualTrack_g *
        vehicle_dual_P.VehicleBody3DOFDualTrack_b *
        vehicle_dual_P.VehicleBody3DOFDualTrack_m +
        vehicle_dual_B.rtb_VectorConcatenate2_j_m *
        vehicle_dual_P.VehicleBody3DOFDualTrack_b) + vehicle_dual_B.Fz_idx_1) -
        vehicle_dual_B.rtb_Product_idx_1) / vehicle_dual_B.d;
      vehicle_dual_B.Fz_idx_1 = (((vehicle_dual_P.VehicleBody3DOFDualTrack_g *
        vehicle_dual_P.VehicleBody3DOFDualTrack_a *
        vehicle_dual_P.VehicleBody3DOFDualTrack_m +
        vehicle_dual_B.rtb_VectorConcatenate2_j_m *
        vehicle_dual_P.VehicleBody3DOFDualTrack_a) - vehicle_dual_B.Fz_idx_1) +
        vehicle_dual_B.rtb_Product_idx_1) / vehicle_dual_B.d;
      if (vehicle_dual_B.Fz_idx_0 < 0.0) {
        vehicle_dual_B.Fz_idx_0 = 0.0;
      }

      if (vehicle_dual_B.Fz_idx_1 < 0.0) {
        vehicle_dual_B.Fz_idx_1 = 0.0;
      }
    }

    vehicle_dual_B.Fy_f = -vehicle_dual_P.VehicleBody3DOFDualTrack_Cy_f *
      vehicle_dual_B.alfa_f * vehicle_dual_B.VectorConcatenate1_d[0] *
      vehicle_dual_B.Fz_idx_0 / vehicle_dual_P.VehicleBody3DOFDualTrack_Fznom;
    vehicle_dual_B.Fy_r = -vehicle_dual_P.VehicleBody3DOFDualTrack_Cy_r *
      vehicle_dual_B.alfa_r * vehicle_dual_B.VectorConcatenate1_d[1] *
      vehicle_dual_B.Fz_idx_1 / vehicle_dual_P.VehicleBody3DOFDualTrack_Fznom;
    vehicle_du_automlvehdynftiresat(vehicle_dual_B.Fy_f,
      vehicle_dual_P.vehiclemodel_Fxtire_sat * vehicle_dual_B.Fz_idx_0 /
      vehicle_dual_P.VehicleBody3DOFDualTrack_Fznom,
      vehicle_dual_P.vehiclemodel_Fytire_sat * vehicle_dual_B.Fz_idx_0 /
      vehicle_dual_P.VehicleBody3DOFDualTrack_Fznom, &vehicle_dual_B.Fx_ft,
      &vehicle_dual_B.yddot);
    vehicle_du_automlvehdynftiresat(vehicle_dual_B.Fy_r,
      vehicle_dual_P.vehiclemodel_Fxtire_sat * vehicle_dual_B.Fz_idx_1 /
      vehicle_dual_P.VehicleBody3DOFDualTrack_Fznom,
      vehicle_dual_P.vehiclemodel_Fytire_sat * vehicle_dual_B.Fz_idx_1 /
      vehicle_dual_P.VehicleBody3DOFDualTrack_Fznom, &vehicle_dual_B.Fz_idx_0,
      &vehicle_dual_B.Fx_ft);
    vehicle_dual_B.Fy_f = -(0.0 * vehicle_dual_B.Fy_f_tmp - vehicle_dual_B.yddot
      * vehicle_dual_B.alfa_f_tmp) * vehicle_dual_B.alfa_f_tmp +
      vehicle_dual_B.Fy_f * vehicle_dual_B.Fy_f_tmp;
    vehicle_dual_B.Fy_r += -(0.0 - vehicle_dual_B.Fx_ft * 0.0) * 0.0;
    vehicle_dual_B.yddot = ((vehicle_dual_B.Fy_f + vehicle_dual_B.Fy_r) +
      vehicle_dual_B.rtb_VectorConcatenate2_j_idx_1) /
      vehicle_dual_P.VehicleBody3DOFDualTrack_m +
      -vehicle_dual_B.UnitConversion6 *
      vehicle_dual_B.rtb_VectorConcatenate1_idx_3;
    vehicle_dual_B.Fy_f = ((vehicle_dual_P.VehicleBody3DOFDualTrack_a *
      vehicle_dual_B.Fy_f - vehicle_dual_P.VehicleBody3DOFDualTrack_b *
      vehicle_dual_B.Fy_r) + vehicle_dual_B.rtb_Product_idx_2) /
      vehicle_dual_P.VehicleBody3DOFDualTrack_Izz;
    vehicle_dual_B.Fz_idx_1 = (0.0 - vehicle_dual_X.Integrator_CSTATE[1] *
      vehicle_dual_B.rtb_VectorConcatenate1_idx_3) *
      vehicle_dual_P.VehicleBody3DOFDualTrack_h;
    vehicle_dual_B.Fy_r = vehicle_dual_B.rtb_VectorConcatenate2_j_idx_0 *
      vehicle_dual_P.VehicleBody3DOFDualTrack_h;
    vehicle_dual_B.Fz_idx_0 = ((((vehicle_dual_P.VehicleBody3DOFDualTrack_g *
      vehicle_dual_P.VehicleBody3DOFDualTrack_b - vehicle_dual_B.Fz_idx_1) *
      vehicle_dual_P.VehicleBody3DOFDualTrack_m +
      vehicle_dual_B.rtb_VectorConcatenate2_j_m *
      vehicle_dual_P.VehicleBody3DOFDualTrack_b) + vehicle_dual_B.Fy_r) -
      vehicle_dual_B.rtb_Product_idx_1) / vehicle_dual_B.d;
    vehicle_dual_B.Fz_idx_1 = ((((vehicle_dual_B.Fz_idx_1 +
      vehicle_dual_P.VehicleBody3DOFDualTrack_g *
      vehicle_dual_P.VehicleBody3DOFDualTrack_a) *
      vehicle_dual_P.VehicleBody3DOFDualTrack_m +
      vehicle_dual_B.rtb_VectorConcatenate2_j_m *
      vehicle_dual_P.VehicleBody3DOFDualTrack_a) - vehicle_dual_B.Fy_r) +
      vehicle_dual_B.rtb_Product_idx_1) / vehicle_dual_B.d;
    if (vehicle_dual_B.Fz_idx_0 < 0.0) {
      vehicle_dual_B.Fz_idx_0 = 0.0;
    }

    if (vehicle_dual_B.Fz_idx_1 < 0.0) {
      vehicle_dual_B.Fz_idx_1 = 0.0;
    }
  }

  vehicle_dual_B.stateDer[0] = 0.0;
  vehicle_dual_B.stateDer[1] = vehicle_dual_B.yddot;
  vehicle_dual_B.stateDer[2] = vehicle_dual_X.Integrator_CSTATE[3];
  vehicle_dual_B.stateDer[3] = vehicle_dual_B.Fy_f;

  // MATLAB Function: '<S26>/COMB2I' incorporates:
  //   Integrator: '<S79>/Integrator'
  //   SignalConversion generated from: '<S79>/Vector Concatenate1'

  vehicle_dual_B.y[0] = vehicle_dual_B.UnitConversion6 *
    vehicle_dual_B.rtb_Product2_g_tmp - vehicle_dual_X.Integrator_CSTATE[1] *
    vehicle_dual_B.rtb_Product_o_tmp;
  vehicle_dual_B.y[1] = vehicle_dual_B.UnitConversion6 *
    vehicle_dual_B.rtb_Product_o_tmp + vehicle_dual_X.Integrator_CSTATE[1] *
    vehicle_dual_B.rtb_Product2_g_tmp;

  // MATLAB Function: '<S4>/vehicle model' incorporates:
  //   SignalConversion generated from: '<S79>/Vector Concatenate1'

  vehicle_dual_B.rtb_VectorConcatenate1_idx_3 = vehicle_dual_B.UnitConversion6 *
    vehicle_dual_B.UnitConversion6;

  // Product: '<S77>/Product1' incorporates:
  //   Constant: '<S76>/Constant1'
  //   Integrator: '<S77>/lateral'
  //   MATLAB Function: '<S4>/vehicle model'
  //   Sum: '<S77>/Sum'

  vehicle_dual_B.Product1 = sqrt(c_a_tmp * c_a_tmp +
    vehicle_dual_B.rtb_VectorConcatenate1_idx_3) * (vehicle_dual_B.alfa_f -
    vehicle_dual_X.lateral_CSTATE) /
    vehicle_dual_P.VehicleBody3DOFDualTrack_sigma_;

  // Product: '<S78>/Product1' incorporates:
  //   Constant: '<S76>/Constant2'
  //   Integrator: '<S78>/lateral'
  //   MATLAB Function: '<S4>/vehicle model'
  //   Sum: '<S78>/Sum'

  vehicle_dual_B.Product1_p = sqrt(rtb_Product_idx_0 * rtb_Product_idx_0 +
    vehicle_dual_B.rtb_VectorConcatenate1_idx_3) * (vehicle_dual_B.alfa_r -
    vehicle_dual_X.lateral_CSTATE_h) /
    vehicle_dual_P.VehicleBody3DOFDualTrack_sigm_e;

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<S1>/Constant'
  //   Integrator: '<S79>/Integrator'
  //   Math: '<Root>/Mod'
  //   SignalConversion generated from: '<S79>/Vector Concatenate1'

  vehicle_dual_B.BusAssignment = vehicle_dual_P.Constant_Value_n;
  vehicle_dual_B.BusAssignment.Linear.X = vehicle_dual_B.UnitConversion6;
  vehicle_dual_B.BusAssignment.Linear.Y = vehicle_dual_X.Integrator_CSTATE[1];
  vehicle_dual_B.BusAssignment.Angular.Z = rt_modd_snf
    (vehicle_dual_X.Integrator_CSTATE[2], vehicle_dual_P.Constant2_Value_l);

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_vehicle_dual_11.publish(&vehicle_dual_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(vehicle_dual_M)) {
    // Constant: '<S4>/X_oConstant'
    vehicle_dual_B.VectorConcatenate3[0] =
      vehicle_dual_P.VehicleBody3DOFDualTrack_X_o;

    // Constant: '<S4>/Y_oConstant'
    vehicle_dual_B.VectorConcatenate3[1] =
      vehicle_dual_P.VehicleBody3DOFDualTrack_Y_o;
  }

  // Integrator: '<S26>/Integrator'
  if (vehicle_dual_DW.Integrator_IWORK_b != 0) {
    vehicle_dual_X.Integrator_CSTATE_h[0] = vehicle_dual_B.VectorConcatenate3[0];
    vehicle_dual_X.Integrator_CSTATE_h[1] = vehicle_dual_B.VectorConcatenate3[1];
  }

  // End of Integrator: '<S26>/Integrator'
  if (rtmIsMajorTimeStep(vehicle_dual_M)) {
    // Update for Integrator: '<S79>/Integrator'
    vehicle_dual_DW.Integrator_IWORK = 0;

    // Update for Integrator: '<S26>/Integrator'
    vehicle_dual_DW.Integrator_IWORK_b = 0;
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(vehicle_dual_M)) {
    rt_ertODEUpdateContinuousStates(&vehicle_dual_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++vehicle_dual_M->Timing.clockTick0;
    vehicle_dual_M->Timing.t[0] = rtsiGetSolverStopTime
      (&vehicle_dual_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      vehicle_dual_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void vehicle_dual_derivatives(void)
{
  XDot_vehicle_dual_T *_rtXdot;
  _rtXdot = ((XDot_vehicle_dual_T *) vehicle_dual_M->derivs);

  // Derivatives for Integrator: '<S79>/Integrator'
  _rtXdot->Integrator_CSTATE[0] = vehicle_dual_B.stateDer[0];
  _rtXdot->Integrator_CSTATE[1] = vehicle_dual_B.stateDer[1];
  _rtXdot->Integrator_CSTATE[2] = vehicle_dual_B.stateDer[2];
  _rtXdot->Integrator_CSTATE[3] = vehicle_dual_B.stateDer[3];

  // Derivatives for Integrator: '<S77>/lateral'
  _rtXdot->lateral_CSTATE = vehicle_dual_B.Product1;

  // Derivatives for Integrator: '<S78>/lateral'
  _rtXdot->lateral_CSTATE_h = vehicle_dual_B.Product1_p;

  // Derivatives for Integrator: '<S26>/Integrator'
  _rtXdot->Integrator_CSTATE_h[0] = vehicle_dual_B.y[0];
  _rtXdot->Integrator_CSTATE_h[1] = vehicle_dual_B.y[1];
}

// Model initialize function
void vehicle_dual_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&vehicle_dual_M->solverInfo,
                          &vehicle_dual_M->Timing.simTimeStep);
    rtsiSetTPtr(&vehicle_dual_M->solverInfo, &rtmGetTPtr(vehicle_dual_M));
    rtsiSetStepSizePtr(&vehicle_dual_M->solverInfo,
                       &vehicle_dual_M->Timing.stepSize0);
    rtsiSetdXPtr(&vehicle_dual_M->solverInfo, &vehicle_dual_M->derivs);
    rtsiSetContStatesPtr(&vehicle_dual_M->solverInfo, (real_T **)
                         &vehicle_dual_M->contStates);
    rtsiSetNumContStatesPtr(&vehicle_dual_M->solverInfo,
      &vehicle_dual_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&vehicle_dual_M->solverInfo,
      &vehicle_dual_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&vehicle_dual_M->solverInfo,
      &vehicle_dual_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&vehicle_dual_M->solverInfo,
      &vehicle_dual_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&vehicle_dual_M->solverInfo, (&rtmGetErrorStatus
      (vehicle_dual_M)));
    rtsiSetRTModelPtr(&vehicle_dual_M->solverInfo, vehicle_dual_M);
  }

  rtsiSetSimTimeStep(&vehicle_dual_M->solverInfo, MAJOR_TIME_STEP);
  vehicle_dual_M->intgData.y = vehicle_dual_M->odeY;
  vehicle_dual_M->intgData.f[0] = vehicle_dual_M->odeF[0];
  vehicle_dual_M->intgData.f[1] = vehicle_dual_M->odeF[1];
  vehicle_dual_M->intgData.f[2] = vehicle_dual_M->odeF[2];
  vehicle_dual_M->contStates = ((X_vehicle_dual_T *) &vehicle_dual_X);
  rtsiSetSolverData(&vehicle_dual_M->solverInfo, static_cast<void *>
                    (&vehicle_dual_M->intgData));
  rtsiSetSolverName(&vehicle_dual_M->solverInfo,"ode3");
  rtmSetTPtr(vehicle_dual_M, &vehicle_dual_M->Timing.tArray[0]);
  vehicle_dual_M->Timing.stepSize0 = 0.05;
  rtmSetFirstInitCond(vehicle_dual_M, 1);

  {
    char_T tmp[8];
    char_T tmp_0[4];
    int32_T i;
    static const char_T tmp_1[7] = { 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    // InitializeConditions for Integrator: '<S79>/Integrator' incorporates:
    //   Integrator: '<S26>/Integrator'

    if (rtmIsFirstInitCond(vehicle_dual_M)) {
      vehicle_dual_X.Integrator_CSTATE[0] = 0.0;
      vehicle_dual_X.Integrator_CSTATE[1] = 0.0;
      vehicle_dual_X.Integrator_CSTATE[2] = 0.0;
      vehicle_dual_X.Integrator_CSTATE[3] = 0.0;
      vehicle_dual_X.Integrator_CSTATE_h[0] = 0.0;
      vehicle_dual_X.Integrator_CSTATE_h[1] = 0.0;
    }

    vehicle_dual_DW.Integrator_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S79>/Integrator'

    // InitializeConditions for Integrator: '<S77>/lateral'
    vehicle_dual_X.lateral_CSTATE = vehicle_dual_P.lateral_IC;

    // InitializeConditions for Integrator: '<S78>/lateral'
    vehicle_dual_X.lateral_CSTATE_h = vehicle_dual_P.lateral_IC_e;

    // InitializeConditions for Integrator: '<S26>/Integrator'
    vehicle_dual_DW.Integrator_IWORK_b = 1;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S5>/Out1'
    vehicle_dual_B.In1 = vehicle_dual_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    vehicle_dual_DW.obj_g.matlabCodegenIsDeleted = false;
    vehicle_dual_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      tmp[i] = tmp_1[i];
    }

    tmp[7] = '\x00';
    Sub_vehicle_dual_2.createSubscriber(tmp, 1);
    vehicle_dual_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    vehicle_dual_DW.obj.matlabCodegenIsDeleted = false;
    vehicle_dual_DW.obj.isInitialized = 1;
    tmp_0[0] = 'v';
    tmp_0[1] = 'e';
    tmp_0[2] = 'l';
    tmp_0[3] = '\x00';
    Pub_vehicle_dual_11.createPublisher(tmp_0, 1);
    vehicle_dual_DW.obj.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }

  // set "at time zero" to false
  if (rtmIsFirstInitCond(vehicle_dual_M)) {
    rtmSetFirstInitCond(vehicle_dual_M, 0);
  }
}

// Model terminate function
void vehicle_dual_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  matlabCodegenHandle_matlabCod_b(&vehicle_dual_DW.obj_g);

  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&vehicle_dual_DW.obj);

  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
