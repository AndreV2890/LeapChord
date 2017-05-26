/*
 * File: SX_Hand0.h
 *
 * Code generated for Simulink model 'SX_Hand0'.
 *
 * Model version                  : 1.128
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Dec  1 14:07:25 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SX_Hand0_h_
#define RTW_HEADER_SX_Hand0_h_
#include <string.h>
#ifndef SX_Hand0_COMMON_INCLUDES_
# define SX_Hand0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SX_Hand0_COMMON_INCLUDES_ */

#include "SX_Hand0_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_SX_Hand0;       /* '<Root>/SX_Hand' */
  uint8_T is_Chord_change_control;     /* '<Root>/SX_Hand' */
  uint8_T is_active_Chord_change_control;/* '<Root>/SX_Hand' */
  uint8_T is_Alterations_control;      /* '<Root>/SX_Hand' */
  uint8_T is_active_Alterations_control;/* '<Root>/SX_Hand' */
  uint8_T is_playing_mode;             /* '<Root>/SX_Hand' */
} D_Work_SX_Hand0_SymType;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  int32_T v_x_polso;                   /* '<Root>/v_x_polso' */
  int32_T v_y_polso;                   /* '<Root>/v_y_polso' */
  int32_T v_z_polso;                   /* '<Root>/v_z_polso' */
  boolean_T up_polso;                  /* '<Root>/up_polso' */
  boolean_T is_sx_hand;                /* '<Root>/is_sx_hand' */
  int32_T v_limit;                     /* '<Root>/v_limit' */
} ExternalInputs_SX_Hand0_SymType;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint16_T id;                         /* '<Root>/id' */
  uint8_T chord_relO;                  /* '<Root>/chord_relO' */
  uint8_T chord_altO;                  /* '<Root>/chord_altO' */
  boolean_T changeO;                   /* '<Root>/changeO' */
  int32_T vel_for_volO;                /* '<Root>/vel_for_volO' */
} ExternalOutputs_SX_Hand_SymType;

/* Real-time Model Data Structure */
struct tag_RTM_SX_Hand0_SymType {
  const char_T * volatile errorStatus;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    D_Work_SX_Hand0_SymType *dwork;
  } ModelData;
};

/* Model entry point functions */
extern void SX_Hand0_initialize(RT_MODEL_SX_Hand0_SymType *const SX_Hand0_M,
  ExternalInputs_SX_Hand0_SymType *SX_Hand0_U, ExternalOutputs_SX_Hand_SymType
  *SX_Hand0_Y);
extern void SX_Hand0_step(RT_MODEL_SX_Hand0_SymType *const SX_Hand0_M,
  ExternalInputs_SX_Hand0_SymType *SX_Hand0_U, ExternalOutputs_SX_Hand_SymType
  *SX_Hand0_Y);
extern void SX_Hand0_terminate(RT_MODEL_SX_Hand0_SymType *const SX_Hand0_M);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('SX_Hand/SX_Hand')    - opens subsystem SX_Hand/SX_Hand
 * hilite_system('SX_Hand/SX_Hand/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SX_Hand'
 * '<S1>'   : 'SX_Hand/SX_Hand'
 */
#endif                                 /* RTW_HEADER_SX_Hand0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
