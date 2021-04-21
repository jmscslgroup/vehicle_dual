//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: vehicle_dual.h
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
#ifndef RTW_HEADER_vehicle_dual_h_
#define RTW_HEADER_vehicle_dual_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "vehicle_dual_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_vehicle_dual_geometry_msgs_Twist In1;// '<S5>/In1'
  SL_Bus_vehicle_dual_geometry_msgs_Twist BusAssignment;// '<Root>/Bus Assignment' 
  real_T VectorConcatenate_c[6];       // '<S19>/Vector Concatenate'
  real_T uAPabsRT[6];                  // '<S19>/.5.*A.*Pabs.//R.//T'
  real_T UnitConversion6;              // '<S79>/Unit Conversion6'
  real_T VectorConcatenate[4];         // '<S79>/Vector Concatenate'
  real_T VectorConcatenate1[3];        // '<S7>/Vector Concatenate1'
  real_T VectorConcatenate1_o[3];      // '<S80>/Vector Concatenate1'
  real_T UnaryMinus[3];                // '<S19>/Unary Minus'
  real_T UnitConversion1;              // '<S73>/Unit Conversion1'
  real_T VectorConcatenate1_d[2];      // '<S71>/Vector Concatenate1'
  real_T Product1;                     // '<S77>/Product1'
  real_T Product1_p;                   // '<S78>/Product1'
  real_T VectorConcatenate3[2];        // '<S4>/Vector Concatenate3'
  real_T stateDer[4];                  // '<S4>/vehicle model'
  real_T y[2];                         // '<S26>/COMB2I'
  real_T alfa_f;
  real_T alfa_r;
  real_T Fy_f;
  real_T Fy_r;
  real_T yddot;
  real_T Fx_ft;
  real_T z_data;
  real_T z1_data;
  real_T d;
  real_T alfa_f_tmp;
  real_T rtb_Product2_g_tmp;
  real_T rtb_Product_o_tmp;
  real_T Fy_f_tmp;
  real_T rtb_VectorConcatenate2_j_m;
  real_T rtb_VectorConcatenate2_j_idx_0;
  real_T rtb_VectorConcatenate2_j_idx_1;
  real_T rtb_VectorConcatenate1_idx_3;
  real_T rtb_Product_idx_1;
  real_T rtb_Product_idx_2;
  real_T Fz_idx_0;
  real_T Fz_idx_1;
} B_vehicle_dual_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_Publ_T obj; // '<S2>/SinkBlock'
  ros_slros_internal_block_Subs_T obj_g;// '<S3>/SourceBlock'
  int_T Integrator_IWORK;              // '<S79>/Integrator'
  int_T Integrator_IWORK_b;            // '<S26>/Integrator'
} DW_vehicle_dual_T;

// Continuous states (default storage)
typedef struct {
  real_T Integrator_CSTATE[4];         // '<S79>/Integrator'
  real_T lateral_CSTATE;               // '<S77>/lateral'
  real_T lateral_CSTATE_h;             // '<S78>/lateral'
  real_T Integrator_CSTATE_h[2];       // '<S26>/Integrator'
} X_vehicle_dual_T;

// State derivatives (default storage)
typedef struct {
  real_T Integrator_CSTATE[4];         // '<S79>/Integrator'
  real_T lateral_CSTATE;               // '<S77>/lateral'
  real_T lateral_CSTATE_h;             // '<S78>/lateral'
  real_T Integrator_CSTATE_h[2];       // '<S26>/Integrator'
} XDot_vehicle_dual_T;

// State disabled
typedef struct {
  boolean_T Integrator_CSTATE[4];      // '<S79>/Integrator'
  boolean_T lateral_CSTATE;            // '<S77>/lateral'
  boolean_T lateral_CSTATE_h;          // '<S78>/lateral'
  boolean_T Integrator_CSTATE_h[2];    // '<S26>/Integrator'
} XDis_vehicle_dual_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Parameters (default storage)
struct P_vehicle_dual_T_ {
  real_T VehicleBody3DOFDualTrack_Af;
                                  // Mask Parameter: VehicleBody3DOFDualTrack_Af
                                     //  Referenced by: '<S19>/.5.*A.*Pabs.//R.//T'

  real_T VehicleBody3DOFDualTrack_Cd;
                                  // Mask Parameter: VehicleBody3DOFDualTrack_Cd
                                     //  Referenced by: '<S19>/Constant'

