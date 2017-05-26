#ifndef __c3_DX_Hand_h__
#define __c3_DX_Hand_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_DX_HandInstanceStruct
#define typedef_SFc3_DX_HandInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_Basic_Logic;
  uint8_T c3_tp_playing_mode;
  uint8_T c3_tp_down;
  uint8_T c3_tp_up;
  uint8_T c3_tp_wait_finger;
  uint8_T c3_tp_play_finger;
  uint8_T c3_tp_wait_dx_hand;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_DX_Hand;
  uint8_T c3_is_Basic_Logic;
  uint8_T c3_is_active_Basic_Logic;
  uint8_T c3_is_playing_mode;
  int32_T c3_fingers_Local;
  int32_T c3_control_number;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_DX_HandInstanceStruct;

#endif                                 /*typedef_SFc3_DX_HandInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_DX_Hand_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_DX_Hand_get_check_sum(mxArray *plhs[]);
extern void c3_DX_Hand_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
