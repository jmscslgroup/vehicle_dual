//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: vehicle_dual_data.cpp
//
// Code generated for Simulink model 'vehicle_dual'.
//
// Model version                  : 1.8
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Tue Apr 20 15:19:55 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "vehicle_dual.h"
#include "vehicle_dual_private.h"

// Block parameters (default storage)
P_vehicle_dual_T vehicle_dual_P = {
  // Mask Parameter: VehicleBody3DOFDualTrack_Af
  //  Referenced by: '<S19>/.5.*A.*Pabs.//R.//T'

  2.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_Cd
  //  Referenced by: '<S19>/Constant'

  0.3,

  // Mask Parameter: VehicleBody3DOFDualTrack_Cl
  //  Referenced by: '<S19>/Constant1'

  0.1,

  // Mask Parameter: VehicleBody3DOFDualTrack_Cpm
  //  Referenced by: '<S19>/Constant2'

  0.1,

  // Mask Parameter: VehicleBody3DOFDualTrack_Cs
  //  Referenced by: '<S19>/Cs'

  { 0.0, 0.03, 0.06, 0.09, 0.12, 0.15, 0.18, 0.21, 0.24, 0.27, 0.3,
    0.32999999999999996, 0.36, 0.39, 0.42, 0.45, 0.48000000000000004, 0.51, 0.54,
    0.57000000000000006, 0.60000000000000009, 0.63, 0.66, 0.69000000000000006,
    0.72, 0.75, 0.78, 0.81, 0.84000000000000008, 0.87, 0.9 },

  // Mask Parameter: VehicleBody3DOFDualTrack_Cy_f
  //  Referenced by: '<S18>/Cyf'

  12000.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_Cy_r
  //  Referenced by: '<S18>/Cyr'

  11000.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_Cym
  //  Referenced by: '<S19>/Cym'

  { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1, 0.11, 0.12,
    0.13, 0.14, 0.15, 0.15999999999999998, 0.16999999999999998, 0.18, 0.19,
    0.19999999999999998, 0.21, 0.21999999999999997, 0.22999999999999998, 0.24,
    0.25, 0.26, 0.27, 0.27999999999999997, 0.29, 0.3 },

  // Mask Parameter: VehicleBody3DOFDualTrack_Fznom
  //  Referenced by: '<S4>/vehicle model'

  5000.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_Izz
  //  Referenced by: '<S4>/vehicle model'

  4000.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_NF
  //  Referenced by: '<S4>/vehicle model'

  2.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_NR
  //  Referenced by: '<S4>/vehicle model'

  2.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_Pabs
  //  Referenced by: '<S19>/.5.*A.*Pabs.//R.//T'

  101325.0,

  // Mask Parameter: DragForce_R
  //  Referenced by: '<S19>/.5.*A.*Pabs.//R.//T'

  287.058,

  // Mask Parameter: HardPointCoordinateTransformFro
  //  Referenced by: '<S27>/R_T2'

  0.0,

  // Mask Parameter: HardPointCoordinateTransformRea
  //  Referenced by: '<S29>/R_T2'

  0.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_Tair
  //  Referenced by: '<S4>/AirTempConstant'

  308.15,

  // Mask Parameter: VehicleBody3DOFDualTrack_X_o
  //  Referenced by: '<S4>/X_oConstant'

  0.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_Y_o
  //  Referenced by: '<S4>/Y_oConstant'

  0.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_a
  //  Referenced by:
  //    '<S4>/vehicle model'
  //    '<S19>/Constant3'
  //    '<S27>/R_T1'

  1.4,

  // Mask Parameter: VehicleBody3DOFDualTrack_b
  //  Referenced by:
  //    '<S4>/vehicle model'
  //    '<S19>/Constant3'
  //    '<S29>/R_T1'

  1.6,

  // Mask Parameter: VehicleBody3DOFDualTrack_beta_w
  //  Referenced by:
  //    '<S19>/Cs'
  //    '<S19>/Cym'

  { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1, 0.11, 0.12,
    0.13, 0.14, 0.15, 0.15999999999999998, 0.16999999999999998, 0.18, 0.19,
    0.19999999999999998, 0.21, 0.21999999999999997, 0.22999999999999998, 0.24,
    0.25, 0.26, 0.27, 0.27999999999999997, 0.29, 0.3 },

  // Mask Parameter: VehicleBody3DOFDualTrack_g
  //  Referenced by: '<S4>/vehicle model'

  9.81,

  // Mask Parameter: VehicleBody3DOFDualTrack_h
  //  Referenced by:
  //    '<S4>/vehicle model'
  //    '<S27>/R_T3'
  //    '<S29>/R_T3'

  0.35,

  // Mask Parameter: VehicleBody3DOFDualTrack_latOff
  //  Referenced by: '<S28>/latOff'

  0.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_longOf
  //  Referenced by: '<S28>/longOff'

  0.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_m
  //  Referenced by: '<S4>/vehicle model'

  2000.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_mu
  //  Referenced by: '<S71>/Constant'

  1.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_psi_o
  //  Referenced by: '<S4>/psi_oConstant'

  0.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_r_o
  //  Referenced by: '<S4>/r_oConstant'

  0.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_sigma_
  //  Referenced by: '<S76>/Constant1'

  0.1,

  // Mask Parameter: VehicleBody3DOFDualTrack_sigm_e
  //  Referenced by: '<S76>/Constant2'

  0.1,

  // Mask Parameter: VehicleBody3DOFDualTrack_vertOf
  //  Referenced by: '<S28>/vertOff'

  0.0,

  // Mask Parameter: VehicleBody3DOFDualTrack_xdot_t
  //  Referenced by: '<S4>/vehicle model'

  0.01,

  // Mask Parameter: VehicleBody3DOFDualTrack_ydot_o
  //  Referenced by: '<S4>/ydot_oConstant'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S5>/Out1'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S3>/Constant'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S1>/Constant'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Expression: Fxtire_sat
  //  Referenced by: '<S4>/vehicle model'

  70000.0,

  // Expression: Fytire_sat
  //  Referenced by: '<S4>/vehicle model'

  70000.0,

  // Expression: d
  //  Referenced by: '<S4>/vehicle model'

  0.0,

  // Expression: w
  //  Referenced by: '<S4>/vehicle model'

  { 1.4, 1.4 },

  // Expression: 0
  //  Referenced by: '<S4>/xdot_oConstant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S7>/Constant'

  0.0,

  // Expression: [0 0]
  //  Referenced by: '<S19>/Crm'

  { 0.0, 0.0 },

  // Expression: [-1 1]
  //  Referenced by: '<S19>/Crm'

  { -1.0, 1.0 },

  // Expression: ones(1,3)
  //  Referenced by: '<S19>/Constant4'

  { 1.0, 1.0, 1.0 },

  // Expression: 0
  //  Referenced by: '<S19>/Switch'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant6'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S77>/lateral'

  0.0,

  // Expression: 0
  //  Referenced by: '<S78>/lateral'

  0.0,

  // Expression: 2*pi
  //  Referenced by: '<Root>/Constant2'

  6.2831853071795862
};

//
// File trailer for generated code.
//
// [EOF]
//