  real_T VehicleBody3DOFDualTrack_Cl;
                                  // Mask Parameter: VehicleBody3DOFDualTrack_Cl
                                     //  Referenced by: '<S19>/Constant1'

  real_T VehicleBody3DOFDualTrack_Cpm;
                                 // Mask Parameter: VehicleBody3DOFDualTrack_Cpm
                                    //  Referenced by: '<S19>/Constant2'

  real_T VehicleBody3DOFDualTrack_Cs[31];
                                  // Mask Parameter: VehicleBody3DOFDualTrack_Cs
                                     //  Referenced by: '<S19>/Cs'

  real_T VehicleBody3DOFDualTrack_Cy_f;
                                // Mask Parameter: VehicleBody3DOFDualTrack_Cy_f
                                   //  Referenced by: '<S18>/Cyf'

  real_T VehicleBody3DOFDualTrack_Cy_r;
                                // Mask Parameter: VehicleBody3DOFDualTrack_Cy_r
                                   //  Referenced by: '<S18>/Cyr'

  real_T VehicleBody3DOFDualTrack_Cym[31];
                                 // Mask Parameter: VehicleBody3DOFDualTrack_Cym
                                    //  Referenced by: '<S19>/Cym'

  real_T VehicleBody3DOFDualTrack_Fznom;
                               // Mask Parameter: VehicleBody3DOFDualTrack_Fznom
                                  //  Referenced by: '<S4>/vehicle model'

  real_T VehicleBody3DOFDualTrack_Izz;
                                 // Mask Parameter: VehicleBody3DOFDualTrack_Izz
                                    //  Referenced by: '<S4>/vehicle model'

  real_T VehicleBody3DOFDualTrack_NF;
                                  // Mask Parameter: VehicleBody3DOFDualTrack_NF
                                     //  Referenced by: '<S4>/vehicle model'

  real_T VehicleBody3DOFDualTrack_NR;
                                  // Mask Parameter: VehicleBody3DOFDualTrack_NR
                                     //  Referenced by: '<S4>/vehicle model'

  real_T VehicleBody3DOFDualTrack_Pabs;
                                // Mask Parameter: VehicleBody3DOFDualTrack_Pabs
                                   //  Referenced by: '<S19>/.5.*A.*Pabs.//R.//T'

  real_T DragForce_R;                  // Mask Parameter: DragForce_R
                                          //  Referenced by: '<S19>/.5.*A.*Pabs.//R.//T'

  real_T HardPointCoordinateTransformFro;
                              // Mask Parameter: HardPointCoordinateTransformFro
                                 //  Referenced by: '<S27>/R_T2'

  real_T HardPointCoordinateTransformRea;
                              // Mask Parameter: HardPointCoordinateTransformRea
                                 //  Referenced by: '<S29>/R_T2'

  real_T VehicleBody3DOFDualTrack_Tair;
                                // Mask Parameter: VehicleBody3DOFDualTrack_Tair
                                   //  Referenced by: '<S4>/AirTempConstant'

  real_T VehicleBody3DOFDualTrack_X_o;
                                 // Mask Parameter: VehicleBody3DOFDualTrack_X_o
                                    //  Referenced by: '<S4>/X_oConstant'

  real_T VehicleBody3DOFDualTrack_Y_o;
                                 // Mask Parameter: VehicleBody3DOFDualTrack_Y_o
                                    //  Referenced by: '<S4>/Y_oConstant'

  real_T VehicleBody3DOFDualTrack_a;
                                   // Mask Parameter: VehicleBody3DOFDualTrack_a
                                      //  Referenced by:
                                      //    '<S4>/vehicle model'
                                      //    '<S19>/Constant3'
                                      //    '<S27>/R_T1'

  real_T VehicleBody3DOFDualTrack_b;
                                   // Mask Parameter: VehicleBody3DOFDualTrack_b
                                      //  Referenced by:
                                      //    '<S4>/vehicle model'
                                      //    '<S19>/Constant3'
                                      //    '<S29>/R_T1'

  real_T VehicleBody3DOFDualTrack_beta_w[31];
                              // Mask Parameter: VehicleBody3DOFDualTrack_beta_w
                                 //  Referenced by:
                                 //    '<S19>/Cs'
                                 //    '<S19>/Cym'

