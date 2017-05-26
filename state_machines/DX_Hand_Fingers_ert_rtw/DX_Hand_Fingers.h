/*
 * File: DX_Hand_Fingers.h
 *
 * Code generated for Simulink model 'DX_Hand_Fingers'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Dec 22 18:21:08 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DX_Hand_Fingers_h_
#define RTW_HEADER_DX_Hand_Fingers_h_
#include <string.h>
#ifndef DX_Hand_Fingers_COMMON_INCLUDES_
# define DX_Hand_Fingers_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DX_Hand_Fingers_COMMON_INCLUDES_ */

#include "DX_Hand_Fingers_types.h"
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
  int32_T control_number;              /* '<Root>/DX_Hand_Fingers ' */
  uint8_T is_active_c3_DX_Hand_Fingers;/* '<Root>/DX_Hand_Fingers ' */
  uint8_T is_Basic_Logic;              /* '<Root>/DX_Hand_Fingers ' */
  uint8_T is_active_Basic_Logic;       /* '<Root>/DX_Hand_Fingers ' */
  uint8_T is_playing_mode;             /* '<Root>/DX_Hand_Fingers ' */
} DW_DX_Hand_Fingers_Sym;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  int32_T thumb_angle;                 /* '<Root>/thumb_angle' */
  int32_T index_angle;                 /* '<Root>/index_angle' */
  int32_T middle_angle;                /* '<Root>/middle_angle' */
  int32_T ring_angle;                  /* '<Root>/ring_angle' */
  int32_T pinky_angle;                 /* '<Root>/pinky_angle' */
  int32_T limit_thumb;                 /* '<Root>/limit_thumb' */
  real_T limit_fingers;                /* '<Root>/limit_fingers' */
  boolean_T is_dx_hand;                /* '<Root>/is_dx_hand' */
  int32_T hand_velocity;               /* '<Root>/hand_velocity' */
  int32_T limit_hand_velocity;         /* '<Root>/limit_hand_velocity' */
} ExtU_DX_Hand_Fingers_Sym;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  int32_T fingers_Output;              /* '<Root>/fingers_Output' */
  int32_T id;                          /* '<Root>/id' */
  boolean_T change_O;                  /* '<Root>/change_O' */
  int32_T octave;                      /* '<Root>/octave' */
} ExtY_DX_Hand_Fingers_Sym;

/* Real-time Model Data Structure */
struct tag_RTM_DX_Hand_Fingers_Sym {
  const char_T * volatile errorStatus;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    DW_DX_Hand_Fingers_Sym *dwork;
  } ModelData;
};

/* Model entry point functions */
extern void DX_Hand_Fingers_initialize(RT_MODEL_DX_Hand_Fingers_Sym *const
  DX_Hand_Fingers_M, ExtU_DX_Hand_Fingers_Sym *DX_Hand_Fingers_U,
  ExtY_DX_Hand_Fingers_Sym *DX_Hand_Fingers_Y);
extern void DX_Hand_Fingers_step(RT_MODEL_DX_Hand_Fingers_Sym *const
  DX_Hand_Fingers_M, ExtU_DX_Hand_Fingers_Sym *DX_Hand_Fingers_U,
  ExtY_DX_Hand_Fingers_Sym *DX_Hand_Fingers_Y);
extern void DX_Hand_Fingers_terminate(RT_MODEL_DX_Hand_Fingers_Sym *const
  DX_Hand_Fingers_M);

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
 * hilite_system('DX_Hand/DX_Hand_Fingers ')    - opens subsystem DX_Hand/DX_Hand_Fingers
 * hilite_system('DX_Hand/DX_Hand_Fingers /Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DX_Hand'
 * '<S1>'   : 'DX_Hand/DX_Hand_Fingers '
 */
#endif                                 /* RTW_HEADER_DX_Hand_Fingers_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
