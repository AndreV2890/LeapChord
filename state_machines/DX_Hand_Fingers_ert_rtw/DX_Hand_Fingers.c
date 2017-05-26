/*
 * File: DX_Hand_Fingers.c
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

#include "DX_Hand_Fingers.h"
#include "DX_Hand_Fingers_private.h"

/* Named constants for Chart: '<Root>/DX_Hand_Fingers ' */
#define DX_Hand_Fing_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define DX_Hand_Fingers_IN_down        ((uint8_T)1U)
#define DX_Hand_Fingers_IN_play_finger ((uint8_T)2U)
#define DX_Hand_Fingers_IN_playing_mode ((uint8_T)1U)
#define DX_Hand_Fingers_IN_up          ((uint8_T)3U)
#define DX_Hand_Fingers_IN_wait_dx_hand ((uint8_T)2U)
#define DX_Hand_Fingers_IN_wait_finger ((uint8_T)4U)

/* Forward declaration for local functions */
static void DX_Hand_Fingers_Basic_Logic(ExtU_DX_Hand_Fingers_Sym
  *DX_Hand_Fingers_U, ExtY_DX_Hand_Fingers_Sym *DX_Hand_Fingers_Y,
  DW_DX_Hand_Fingers_Sym *DX_Hand_Fingers_DW);
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = (uint32_T)(in0 < 0 ? -in0 : in0);
  absIn1 = (uint32_T)(in1 < 0 ? -in1 : in1);
  in0Hi = absIn0 >> 16U;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16U;
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << 16U) + absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += productHiLo << 16U;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn1;
  if (!((in0 == 0) || ((in1 == 0) || ((in0 > 0) == (in1 > 0))))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_s32_s32_sat(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  if (((int32_T)u32_chi > 0) || ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo <
               2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

/* Function for Chart: '<Root>/DX_Hand_Fingers ' */
static void DX_Hand_Fingers_Basic_Logic(ExtU_DX_Hand_Fingers_Sym
  *DX_Hand_Fingers_U, ExtY_DX_Hand_Fingers_Sym *DX_Hand_Fingers_Y,
  DW_DX_Hand_Fingers_Sym *DX_Hand_Fingers_DW)
{
  int32_T qY;
  int32_T q1;

  /* During 'Basic_Logic': '<S1>:123' */
  DX_Hand_Fingers_Y->change_O = false;
  if (DX_Hand_Fingers_DW->is_Basic_Logic == DX_Hand_Fingers_IN_playing_mode) {
    /* During 'playing_mode': '<S1>:129' */
    if (!DX_Hand_Fingers_U->is_dx_hand) {
      /* Transition: '<S1>:130' */
      /* Exit Internal 'playing_mode': '<S1>:129' */
      DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fing_IN_NO_ACTIVE_CHILD;
      DX_Hand_Fingers_DW->is_Basic_Logic = DX_Hand_Fingers_IN_wait_dx_hand;

      /* Entry 'wait_dx_hand': '<S1>:127' */
      qY = DX_Hand_Fingers_Y->id + 1;
      if ((DX_Hand_Fingers_Y->id > 0) && (qY <= 0)) {
        qY = MAX_int32_T;
      }

      DX_Hand_Fingers_Y->id = qY;
      DX_Hand_Fingers_Y->fingers_Output = -1;
      DX_Hand_Fingers_Y->change_O = true;
      DX_Hand_Fingers_DW->control_number = 0;
    } else {
      switch (DX_Hand_Fingers_DW->is_playing_mode) {
       case DX_Hand_Fingers_IN_down:
        /* During 'down': '<S1>:151' */
        if (DX_Hand_Fingers_U->limit_hand_velocity <= MIN_int32_T) {
          qY = MAX_int32_T;
        } else {
          qY = -DX_Hand_Fingers_U->limit_hand_velocity;
        }

        if (DX_Hand_Fingers_U->hand_velocity > qY) {
          /* Transition: '<S1>:145' */
          DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fingers_IN_wait_finger;

          /* Entry 'wait_finger': '<S1>:131' */
          qY = DX_Hand_Fingers_Y->id + 1;
          if ((DX_Hand_Fingers_Y->id > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->id = qY;
          DX_Hand_Fingers_Y->fingers_Output = -1;
          DX_Hand_Fingers_Y->change_O = true;
        }
        break;

       case DX_Hand_Fingers_IN_play_finger:
        /* During 'play_finger': '<S1>:132' */
        if ((DX_Hand_Fingers_U->thumb_angle < DX_Hand_Fingers_U->limit_thumb) &&
            (DX_Hand_Fingers_U->index_angle < DX_Hand_Fingers_U->limit_fingers) &&
            (DX_Hand_Fingers_U->middle_angle < DX_Hand_Fingers_U->limit_fingers)
            && (DX_Hand_Fingers_U->ring_angle < DX_Hand_Fingers_U->limit_fingers)
            && (DX_Hand_Fingers_U->pinky_angle <
                DX_Hand_Fingers_U->limit_fingers)) {
          /* Transition: '<S1>:139' */
          DX_Hand_Fingers_DW->is_Basic_Logic = DX_Hand_Fingers_IN_playing_mode;
          DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fingers_IN_wait_finger;

          /* Entry 'wait_finger': '<S1>:131' */
          qY = DX_Hand_Fingers_Y->id + 1;
          if ((DX_Hand_Fingers_Y->id > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->id = qY;
          DX_Hand_Fingers_Y->fingers_Output = -1;
          DX_Hand_Fingers_Y->change_O = true;
        }
        break;

       case DX_Hand_Fingers_IN_up:
        /* During 'up': '<S1>:150' */
        if (DX_Hand_Fingers_U->hand_velocity <
            DX_Hand_Fingers_U->limit_hand_velocity) {
          /* Transition: '<S1>:149' */
          DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fingers_IN_wait_finger;

          /* Entry 'wait_finger': '<S1>:131' */
          qY = DX_Hand_Fingers_Y->id + 1;
          if ((DX_Hand_Fingers_Y->id > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->id = qY;
          DX_Hand_Fingers_Y->fingers_Output = -1;
          DX_Hand_Fingers_Y->change_O = true;
        }
        break;

       default:
        /* During 'wait_finger': '<S1>:131' */
        if (DX_Hand_Fingers_U->thumb_angle > DX_Hand_Fingers_U->limit_thumb) {
          /* Transition: '<S1>:134' */
          DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fingers_IN_play_finger;

          /* Entry 'play_finger': '<S1>:132' */
          qY = DX_Hand_Fingers_Y->id + 1;
          if ((DX_Hand_Fingers_Y->id > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->id = qY;
          DX_Hand_Fingers_Y->fingers_Output = mul_s32_s32_s32_sat
            (DX_Hand_Fingers_Y->octave, 5);
          DX_Hand_Fingers_Y->change_O = true;
          DX_Hand_Fingers_DW->control_number = 0;
        } else if (DX_Hand_Fingers_U->index_angle >
                   DX_Hand_Fingers_U->limit_fingers) {
          /* Transition: '<S1>:135' */
          DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fingers_IN_play_finger;

          /* Entry 'play_finger': '<S1>:132' */
          qY = DX_Hand_Fingers_Y->id + 1;
          if ((DX_Hand_Fingers_Y->id > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->id = qY;
          q1 = mul_s32_s32_s32_sat(DX_Hand_Fingers_Y->octave, 5);
          qY = 1 + q1;
          if ((q1 > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->fingers_Output = qY;
          DX_Hand_Fingers_Y->change_O = true;
          DX_Hand_Fingers_DW->control_number = 0;
        } else if (DX_Hand_Fingers_U->middle_angle >
                   DX_Hand_Fingers_U->limit_fingers) {
          /* Transition: '<S1>:136' */
          DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fingers_IN_play_finger;

          /* Entry 'play_finger': '<S1>:132' */
          qY = DX_Hand_Fingers_Y->id + 1;
          if ((DX_Hand_Fingers_Y->id > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->id = qY;
          q1 = mul_s32_s32_s32_sat(DX_Hand_Fingers_Y->octave, 5);
          qY = 2 + q1;
          if ((q1 > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->fingers_Output = qY;
          DX_Hand_Fingers_Y->change_O = true;
          DX_Hand_Fingers_DW->control_number = 0;
        } else if (DX_Hand_Fingers_U->ring_angle >
                   DX_Hand_Fingers_U->limit_fingers) {
          /* Transition: '<S1>:137' */
          DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fingers_IN_play_finger;

          /* Entry 'play_finger': '<S1>:132' */
          qY = DX_Hand_Fingers_Y->id + 1;
          if ((DX_Hand_Fingers_Y->id > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->id = qY;
          q1 = mul_s32_s32_s32_sat(DX_Hand_Fingers_Y->octave, 5);
          qY = 3 + q1;
          if ((q1 > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->fingers_Output = qY;
          DX_Hand_Fingers_Y->change_O = true;
          DX_Hand_Fingers_DW->control_number = 0;
        } else if (DX_Hand_Fingers_U->pinky_angle >
                   DX_Hand_Fingers_U->limit_fingers) {
          /* Transition: '<S1>:138' */
          DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fingers_IN_play_finger;

          /* Entry 'play_finger': '<S1>:132' */
          qY = DX_Hand_Fingers_Y->id + 1;
          if ((DX_Hand_Fingers_Y->id > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->id = qY;
          q1 = mul_s32_s32_s32_sat(DX_Hand_Fingers_Y->octave, 5);
          qY = 4 + q1;
          if ((q1 > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->fingers_Output = qY;
          DX_Hand_Fingers_Y->change_O = true;
          DX_Hand_Fingers_DW->control_number = 0;
        } else if ((DX_Hand_Fingers_U->hand_velocity >
                    DX_Hand_Fingers_U->limit_hand_velocity) &&
                   (DX_Hand_Fingers_Y->octave < 2) &&
                   (DX_Hand_Fingers_DW->control_number < 1)) {
          /* Transition: '<S1>:143' */
          qY = DX_Hand_Fingers_Y->octave + 1;
          if ((DX_Hand_Fingers_Y->octave > 0) && (qY <= 0)) {
            qY = MAX_int32_T;
          }

          DX_Hand_Fingers_Y->octave = qY;
          DX_Hand_Fingers_DW->control_number = 1;
          DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fingers_IN_up;
        } else {
          if (DX_Hand_Fingers_U->limit_hand_velocity <= MIN_int32_T) {
            qY = MAX_int32_T;
          } else {
            qY = -DX_Hand_Fingers_U->limit_hand_velocity;
          }

          if ((DX_Hand_Fingers_U->hand_velocity < qY) &&
              (DX_Hand_Fingers_Y->octave > 0) &&
              (DX_Hand_Fingers_DW->control_number < 1)) {
            /* Transition: '<S1>:147' */
            qY = DX_Hand_Fingers_Y->octave - 1;
            if ((DX_Hand_Fingers_Y->octave < 0) && (qY >= 0)) {
              qY = MIN_int32_T;
            }

            DX_Hand_Fingers_Y->octave = qY;
            DX_Hand_Fingers_DW->control_number = 1;
            DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fingers_IN_down;
          }
        }
        break;
      }
    }
  } else {
    /* During 'wait_dx_hand': '<S1>:127' */
    if (DX_Hand_Fingers_U->is_dx_hand) {
      /* Transition: '<S1>:133' */
      DX_Hand_Fingers_DW->is_Basic_Logic = DX_Hand_Fingers_IN_playing_mode;
      DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fingers_IN_wait_finger;

      /* Entry 'wait_finger': '<S1>:131' */
      qY = DX_Hand_Fingers_Y->id + 1;
      if ((DX_Hand_Fingers_Y->id > 0) && (qY <= 0)) {
        qY = MAX_int32_T;
      }

      DX_Hand_Fingers_Y->id = qY;
      DX_Hand_Fingers_Y->fingers_Output = -1;
      DX_Hand_Fingers_Y->change_O = true;
    }
  }
}

/* Model step function */
void DX_Hand_Fingers_step(RT_MODEL_DX_Hand_Fingers_Sym *const DX_Hand_Fingers_M,
  ExtU_DX_Hand_Fingers_Sym *DX_Hand_Fingers_U, ExtY_DX_Hand_Fingers_Sym
  *DX_Hand_Fingers_Y)
{
  DW_DX_Hand_Fingers_Sym *DX_Hand_Fingers_DW = ((DW_DX_Hand_Fingers_Sym *)
    DX_Hand_Fingers_M->ModelData.dwork);
  int32_T qY;

  /* Chart: '<Root>/DX_Hand_Fingers ' */
  /* Gateway: DX_Hand_Fingers
   */
  /* During: DX_Hand_Fingers
   */
  if (DX_Hand_Fingers_DW->is_active_c3_DX_Hand_Fingers == 0U) {
    /* Entry: DX_Hand_Fingers
     */
    DX_Hand_Fingers_DW->is_active_c3_DX_Hand_Fingers = 1U;

    /* Entry Internal: DX_Hand_Fingers
     */
    DX_Hand_Fingers_DW->is_active_Basic_Logic = 1U;

    /* Outport: '<Root>/id' */
    /* Entry Internal 'Basic_Logic': '<S1>:123' */
    /* Transition: '<S1>:128' */
    DX_Hand_Fingers_Y->id = 0;

    /* Outport: '<Root>/octave' */
    DX_Hand_Fingers_Y->octave = 0;
    DX_Hand_Fingers_DW->is_Basic_Logic = DX_Hand_Fingers_IN_wait_dx_hand;

    /* Entry 'wait_dx_hand': '<S1>:127' */
    qY = DX_Hand_Fingers_Y->id + 1;
    if ((DX_Hand_Fingers_Y->id > 0) && (qY <= 0)) {
      qY = MAX_int32_T;
    }

    /* Outport: '<Root>/id' */
    DX_Hand_Fingers_Y->id = qY;

    /* Outport: '<Root>/fingers_Output' */
    DX_Hand_Fingers_Y->fingers_Output = -1;

    /* Outport: '<Root>/change_O' */
    DX_Hand_Fingers_Y->change_O = true;
    DX_Hand_Fingers_DW->control_number = 0;
  } else {
    DX_Hand_Fingers_Basic_Logic(DX_Hand_Fingers_U, DX_Hand_Fingers_Y,
      DX_Hand_Fingers_DW);
  }

  /* End of Chart: '<Root>/DX_Hand_Fingers ' */
}

/* Model initialize function */
void DX_Hand_Fingers_initialize(RT_MODEL_DX_Hand_Fingers_Sym *const
  DX_Hand_Fingers_M, ExtU_DX_Hand_Fingers_Sym *DX_Hand_Fingers_U,
  ExtY_DX_Hand_Fingers_Sym *DX_Hand_Fingers_Y)
{
  DW_DX_Hand_Fingers_Sym *DX_Hand_Fingers_DW = ((DW_DX_Hand_Fingers_Sym *)
    DX_Hand_Fingers_M->ModelData.dwork);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)DX_Hand_Fingers_DW, 0,
                sizeof(DW_DX_Hand_Fingers_Sym));

  /* external inputs */
  (void) memset((void *)DX_Hand_Fingers_U, 0,
                sizeof(ExtU_DX_Hand_Fingers_Sym));

  /* external outputs */
  (void) memset((void *)DX_Hand_Fingers_Y, 0,
                sizeof(ExtY_DX_Hand_Fingers_Sym));

  /* InitializeConditions for Chart: '<Root>/DX_Hand_Fingers ' */
  DX_Hand_Fingers_DW->is_active_Basic_Logic = 0U;
  DX_Hand_Fingers_DW->is_Basic_Logic = DX_Hand_Fing_IN_NO_ACTIVE_CHILD;
  DX_Hand_Fingers_DW->is_playing_mode = DX_Hand_Fing_IN_NO_ACTIVE_CHILD;
  DX_Hand_Fingers_DW->is_active_c3_DX_Hand_Fingers = 0U;
}

/* Model terminate function */
void DX_Hand_Fingers_terminate(RT_MODEL_DX_Hand_Fingers_Sym *const
  DX_Hand_Fingers_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(DX_Hand_Fingers_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
