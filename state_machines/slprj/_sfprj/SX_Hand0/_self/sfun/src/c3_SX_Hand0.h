#ifndef __c3_SX_Hand0_h__
#define __c3_SX_Hand0_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_SX_Hand0InstanceStruct
#define typedef_SFc3_SX_Hand0InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_Chord_change_control;
  uint8_T c3_tp_wait_hand;
  uint8_T c3_tp_wait_for_change;
  uint8_T c3_tp_Alterations_control;
  uint8_T c3_tp_no_alt;
  uint8_T c3_tp_filter_state;
  uint8_T c3_tp_playing_mode;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_SX_Hand0;
  uint8_T c3_is_Chord_change_control;
  uint8_T c3_is_active_Chord_change_control;
  uint8_T c3_is_Alterations_control;
  uint8_T c3_is_active_Alterations_control;
  uint8_T c3_is_playing_mode;
  uint8_T c3_chord_relL;
  int32_T c3_vel_for_volL;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_SX_Hand0InstanceStruct;

#endif                                 /*typedef_SFc3_SX_Hand0InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_SX_Hand0_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_SX_Hand0_get_check_sum(mxArray *plhs[]);
extern void c3_SX_Hand0_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