  real_T VehicleBody3DOFDualTrack_g;
                                   // Mask Parameter: VehicleBody3DOFDualTrack_g
                                      //  Referenced by: '<S4>/vehicle model'

  real_T VehicleBody3DOFDualTrack_h;
                                   // Mask Parameter: VehicleBody3DOFDualTrack_h
                                      //  Referenced by:
                                      //    '<S4>/vehicle model'
                                      //    '<S27>/R_T3'
                                      //    '<S29>/R_T3'

  real_T VehicleBody3DOFDualTrack_latOff;
                              // Mask Parameter: VehicleBody3DOFDualTrack_latOff
                                 //  Referenced by: '<S28>/latOff'

  real_T VehicleBody3DOFDualTrack_longOf;
                              // Mask Parameter: VehicleBody3DOFDualTrack_longOf
                                 //  Referenced by: '<S28>/longOff'

  real_T VehicleBody3DOFDualTrack_m;
                                   // Mask Parameter: VehicleBody3DOFDualTrack_m
                                      //  Referenced by: '<S4>/vehicle model'

  real_T VehicleBody3DOFDualTrack_mu;
                                  // Mask Parameter: VehicleBody3DOFDualTrack_mu
                                     //  Referenced by: '<S71>/Constant'

  real_T VehicleBody3DOFDualTrack_psi_o;
                               // Mask Parameter: VehicleBody3DOFDualTrack_psi_o
                                  //  Referenced by: '<S4>/psi_oConstant'

  real_T VehicleBody3DOFDualTrack_r_o;
                                 // Mask Parameter: VehicleBody3DOFDualTrack_r_o
                                    //  Referenced by: '<S4>/r_oConstant'

  real_T VehicleBody3DOFDualTrack_sigma_;
                              // Mask Parameter: VehicleBody3DOFDualTrack_sigma_
                                 //  Referenced by: '<S76>/Constant1'

  real_T VehicleBody3DOFDualTrack_sigm_e;
                              // Mask Parameter: VehicleBody3DOFDualTrack_sigm_e
                                 //  Referenced by: '<S76>/Constant2'

  real_T VehicleBody3DOFDualTrack_vertOf;
                              // Mask Parameter: VehicleBody3DOFDualTrack_vertOf
                                 //  Referenced by: '<S28>/vertOff'

  real_T VehicleBody3DOFDualTrack_xdot_t;
                              // Mask Parameter: VehicleBody3DOFDualTrack_xdot_t
                                 //  Referenced by: '<S4>/vehicle model'

  real_T VehicleBody3DOFDualTrack_ydot_o;
                              // Mask Parameter: VehicleBody3DOFDualTrack_ydot_o
                                 //  Referenced by: '<S4>/ydot_oConstant'

  SL_Bus_vehicle_dual_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                     //  Referenced by: '<S5>/Out1'

  SL_Bus_vehicle_dual_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                            //  Referenced by: '<S3>/Constant'

  SL_Bus_vehicle_dual_geometry_msgs_Twist Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                              //  Referenced by: '<S1>/Constant'

  real_T vehiclemodel_Fxtire_sat;      // Expression: Fxtire_sat
                                          //  Referenced by: '<S4>/vehicle model'

  real_T vehiclemodel_Fytire_sat;      // Expression: Fytire_sat
                                          //  Referenced by: '<S4>/vehicle model'

  real_T vehiclemodel_d;               // Expression: d
                                          //  Referenced by: '<S4>/vehicle model'

  real_T vehiclemodel_w[2];            // Expression: w
                                          //  Referenced by: '<S4>/vehicle model'

  real_T xdot_oConstant_Value;         // Expression: 0
                                          //  Referenced by: '<S4>/xdot_oConstant'

  real_T Constant_Value_f;             // Expression: 0
                                          //  Referenced by: '<S7>/Constant'

  real_T Crm_tableData[2];             // Expression: [0 0]
                                          //  Referenced by: '<S19>/Crm'

  real_T Crm_bp01Data[2];              // Expression: [-1 1]
                                          //  Referenced by: '<S19>/Crm'

  real_T Constant4_Value[3];           // Expression: ones(1,3)
                                          //  Referenced by: '<S19>/Constant4'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<S19>/Switch'

  real_T Constant6_Value;              // Expression: 0
                                          //  Referenced by: '<S26>/Constant6'

  real_T Constant4_Value_m;            // Expression: 0
                                          //  Referenced by: '<S26>/Constant4'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S26>/Constant5'

