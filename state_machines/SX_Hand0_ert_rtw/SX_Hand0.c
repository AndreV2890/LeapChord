/*
 * File: SX_Hand0.c
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

#include "SX_Hand0.h"
#include "SX_Hand0_private.h"

/* Named constants for Chart: '<Root>/SX_Hand' */
#define SX_Hand0_IN_NO_ACTIVE_CHILD    ((uint8_T)0U)
#define SX_Hand0_IN_filter_state       ((uint8_T)1U)
#define SX_Hand0_IN_no_alt             ((uint8_T)1U)
#define SX_Hand0_IN_playing_mode       ((uint8_T)1U)
#define SX_Hand0_IN_wait_for_change    ((uint8_T)2U)
#define SX_Hand0_IN_wait_hand          ((uint8_T)2U)

/* Forward declaration for local functions */
static void SX_Hand0_Chord_change_control(ExternalInputs_SX_Hand0_SymType
  *SX_Hand0_U, ExternalOutputs_SX_Hand_SymType *SX_Hand0_Y,
  D_Work_SX_Hand0_SymType *SX_Hand0_DWork);

/* Function for Chart: '<Root>/SX_Hand' */
static void SX_Hand0_Chord_change_control(ExternalInputs_SX_Hand0_SymType
  *SX_Hand0_U, ExternalOutputs_SX_Hand_SymType *SX_Hand0_Y,
  D_Work_SX_Hand0_SymType *SX_Hand0_DWork)
{
  uint32_T tmp;
  int32_T tmp_0;
  int32_T tmp_1;
  int32_T tmp_2;

  /* During 'Chord_change_control': '<S1>:2' */
  SX_Hand0_Y->changeO = false;
  switch (SX_Hand0_DWork->is_Chord_change_control) {
   case SX_Hand0_IN_playing_mode:
    /* During 'playing_mode': '<S1>:97' */
    if (!SX_Hand0_U->is_sx_hand) {
      /* Transition: '<S1>:84' */
      /* Exit Internal 'playing_mode': '<S1>:97' */
      SX_Hand0_DWork->is_playing_mode = SX_Hand0_IN_NO_ACTIVE_CHILD;
      SX_Hand0_DWork->is_Chord_change_control = SX_Hand0_IN_wait_hand;

      /* Entry 'wait_hand': '<S1>:77' */
      tmp = SX_Hand0_Y->id + 1U;
      if (tmp > 65535U) {
        tmp = 65535U;
      }

      SX_Hand0_Y->id = (uint16_T)tmp;
      SX_Hand0_Y->changeO = true;
      SX_Hand0_Y->chord_relO = 0U;
      SX_Hand0_Y->vel_for_volO = 0;
    } else {
      switch (SX_Hand0_DWork->is_playing_mode) {
       case SX_Hand0_IN_filter_state:
        /* During 'filter_state': '<S1>:96' */
        if (SX_Hand0_U->v_limit <= MIN_int32_T) {
          tmp_0 = MAX_int32_T;
          tmp_1 = MAX_int32_T;
          tmp_2 = MAX_int32_T;
        } else {
          tmp_0 = -SX_Hand0_U->v_limit;
          tmp_1 = -SX_Hand0_U->v_limit;
          tmp_2 = -SX_Hand0_U->v_limit;
        }

        if ((!SX_Hand0_U->up_polso) && (SX_Hand0_U->v_x_polso > tmp_0) &&
            (SX_Hand0_U->v_x_polso < SX_Hand0_U->v_limit) &&
            (SX_Hand0_U->v_y_polso > tmp_1) && (SX_Hand0_U->v_y_polso <
             SX_Hand0_U->v_limit) && (SX_Hand0_U->v_z_polso > tmp_2) &&
            (SX_Hand0_U->v_z_polso < SX_Hand0_U->v_limit)) {
          /* Transition: '<S1>:98' */
          SX_Hand0_DWork->is_playing_mode = SX_Hand0_IN_wait_for_change;
        }
        break;

       case SX_Hand0_IN_wait_for_change:
        /* During 'wait_for_change': '<S1>:82' */
        if (SX_Hand0_U->v_x_polso > SX_Hand0_U->v_limit) {
          /* Transition: '<S1>:87' */
          SX_Hand0_DWork->is_playing_mode = SX_Hand0_IN_filter_state;

          /* Entry 'filter_state': '<S1>:96' */
          SX_Hand0_Y->changeO = true;
          tmp = SX_Hand0_Y->id + 1U;
          if (tmp > 65535U) {
            tmp = 65535U;
          }

          SX_Hand0_Y->id = (uint16_T)tmp;
          SX_Hand0_Y->chord_relO = 1U;
          if (SX_Hand0_U->v_x_polso < 0) {
            if (SX_Hand0_U->v_x_polso <= MIN_int32_T) {
              SX_Hand0_Y->vel_for_volO = MAX_int32_T;
            } else {
              SX_Hand0_Y->vel_for_volO = -SX_Hand0_U->v_x_polso;
            }
          } else {
            SX_Hand0_Y->vel_for_volO = SX_Hand0_U->v_x_polso;
          }
        } else {
          if (SX_Hand0_U->v_limit <= MIN_int32_T) {
            tmp_0 = MAX_int32_T;
          } else {
            tmp_0 = -SX_Hand0_U->v_limit;
          }

          if (SX_Hand0_U->v_x_polso < tmp_0) {
            /* Transition: '<S1>:89' */
            SX_Hand0_DWork->is_playing_mode = SX_Hand0_IN_filter_state;

            /* Entry 'filter_state': '<S1>:96' */
            SX_Hand0_Y->changeO = true;
            tmp = SX_Hand0_Y->id + 1U;
            if (tmp > 65535U) {
              tmp = 65535U;
            }

            SX_Hand0_Y->id = (uint16_T)tmp;
            SX_Hand0_Y->chord_relO = 3U;
            if (SX_Hand0_U->v_x_polso < 0) {
              if (SX_Hand0_U->v_x_polso <= MIN_int32_T) {
                SX_Hand0_Y->vel_for_volO = MAX_int32_T;
              } else {
                SX_Hand0_Y->vel_for_volO = -SX_Hand0_U->v_x_polso;
              }
            } else {
              SX_Hand0_Y->vel_for_volO = SX_Hand0_U->v_x_polso;
            }
          } else if (SX_Hand0_U->v_z_polso > SX_Hand0_U->v_limit) {
            /* Transition: '<S1>:91' */
            SX_Hand0_DWork->is_playing_mode = SX_Hand0_IN_filter_state;

            /* Entry 'filter_state': '<S1>:96' */
            SX_Hand0_Y->changeO = true;
            tmp = SX_Hand0_Y->id + 1U;
            if (tmp > 65535U) {
              tmp = 65535U;
            }

            SX_Hand0_Y->id = (uint16_T)tmp;
            SX_Hand0_Y->chord_relO = 4U;
            if (SX_Hand0_U->v_z_polso < 0) {
              if (SX_Hand0_U->v_z_polso <= MIN_int32_T) {
                SX_Hand0_Y->vel_for_volO = MAX_int32_T;
              } else {
                SX_Hand0_Y->vel_for_volO = -SX_Hand0_U->v_z_polso;
              }
            } else {
              SX_Hand0_Y->vel_for_volO = SX_Hand0_U->v_z_polso;
            }
          } else {
            if (SX_Hand0_U->v_limit <= MIN_int32_T) {
              tmp_0 = MAX_int32_T;
            } else {
              tmp_0 = -SX_Hand0_U->v_limit;
            }

            if (SX_Hand0_U->v_z_polso < tmp_0) {
              /* Transition: '<S1>:92' */
              SX_Hand0_DWork->is_playing_mode = SX_Hand0_IN_filter_state;

              /* Entry 'filter_state': '<S1>:96' */
              SX_Hand0_Y->changeO = true;
              tmp = SX_Hand0_Y->id + 1U;
              if (tmp > 65535U) {
                tmp = 65535U;
              }

              SX_Hand0_Y->id = (uint16_T)tmp;
              SX_Hand0_Y->chord_relO = 2U;
              if (SX_Hand0_U->v_z_polso < 0) {
                if (SX_Hand0_U->v_z_polso <= MIN_int32_T) {
                  SX_Hand0_Y->vel_for_volO = MAX_int32_T;
                } else {
                  SX_Hand0_Y->vel_for_volO = -SX_Hand0_U->v_z_polso;
                }
              } else {
                SX_Hand0_Y->vel_for_volO = SX_Hand0_U->v_z_polso;
              }
            } else if (SX_Hand0_U->v_y_polso > SX_Hand0_U->v_limit) {
              /* Transition: '<S1>:93' */
              SX_Hand0_DWork->is_playing_mode = SX_Hand0_IN_filter_state;

              /* Entry 'filter_state': '<S1>:96' */
              SX_Hand0_Y->changeO = true;
              tmp = SX_Hand0_Y->id + 1U;
              if (tmp > 65535U) {
                tmp = 65535U;
              }

              SX_Hand0_Y->id = (uint16_T)tmp;
              SX_Hand0_Y->chord_relO = 5U;
              if (SX_Hand0_U->v_y_polso < 0) {
                if (SX_Hand0_U->v_y_polso <= MIN_int32_T) {
                  SX_Hand0_Y->vel_for_volO = MAX_int32_T;
                } else {
                  SX_Hand0_Y->vel_for_volO = -SX_Hand0_U->v_y_polso;
                }
              } else {
                SX_Hand0_Y->vel_for_volO = SX_Hand0_U->v_y_polso;
              }
            } else {
              if (SX_Hand0_U->v_limit <= MIN_int32_T) {
                tmp_0 = MAX_int32_T;
              } else {
                tmp_0 = -SX_Hand0_U->v_limit;
              }

              if (SX_Hand0_U->v_y_polso < tmp_0) {
                /* Transition: '<S1>:94' */
                SX_Hand0_DWork->is_playing_mode = SX_Hand0_IN_filter_state;

                /* Entry 'filter_state': '<S1>:96' */
                SX_Hand0_Y->changeO = true;
                tmp = SX_Hand0_Y->id + 1U;
                if (tmp > 65535U) {
                  tmp = 65535U;
                }

                SX_Hand0_Y->id = (uint16_T)tmp;
                SX_Hand0_Y->chord_relO = 6U;
                if (SX_Hand0_U->v_y_polso < 0) {
                  if (SX_Hand0_U->v_y_polso <= MIN_int32_T) {
                    SX_Hand0_Y->vel_for_volO = MAX_int32_T;
                  } else {
                    SX_Hand0_Y->vel_for_volO = -SX_Hand0_U->v_y_polso;
                  }
                } else {
                  SX_Hand0_Y->vel_for_volO = SX_Hand0_U->v_y_polso;
                }
              } else {
                if (SX_Hand0_U->up_polso) {
                  /* Transition: '<S1>:95' */
                  SX_Hand0_DWork->is_playing_mode = SX_Hand0_IN_filter_state;

                  /* Entry 'filter_state': '<S1>:96' */
                  SX_Hand0_Y->changeO = true;
                  tmp = SX_Hand0_Y->id + 1U;
                  if (tmp > 65535U) {
                    tmp = 65535U;
                  }

                  SX_Hand0_Y->id = (uint16_T)tmp;
                  SX_Hand0_Y->chord_relO = 7U;
                  SX_Hand0_Y->vel_for_volO = 500;
                }
              }
            }
          }
        }
        break;

       default:
        SX_Hand0_DWork->is_playing_mode = SX_Hand0_IN_NO_ACTIVE_CHILD;
        break;
      }
    }
    break;

   case SX_Hand0_IN_wait_hand:
    /* During 'wait_hand': '<S1>:77' */
    if (SX_Hand0_U->is_sx_hand) {
      /* Transition: '<S1>:83' */
      SX_Hand0_DWork->is_Chord_change_control = SX_Hand0_IN_playing_mode;
      SX_Hand0_DWork->is_playing_mode = SX_Hand0_IN_wait_for_change;
    }
    break;

   default:
    SX_Hand0_DWork->is_Chord_change_control = SX_Hand0_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Model step function */
void SX_Hand0_step(RT_MODEL_SX_Hand0_SymType *const SX_Hand0_M,
                   ExternalInputs_SX_Hand0_SymType *SX_Hand0_U,
                   ExternalOutputs_SX_Hand_SymType *SX_Hand0_Y)
{
  D_Work_SX_Hand0_SymType *SX_Hand0_DWork = ((D_Work_SX_Hand0_SymType *)
    SX_Hand0_M->ModelData.dwork);
  uint32_T tmp;

  /* Chart: '<Root>/SX_Hand' */
  /* Gateway: SX_Hand */
  /* During: SX_Hand */
  if (SX_Hand0_DWork->is_active_c3_SX_Hand0 == 0U) {
    /* Entry: SX_Hand */
    SX_Hand0_DWork->is_active_c3_SX_Hand0 = 1U;

    /* Entry Internal: SX_Hand */
    SX_Hand0_DWork->is_active_Chord_change_control = 1U;

    /* Outport: '<Root>/id' */
    /* Entry Internal 'Chord_change_control': '<S1>:2' */
    /* Transition: '<S1>:81' */
    SX_Hand0_Y->id = 0U;
    if (SX_Hand0_DWork->is_Chord_change_control != SX_Hand0_IN_wait_hand) {
      SX_Hand0_DWork->is_Chord_change_control = SX_Hand0_IN_wait_hand;

      /* Entry 'wait_hand': '<S1>:77' */
      tmp = SX_Hand0_Y->id + 1U;
      if (tmp > 65535U) {
        tmp = 65535U;
      }

      /* Outport: '<Root>/id' */
      SX_Hand0_Y->id = (uint16_T)tmp;

      /* Outport: '<Root>/changeO' */
      SX_Hand0_Y->changeO = true;

      /* Outport: '<Root>/chord_relO' */
      SX_Hand0_Y->chord_relO = 0U;

      /* Outport: '<Root>/vel_for_volO' */
      SX_Hand0_Y->vel_for_volO = 0;
    }

    SX_Hand0_DWork->is_active_Alterations_control = 1U;

    /* Entry Internal 'Alterations_control': '<S1>:1' */
    /* Transition: '<S1>:24' */
    if (SX_Hand0_DWork->is_Alterations_control != SX_Hand0_IN_no_alt) {
      SX_Hand0_DWork->is_Alterations_control = SX_Hand0_IN_no_alt;

      /* Outport: '<Root>/chord_altO' */
      /* Entry 'no_alt': '<S1>:21' */
      SX_Hand0_Y->chord_altO = 0U;
    }
  } else {
    if (SX_Hand0_DWork->is_active_Chord_change_control != 0U) {
      SX_Hand0_Chord_change_control(SX_Hand0_U, SX_Hand0_Y, SX_Hand0_DWork);
    }
  }

  /* End of Chart: '<Root>/SX_Hand' */
}

/* Model initialize function */
void SX_Hand0_initialize(RT_MODEL_SX_Hand0_SymType *const SX_Hand0_M,
  ExternalInputs_SX_Hand0_SymType *SX_Hand0_U, ExternalOutputs_SX_Hand_SymType
  *SX_Hand0_Y)
{
  D_Work_SX_Hand0_SymType *SX_Hand0_DWork = ((D_Work_SX_Hand0_SymType *)
    SX_Hand0_M->ModelData.dwork);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)SX_Hand0_DWork, 0,
                sizeof(D_Work_SX_Hand0_SymType));

  /* external inputs */
  (void) memset((void *)SX_Hand0_U, 0,
                sizeof(ExternalInputs_SX_Hand0_SymType));

  /* external outputs */
  (void) memset((void *)SX_Hand0_Y, 0,
                sizeof(ExternalOutputs_SX_Hand_SymType));

  /* InitializeConditions for Chart: '<Root>/SX_Hand' */
  SX_Hand0_DWork->is_active_Alterations_control = 0U;
  SX_Hand0_DWork->is_Alterations_control = SX_Hand0_IN_NO_ACTIVE_CHILD;
  SX_Hand0_DWork->is_active_Chord_change_control = 0U;
  SX_Hand0_DWork->is_Chord_change_control = SX_Hand0_IN_NO_ACTIVE_CHILD;
  SX_Hand0_DWork->is_playing_mode = SX_Hand0_IN_NO_ACTIVE_CHILD;
  SX_Hand0_DWork->is_active_c3_SX_Hand0 = 0U;
}

/* Model terminate function */
void SX_Hand0_terminate(RT_MODEL_SX_Hand0_SymType *const SX_Hand0_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(SX_Hand0_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