  real_T Constant7_Value;              // Expression: 0
                                          //  Referenced by: '<S26>/Constant7'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S26>/Constant2'

  real_T lateral_IC;                   // Expression: 0
                                          //  Referenced by: '<S77>/lateral'

  real_T lateral_IC_e;                 // Expression: 0
                                          //  Referenced by: '<S78>/lateral'

  real_T Constant2_Value_l;            // Expression: 2*pi
                                          //  Referenced by: '<Root>/Constant2'

};

// Real-time Model Data Structure
struct tag_RTM_vehicle_dual_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_vehicle_dual_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[8];
  real_T odeF[3][8];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    boolean_T firstInitCondFlag;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_vehicle_dual_T vehicle_dual_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_vehicle_dual_T vehicle_dual_B;

#ifdef __cplusplus

}
#endif

// Continuous states (default storage)
extern X_vehicle_dual_T vehicle_dual_X;

// Block states (default storage)
extern DW_vehicle_dual_T vehicle_dual_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void vehicle_dual_initialize(void);
  extern void vehicle_dual_step(void);
  extern void vehicle_dual_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_vehicle_dual_T *const vehicle_dual_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S27>/Add' : Unused code path elimination
//  Block '<S27>/Add1' : Unused code path elimination
//  Block '<S27>/Add4' : Unused code path elimination
//  Block '<S34>/Reshape (9) to [3x3] column-major' : Unused code path elimination
//  Block '<S27>/Transpose1' : Unused code path elimination
//  Block '<S31>/Product' : Unused code path elimination
//  Block '<S31>/Reshape1' : Unused code path elimination
//  Block '<S31>/Reshape2' : Unused code path elimination
//  Block '<S32>/Product' : Unused code path elimination
//  Block '<S32>/Reshape1' : Unused code path elimination
//  Block '<S32>/Reshape2' : Unused code path elimination
//  Block '<S35>/i x j' : Unused code path elimination
//  Block '<S35>/j x k' : Unused code path elimination
//  Block '<S35>/k x i' : Unused code path elimination
//  Block '<S36>/i x k' : Unused code path elimination
//  Block '<S36>/j x i' : Unused code path elimination
//  Block '<S36>/k x j' : Unused code path elimination
//  Block '<S33>/Sum' : Unused code path elimination
//  Block '<S37>/Add' : Unused code path elimination
//  Block '<S37>/Add1' : Unused code path elimination
//  Block '<S37>/Add4' : Unused code path elimination
//  Block '<S38>/Divide' : Unused code path elimination
//  Block '<S38>/Trigonometric Function' : Unused code path elimination
//  Block '<S43>/Abs' : Unused code path elimination
//  Block '<S44>/Compare' : Unused code path elimination
//  Block '<S44>/Constant' : Unused code path elimination
//  Block '<S45>/Compare' : Unused code path elimination
//  Block '<S45>/Constant' : Unused code path elimination
//  Block '<S43>/Fcn' : Unused code path elimination
//  Block '<S43>/Logical Operator' : Unused code path elimination
//  Block '<S43>/Switch' : Unused code path elimination
//  Block '<S46>/Reshape (9) to [3x3] column-major' : Unused code path elimination
//  Block '<S37>/Transpose1' : Unused code path elimination
//  Block '<S40>/Product' : Unused code path elimination
//  Block '<S40>/Reshape1' : Unused code path elimination
//  Block '<S40>/Reshape2' : Unused code path elimination
//  Block '<S41>/Product' : Unused code path elimination
//  Block '<S41>/Reshape1' : Unused code path elimination
//  Block '<S41>/Reshape2' : Unused code path elimination
//  Block '<S47>/i x j' : Unused code path elimination
//  Block '<S47>/j x k' : Unused code path elimination
//  Block '<S47>/k x i' : Unused code path elimination
//  Block '<S48>/i x k' : Unused code path elimination
//  Block '<S48>/j x i' : Unused code path elimination
//  Block '<S48>/k x j' : Unused code path elimination
//  Block '<S42>/Sum' : Unused code path elimination
//  Block '<S29>/Add' : Unused code path elimination
//  Block '<S29>/Add1' : Unused code path elimination
//  Block '<S29>/Add4' : Unused code path elimination
//  Block '<S53>/Reshape (9) to [3x3] column-major' : Unused code path elimination
//  Block '<S29>/Transpose1' : Unused code path elimination
//  Block '<S50>/Product' : Unused code path elimination
//  Block '<S50>/Reshape1' : Unused code path elimination
//  Block '<S50>/Reshape2' : Unused code path elimination
//  Block '<S51>/Product' : Unused code path elimination
//  Block '<S51>/Reshape1' : Unused code path elimination
//  Block '<S51>/Reshape2' : Unused code path elimination
//  Block '<S54>/i x j' : Unused code path elimination
//  Block '<S54>/j x k' : Unused code path elimination
//  Block '<S54>/k x i' : Unused code path elimination
//  Block '<S55>/i x k' : Unused code path elimination
//  Block '<S55>/j x i' : Unused code path elimination
//  Block '<S55>/k x j' : Unused code path elimination
//  Block '<S52>/Sum' : Unused code path elimination
//  Block '<S25>/Constant' : Unused code path elimination
//  Block '<S25>/Constant1' : Unused code path elimination
//  Block '<S25>/Constant2' : Unused code path elimination
//  Block '<S25>/Product' : Unused code path elimination
//  Block '<S25>/Product12' : Unused code path elimination
//  Block '<S25>/Product13' : Unused code path elimination
//  Block '<S25>/Product5' : Unused code path elimination
//  Block '<S25>/Product6' : Unused code path elimination
//  Block '<S25>/Product7' : Unused code path elimination
//  Block '<S25>/Sum of Elements2' : Unused code path elimination
//  Block '<S25>/Sum of Elements3' : Unused code path elimination
//  Block '<S25>/Unary Minus5' : Unused code path elimination
//  Block '<S25>/Unit Conversion1' : Unused code path elimination
//  Block '<S25>/Unit Conversion2' : Unused code path elimination
//  Block '<S61>/Add' : Unused code path elimination
//  Block '<S61>/Unary Minus1' : Unused code path elimination
//  Block '<S61>/Unary Minus2' : Unused code path elimination
//  Block '<S61>/Unary Minus3' : Unused code path elimination
//  Block '<S63>/Divide' : Unused code path elimination
//  Block '<S63>/Trigonometric Function' : Unused code path elimination
//  Block '<S67>/Abs' : Unused code path elimination
//  Block '<S68>/Compare' : Unused code path elimination
//  Block '<S68>/Constant' : Unused code path elimination
//  Block '<S69>/Compare' : Unused code path elimination
//  Block '<S69>/Constant' : Unused code path elimination
//  Block '<S67>/Fcn' : Unused code path elimination
//  Block '<S67>/Logical Operator' : Unused code path elimination
//  Block '<S67>/Switch' : Unused code path elimination
//  Block '<S26>/Constant' : Unused code path elimination
//  Block '<S26>/Constant1' : Unused code path elimination
//  Block '<S26>/Constant10' : Unused code path elimination
//  Block '<S26>/Constant3' : Unused code path elimination
//  Block '<S26>/Constant8' : Unused code path elimination
//  Block '<S26>/Constant9' : Unused code path elimination
//  Block '<S65>/Divide' : Unused code path elimination
//  Block '<S65>/Divide1' : Unused code path elimination
//  Block '<S65>/Sum of Elements' : Unused code path elimination
//  Block '<S65>/Sum of Elements1' : Unused code path elimination
//  Block '<S70>/Unit Conversion' : Unused code path elimination
//  Block '<S70>/Unit Conversion1' : Unused code path elimination


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
//  '<Root>' : 'vehicle_dual'
//  '<S1>'   : 'vehicle_dual/Blank Message'
//  '<S2>'   : 'vehicle_dual/Publish'
//  '<S3>'   : 'vehicle_dual/Subscribe'
//  '<S4>'   : 'vehicle_dual/Vehicle Body 3DOF Dual Track'
//  '<S5>'   : 'vehicle_dual/Subscribe/Enabled Subsystem'
//  '<S6>'   : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Cy'
//  '<S7>'   : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Drag'
//  '<S8>'   : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing'
//  '<S9>'   : 'vehicle_dual/Vehicle Body 3DOF Dual Track/friction'
//  '<S10>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/front forces'
//  '<S11>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/front steer'
//  '<S12>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/rear forces'
//  '<S13>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/rear steer'
//  '<S14>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/sigma'
//  '<S15>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/state'
//  '<S16>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/vehicle model'
//  '<S17>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/wind'
//  '<S18>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Cy/Cy const'
//  '<S19>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Drag/Drag Force'
//  '<S20>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Drag/inertial2body'
//  '<S21>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing'
//  '<S22>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Forces 3DOF'
//  '<S23>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF'
//  '<S24>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Moments'
//  '<S25>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Power'
//  '<S26>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/state2bus'
//  '<S27>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Front'
//  '<S28>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric'
//  '<S29>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Rear'
//  '<S30>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Front/Rotation Angles to Direction Cosine Matrix'
//  '<S31>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Front/transform to Inertial axes'
//  '<S32>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Front/transform to Inertial axes1'
//  '<S33>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Front/wxR'
//  '<S34>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Front/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S35>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Front/wxR/Subsystem'
//  '<S36>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Front/wxR/Subsystem1'
//  '<S37>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric/Hard Point Coordinate Transform External Displacement Beta'
//  '<S38>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric/Hard Point Coordinate Transform External Displacement Beta/Body Slip'
//  '<S39>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric/Hard Point Coordinate Transform External Displacement Beta/Rotation Angles to Direction Cosine Matrix'
//  '<S40>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric/Hard Point Coordinate Transform External Displacement Beta/transform to Inertial axes'
//  '<S41>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric/Hard Point Coordinate Transform External Displacement Beta/transform to Inertial axes1'
//  '<S42>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric/Hard Point Coordinate Transform External Displacement Beta/wxR'
//  '<S43>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric/Hard Point Coordinate Transform External Displacement Beta/Body Slip/div0protect - abs poly'
//  '<S44>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric/Hard Point Coordinate Transform External Displacement Beta/Body Slip/div0protect - abs poly/Compare To Constant'
//  '<S45>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric/Hard Point Coordinate Transform External Displacement Beta/Body Slip/div0protect - abs poly/Compare To Constant1'
//  '<S46>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric/Hard Point Coordinate Transform External Displacement Beta/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S47>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric/Hard Point Coordinate Transform External Displacement Beta/wxR/Subsystem'
//  '<S48>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Geometric/Hard Point Coordinate Transform External Displacement Beta/wxR/Subsystem1'
//  '<S49>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Rear/Rotation Angles to Direction Cosine Matrix'
//  '<S50>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Rear/transform to Inertial axes'
//  '<S51>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Rear/transform to Inertial axes1'
//  '<S52>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Rear/wxR'
//  '<S53>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Rear/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S54>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Rear/wxR/Subsystem'
//  '<S55>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Lateral 3DOF/Hard Point Coordinate Transform Rear/wxR/Subsystem1'
//  '<S56>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Power/Power Accounting Bus Creator'
//  '<S57>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Power/xdot mode'
//  '<S58>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Power/Power Accounting Bus Creator/PwrNotTrnsfrd Input'
//  '<S59>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Power/Power Accounting Bus Creator/PwrStored Input'
//  '<S60>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Power/Power Accounting Bus Creator/PwrTrnsfrd Input'
//  '<S61>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/Power/xdot mode/xdotin'
//  '<S62>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/state2bus/Angle Wrap'
//  '<S63>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/state2bus/Body Slip'
//  '<S64>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/state2bus/COMB2I'
//  '<S65>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/state2bus/xddot2ax'
//  '<S66>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/state2bus/Angle Wrap/None'
//  '<S67>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/state2bus/Body Slip/div0protect - abs poly'
//  '<S68>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/state2bus/Body Slip/div0protect - abs poly/Compare To Constant'
//  '<S69>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/state2bus/Body Slip/div0protect - abs poly/Compare To Constant1'
//  '<S70>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/Signal Routing/Signal Routing/state2bus/xddot2ax/m^22gn'
//  '<S71>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/friction/mu int'
//  '<S72>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/front forces/int'
//  '<S73>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/front steer/delta ext'
//  '<S74>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/rear forces/int'
//  '<S75>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/rear steer/delta int'
//  '<S76>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/sigma/sigma'
//  '<S77>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/sigma/sigma/relaxation front'
//  '<S78>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/sigma/sigma/relaxation rear'
//  '<S79>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/state/xdot ext'
//  '<S80>'  : 'vehicle_dual/Vehicle Body 3DOF Dual Track/wind/wind int'

#endif                                 // RTW_HEADER_vehicle_dual_h_

//
// File trailer for generated code.
//
// [EOF]
//
