/* Include files */

#include <stddef.h>
#include "blas.h"
#include "SX_Hand0_sfun.h"
#include "c3_SX_Hand0.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SX_Hand0_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c3_event_tick                  (0)
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_playing_mode             ((uint8_T)1U)
#define c3_IN_wait_hand                ((uint8_T)2U)
#define c3_IN_no_alt                   ((uint8_T)1U)
#define c3_IN_filter_state             ((uint8_T)1U)
#define c3_IN_wait_for_change          ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_t_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_v_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_x_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ab_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_cb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_eb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c3_dataWrittenToVector[7];

/* Function Declarations */
static void initialize_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance);
static void initialize_params_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct
  *chartInstance);
static void enable_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance);
static void disable_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct
  *chartInstance);
static void set_sim_state_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_SX_Hand0
  (SFc3_SX_Hand0InstanceStruct *chartInstance);
static void finalize_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance);
static void sf_gateway_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance);
static void initSimStructsc3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance);
static void c3_Chord_change_control(SFc3_SX_Hand0InstanceStruct *chartInstance);
static void c3_enter_atomic_wait_hand(SFc3_SX_Hand0InstanceStruct *chartInstance);
static void c3_wait_for_change(SFc3_SX_Hand0InstanceStruct *chartInstance);
static void c3_enter_atomic_filter_state(SFc3_SX_Hand0InstanceStruct
  *chartInstance);
static void c3_exit_internal_playing_mode(SFc3_SX_Hand0InstanceStruct
  *chartInstance);
static int32_T c3_abs(SFc3_SX_Hand0InstanceStruct *chartInstance, int32_T c3_x);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_b_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct
  *chartInstance, const mxArray *c3_sf_internal_predicateOutput, const char_T
  *c3_identifier);
static boolean_T c3_c_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_b_sfEvent, const char_T *c3_identifier);
static int32_T c3_e_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_b_tp_Chord_change_control, const char_T *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint16_T c3_h_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_id, const char_T *c3_identifier);
static uint16_T c3_i_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_j_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_k_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector(SFc3_SX_Hand0InstanceStruct
  *chartInstance, uint32_T c3_vectorIndex);
static void c3_errorIfDataNotWrittenToFcn(SFc3_SX_Hand0InstanceStruct
  *chartInstance, uint32_T c3_vectorIndex, uint32_T c3_dataNumber);
static void init_dsm_address_info(SFc3_SX_Hand0InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_is_active_Alterations_control = 0U;
  chartInstance->c3_is_Alterations_control = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_Alterations_control = 0U;
  chartInstance->c3_tp_no_alt = 0U;
  chartInstance->c3_is_active_Chord_change_control = 0U;
  chartInstance->c3_is_Chord_change_control = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_Chord_change_control = 0U;
  chartInstance->c3_is_playing_mode = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_playing_mode = 0U;
  chartInstance->c3_tp_filter_state = 0U;
  chartInstance->c3_tp_wait_for_change = 0U;
  chartInstance->c3_tp_wait_hand = 0U;
  chartInstance->c3_is_active_c3_SX_Hand0 = 0U;
}

static void initialize_params_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct
  *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_SX_Hand0 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_Chord_change_control == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_Chord_change_control == c3_IN_wait_hand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_playing_mode == c3_IN_wait_for_change) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_Alterations_control == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_Alterations_control == c3_IN_no_alt) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_playing_mode == c3_IN_filter_state) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_Chord_change_control == c3_IN_playing_mode) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  boolean_T c3_hoistedGlobal;
  boolean_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint16_T c3_d_hoistedGlobal;
  uint16_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  int32_T c3_e_hoistedGlobal;
  int32_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  int32_T c3_g_hoistedGlobal;
  int32_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  uint8_T c3_h_hoistedGlobal;
  uint8_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  uint8_T c3_i_hoistedGlobal;
  uint8_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  uint8_T c3_j_hoistedGlobal;
  uint8_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  uint8_T c3_k_hoistedGlobal;
  uint8_T c3_k_u;
  const mxArray *c3_l_y = NULL;
  uint8_T c3_l_hoistedGlobal;
  uint8_T c3_l_u;
  const mxArray *c3_m_y = NULL;
  uint8_T c3_m_hoistedGlobal;
  uint8_T c3_m_u;
  const mxArray *c3_n_y = NULL;
  boolean_T *c3_changeO;
  uint8_T *c3_chord_altO;
  uint8_T *c3_chord_relO;
  uint16_T *c3_id;
  int32_T *c3_vel_for_volO;
  c3_vel_for_volO = (int32_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_changeO = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_chord_altO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_chord_relO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_id = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(13, 1), false);
  c3_hoistedGlobal = *c3_changeO;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_chord_altO;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_chord_relO;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_id;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *c3_vel_for_volO;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = chartInstance->c3_chord_relL;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = chartInstance->c3_vel_for_volL;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = chartInstance->c3_is_active_c3_SX_Hand0;
  c3_h_u = c3_h_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_i_hoistedGlobal = chartInstance->c3_is_active_Alterations_control;
  c3_i_u = c3_i_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_j_hoistedGlobal = chartInstance->c3_is_active_Chord_change_control;
  c3_j_u = c3_j_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_k_hoistedGlobal = chartInstance->c3_is_Alterations_control;
  c3_k_u = c3_k_hoistedGlobal;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_l_hoistedGlobal = chartInstance->c3_is_Chord_change_control;
  c3_l_u = c3_l_hoistedGlobal;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 11, c3_m_y);
  c3_m_hoistedGlobal = chartInstance->c3_is_playing_mode;
  c3_m_u = c3_m_hoistedGlobal;
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 12, c3_n_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  boolean_T *c3_changeO;
  uint8_T *c3_chord_altO;
  uint8_T *c3_chord_relO;
  uint16_T *c3_id;
  int32_T *c3_vel_for_volO;
  c3_vel_for_volO = (int32_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_changeO = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_chord_altO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_chord_relO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_id = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_u = sf_mex_dup(c3_st);
  *c3_changeO = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 0)), "changeO");
  *c3_chord_altO = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "chord_altO");
  *c3_chord_relO = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "chord_relO");
  *c3_id = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    3)), "id");
  *c3_vel_for_volO = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 4)), "vel_for_volO");
  chartInstance->c3_chord_relL = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 5)), "chord_relL");
  chartInstance->c3_vel_for_volL = c3_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 6)), "vel_for_volL");
  chartInstance->c3_is_active_c3_SX_Hand0 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 7)), "is_active_c3_SX_Hand0");
  chartInstance->c3_is_active_Alterations_control = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 8)),
     "is_active_Alterations_control");
  chartInstance->c3_is_active_Chord_change_control = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 9)),
     "is_active_Chord_change_control");
  chartInstance->c3_is_Alterations_control = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 10)), "is_Alterations_control");
  chartInstance->c3_is_Chord_change_control = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 11)),
     "is_Chord_change_control");
  chartInstance->c3_is_playing_mode = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 12)), "is_playing_mode");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 13)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_SX_Hand0(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_SX_Hand0
  (SFc3_SX_Hand0InstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_active_Chord_change_control == 1U) {
      chartInstance->c3_tp_Chord_change_control = 1U;
    } else {
      chartInstance->c3_tp_Chord_change_control = 0U;
    }

    if (chartInstance->c3_is_Chord_change_control == c3_IN_playing_mode) {
      chartInstance->c3_tp_playing_mode = 1U;
    } else {
      chartInstance->c3_tp_playing_mode = 0U;
    }

    if (chartInstance->c3_is_playing_mode == c3_IN_filter_state) {
      chartInstance->c3_tp_filter_state = 1U;
    } else {
      chartInstance->c3_tp_filter_state = 0U;
    }

    if (chartInstance->c3_is_playing_mode == c3_IN_wait_for_change) {
      chartInstance->c3_tp_wait_for_change = 1U;
    } else {
      chartInstance->c3_tp_wait_for_change = 0U;
    }

    if (chartInstance->c3_is_Chord_change_control == c3_IN_wait_hand) {
      chartInstance->c3_tp_wait_hand = 1U;
    } else {
      chartInstance->c3_tp_wait_hand = 0U;
    }

    if (chartInstance->c3_is_active_Alterations_control == 1U) {
      chartInstance->c3_tp_Alterations_control = 1U;
    } else {
      chartInstance->c3_tp_Alterations_control = 0U;
    }

    if (chartInstance->c3_is_Alterations_control == c3_IN_no_alt) {
      chartInstance->c3_tp_no_alt = 1U;
    } else {
      chartInstance->c3_tp_no_alt = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  uint16_T *c3_id;
  uint8_T *c3_chord_relO;
  uint8_T *c3_chord_altO;
  int32_T *c3_v_x_polso;
  int32_T *c3_v_y_polso;
  int32_T *c3_v_z_polso;
  boolean_T *c3_up_polso;
  boolean_T *c3_changeO;
  boolean_T *c3_is_sx_hand;
  int32_T *c3_v_limit;
  int32_T *c3_vel_for_volO;
  c3_vel_for_volO = (int32_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_v_limit = (int32_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_is_sx_hand = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_changeO = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_up_polso = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_v_z_polso = (int32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_v_y_polso = (int32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_v_x_polso = (int32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_chord_altO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_chord_relO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_id = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_set_sim_state_side_effects_c3_SX_Hand0(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_id, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_chord_relO, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_chord_altO, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_v_x_polso, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_v_y_polso, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_v_z_polso, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_up_polso, 6U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_changeO, 7U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_is_sx_hand, 8U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_v_limit, 9U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_chord_relL, 10U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_vel_for_volO, 11U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_vel_for_volL, 12U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_SX_Hand0 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_SX_Hand0 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_Chord_change_control = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_Chord_change_control = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_n_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *c3_id = 0U;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK((real_T)*c3_id, 0U);
    _SFD_SYMBOL_SCOPE_POP();
    if (chartInstance->c3_is_Chord_change_control == c3_IN_wait_hand) {
    } else {
      chartInstance->c3_is_Chord_change_control = c3_IN_wait_hand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_wait_hand = 1U;
      c3_enter_atomic_wait_hand(chartInstance);
    }

    chartInstance->c3_is_active_Alterations_control = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_Alterations_control = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    if (chartInstance->c3_is_Alterations_control == c3_IN_no_alt) {
    } else {
      chartInstance->c3_is_Alterations_control = c3_IN_no_alt;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_no_alt = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *c3_chord_altO = 0U;
      c3_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK((real_T)*c3_chord_altO, 2U);
      _SFD_SYMBOL_SCOPE_POP();
    }
  } else {
    if (chartInstance->c3_is_active_Chord_change_control == 0U) {
    } else {
      c3_Chord_change_control(chartInstance);
    }

    if (chartInstance->c3_is_active_Alterations_control == 0U) {
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c3_sfEvent);
      if (chartInstance->c3_is_Alterations_control != c3_IN_no_alt) {
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c3_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_SX_Hand0MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_SX_Hand0(SFc3_SX_Hand0InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_Chord_change_control(SFc3_SX_Hand0InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  int32_T c3_i0;
  int32_T c3_saturatedUnaryMinus;
  int32_T c3_i1;
  int32_T c3_b_saturatedUnaryMinus;
  int32_T c3_i2;
  int32_T c3_c_saturatedUnaryMinus;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_c_out;
  boolean_T *c3_changeO;
  boolean_T *c3_is_sx_hand;
  boolean_T *c3_up_polso;
  int32_T *c3_v_x_polso;
  int32_T *c3_v_limit;
  int32_T *c3_v_y_polso;
  int32_T *c3_v_z_polso;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  c3_v_limit = (int32_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_is_sx_hand = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_changeO = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_up_polso = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_v_z_polso = (int32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_v_y_polso = (int32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_v_x_polso = (int32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *c3_changeO = false;
  c3_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_changeO, 7U);
  _SFD_SYMBOL_SCOPE_POP();
  switch (chartInstance->c3_is_Chord_change_control) {
   case c3_IN_playing_mode:
    CV_STATE_EVAL(2, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_out = CV_EML_IF(3, 0, 0, !*c3_is_sx_hand);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      c3_exit_internal_playing_mode(chartInstance);
      chartInstance->c3_tp_playing_mode = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_Chord_change_control = c3_IN_wait_hand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_wait_hand = 1U;
      c3_enter_atomic_wait_hand(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c3_sfEvent);
      switch (chartInstance->c3_is_playing_mode) {
       case c3_IN_filter_state:
        CV_STATE_EVAL(3, 0, 1);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        guard1 = false;
        guard2 = false;
        guard3 = false;
        guard4 = false;
        guard5 = false;
        guard6 = false;
        if (CV_EML_COND(11, 0, 0, !*c3_up_polso)) {
          c3_i0 = *c3_v_limit;
          if (CV_SATURATION_EVAL(5, 11, 1, 0, c3_i0 <= MIN_int32_T)) {
            c3_saturatedUnaryMinus = MAX_int32_T;
          } else {
            c3_saturatedUnaryMinus = -c3_i0;
          }

          if (CV_EML_COND(11, 0, 1, *c3_v_x_polso > c3_saturatedUnaryMinus)) {
            if (CV_EML_COND(11, 0, 2, *c3_v_x_polso < *c3_v_limit)) {
              c3_i1 = *c3_v_limit;
              if (CV_SATURATION_EVAL(5, 11, 2, 0, c3_i1 <= MIN_int32_T)) {
                c3_b_saturatedUnaryMinus = MAX_int32_T;
              } else {
                c3_b_saturatedUnaryMinus = -c3_i1;
              }

              if (CV_EML_COND(11, 0, 3, *c3_v_y_polso > c3_b_saturatedUnaryMinus))
              {
                if (CV_EML_COND(11, 0, 4, *c3_v_y_polso < *c3_v_limit)) {
                  c3_i2 = *c3_v_limit;
                  if (CV_SATURATION_EVAL(5, 11, 0, 0, c3_i2 <= MIN_int32_T)) {
                    c3_c_saturatedUnaryMinus = MAX_int32_T;
                  } else {
                    c3_c_saturatedUnaryMinus = -c3_i2;
                  }

                  if (CV_EML_COND(11, 0, 5, *c3_v_z_polso >
                                  c3_c_saturatedUnaryMinus)) {
                    if (CV_EML_COND(11, 0, 6, *c3_v_z_polso < *c3_v_limit)) {
                      CV_EML_MCDC(11, 0, 0, true);
                      CV_EML_IF(11, 0, 0, true);
                      c3_b_out = true;
                    } else {
                      guard1 = true;
                    }
                  } else {
                    guard2 = true;
                  }
                } else {
                  guard3 = true;
                }
              } else {
                guard4 = true;
              }
            } else {
              guard5 = true;
            }
          } else {
            guard6 = true;
          }
        } else {
          guard6 = true;
        }

        if (guard6 == true) {
          guard5 = true;
        }

        if (guard5 == true) {
          guard4 = true;
        }

        if (guard4 == true) {
          guard3 = true;
        }

        if (guard3 == true) {
          guard2 = true;
        }

        if (guard2 == true) {
          guard1 = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(11, 0, 0, false);
          CV_EML_IF(11, 0, 0, false);
          c3_b_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c3_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_filter_state = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_playing_mode = c3_IN_wait_for_change;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_wait_for_change = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                       chartInstance->c3_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
        break;

       case c3_IN_wait_for_change:
        CV_STATE_EVAL(3, 0, 2);
        c3_wait_for_change(chartInstance);
        break;

       default:
        CV_STATE_EVAL(3, 0, 0);
        chartInstance->c3_is_playing_mode = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        break;
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_wait_hand:
    CV_STATE_EVAL(2, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_c_out = CV_EML_IF(2, 0, 0, *c3_is_sx_hand);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_wait_hand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_Chord_change_control = c3_IN_playing_mode;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_playing_mode = 1U;
      chartInstance->c3_is_playing_mode = c3_IN_wait_for_change;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_wait_for_change = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(2, 0, 0);
    chartInstance->c3_is_Chord_change_control = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_wait_hand(SFc3_SX_Hand0InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_u0;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  uint16_T *c3_id;
  boolean_T *c3_changeO;
  uint8_T *c3_chord_relO;
  int32_T *c3_vel_for_volO;
  c3_vel_for_volO = (int32_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_changeO = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_chord_relO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_id = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
  c3_u0 = (uint32_T)*c3_id + 1U;
  if (CV_SATURATION_EVAL(4, 6, 0, 0, c3_u0 > 65535U)) {
    c3_u0 = 65535U;
  }

  *c3_id = (uint16_T)c3_u0;
  c3_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_id, 0U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *c3_changeO = true;
  c3_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_changeO, 7U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *c3_chord_relO = 0U;
  c3_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_chord_relO, 1U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  chartInstance->c3_chord_relL = 0U;
  c3_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_chord_relL, 10U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  chartInstance->c3_vel_for_volL = 0;
  c3_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_vel_for_volL, 12U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *c3_vel_for_volO = 0;
  c3_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_vel_for_volO, 11U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_wait_for_change(SFc3_SX_Hand0InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  int32_T c3_i3;
  int32_T c3_saturatedUnaryMinus;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_d_out;
  int32_T c3_i4;
  int32_T c3_b_saturatedUnaryMinus;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 1.0;
  boolean_T c3_e_out;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 0.0;
  real_T c3_k_nargin = 0.0;
  real_T c3_k_nargout = 1.0;
  boolean_T c3_f_out;
  int32_T c3_i5;
  int32_T c3_c_saturatedUnaryMinus;
  real_T c3_l_nargin = 0.0;
  real_T c3_l_nargout = 0.0;
  int32_T c3_hoistedGlobal;
  int32_T c3_x;
  int32_T c3_b_x;
  int32_T c3_i6;
  int32_T c3_d_saturatedUnaryMinus;
  real_T c3_m_nargin = 0.0;
  real_T c3_m_nargout = 1.0;
  boolean_T c3_g_out;
  real_T c3_n_nargin = 0.0;
  real_T c3_n_nargout = 0.0;
  int32_T *c3_v_x_polso;
  int32_T *c3_v_limit;
  int32_T *c3_v_z_polso;
  int32_T *c3_v_y_polso;
  boolean_T *c3_up_polso;
  c3_v_limit = (int32_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_up_polso = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_v_z_polso = (int32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_v_y_polso = (int32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_v_x_polso = (int32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_s_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  c3_out = CV_EML_IF(4, 0, 0, *c3_v_x_polso > *c3_v_limit);
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_wait_for_change = 0U;
    chartInstance->c3_is_playing_mode = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_t_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    chartInstance->c3_chord_relL = 1U;
    c3_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_chord_relL, 10U);
    chartInstance->c3_vel_for_volL = c3_abs(chartInstance, *c3_v_x_polso);
    c3_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_vel_for_volL, 12U);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c3_is_playing_mode = c3_IN_filter_state;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_filter_state = 1U;
    c3_enter_atomic_filter_state(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_q_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_i3 = *c3_v_limit;
    if (CV_SATURATION_EVAL(5, 5, 0, 0, c3_i3 <= MIN_int32_T)) {
      c3_saturatedUnaryMinus = MAX_int32_T;
    } else {
      c3_saturatedUnaryMinus = -c3_i3;
    }

    c3_b_out = CV_EML_IF(5, 0, 0, *c3_v_x_polso < c3_saturatedUnaryMinus);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_wait_for_change = 0U;
      chartInstance->c3_is_playing_mode = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_r_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      chartInstance->c3_chord_relL = 3U;
      c3_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_chord_relL, 10U);
      chartInstance->c3_vel_for_volL = c3_abs(chartInstance, *c3_v_x_polso);
      c3_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_vel_for_volL, 12U);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c3_is_playing_mode = c3_IN_filter_state;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_filter_state = 1U;
      c3_enter_atomic_filter_state(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_db_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_c_out = CV_EML_IF(6, 0, 0, *c3_v_z_polso > *c3_v_limit);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_wait_for_change = 0U;
        chartInstance->c3_is_playing_mode = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_eb_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        chartInstance->c3_chord_relL = 4U;
        c3_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_chord_relL, 10U);
        chartInstance->c3_vel_for_volL = c3_abs(chartInstance, *c3_v_z_polso);
        c3_updateDataWrittenToVector(chartInstance, 6U);
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_vel_for_volL, 12U);
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c3_is_playing_mode = c3_IN_filter_state;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_filter_state = 1U;
        c3_enter_atomic_filter_state(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_y_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_i4 = *c3_v_limit;
        if (CV_SATURATION_EVAL(5, 7, 0, 0, c3_i4 <= MIN_int32_T)) {
          c3_b_saturatedUnaryMinus = MAX_int32_T;
        } else {
          c3_b_saturatedUnaryMinus = -c3_i4;
        }

        c3_d_out = CV_EML_IF(7, 0, 0, *c3_v_z_polso < c3_b_saturatedUnaryMinus);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_wait_for_change = 0U;
          chartInstance->c3_is_playing_mode = c3_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ab_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          chartInstance->c3_chord_relL = 2U;
          c3_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_chord_relL, 10U);
          chartInstance->c3_vel_for_volL = c3_abs(chartInstance, *c3_v_z_polso);
          c3_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_vel_for_volL, 12U);
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c3_is_playing_mode = c3_IN_filter_state;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_filter_state = 1U;
          c3_enter_atomic_filter_state(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_bb_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          c3_e_out = CV_EML_IF(8, 0, 0, *c3_v_y_polso > *c3_v_limit);
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_wait_for_change = 0U;
            chartInstance->c3_is_playing_mode = c3_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_cb_debug_family_names,
              c3_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            chartInstance->c3_chord_relL = 5U;
            c3_updateDataWrittenToVector(chartInstance, 4U);
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_chord_relL, 10U);
            chartInstance->c3_vel_for_volL = c3_abs(chartInstance, *c3_v_y_polso);
            c3_updateDataWrittenToVector(chartInstance, 6U);
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_vel_for_volL, 12U);
            _SFD_SYMBOL_SCOPE_POP();
            chartInstance->c3_is_playing_mode = c3_IN_filter_state;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_filter_state = 1U;
            c3_enter_atomic_filter_state(chartInstance);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                         chartInstance->c3_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_u_debug_family_names,
              c3_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U,
              c3_b_sf_marshallOut, c3_b_sf_marshallIn);
            c3_i5 = *c3_v_limit;
            if (CV_SATURATION_EVAL(5, 9, 0, 0, c3_i5 <= MIN_int32_T)) {
              c3_c_saturatedUnaryMinus = MAX_int32_T;
            } else {
              c3_c_saturatedUnaryMinus = -c3_i5;
            }

            c3_f_out = CV_EML_IF(9, 0, 0, *c3_v_y_polso <
                                 c3_c_saturatedUnaryMinus);
            _SFD_SYMBOL_SCOPE_POP();
            if (c3_f_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_wait_for_change = 0U;
              chartInstance->c3_is_playing_mode = c3_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_v_debug_family_names,
                c3_b_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U,
                c3_sf_marshallOut, c3_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U,
                c3_sf_marshallOut, c3_sf_marshallIn);
              chartInstance->c3_chord_relL = 6U;
              c3_updateDataWrittenToVector(chartInstance, 4U);
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_chord_relL, 10U);
              c3_hoistedGlobal = *c3_v_y_polso;
              c3_x = c3_hoistedGlobal;
              c3_b_x = c3_x;
              c3_i6 = c3_b_x;
              if (CV_SATURATION_EVAL(5, 9, 1, 0, c3_i6 <= MIN_int32_T)) {
                c3_d_saturatedUnaryMinus = MAX_int32_T;
              } else {
                c3_d_saturatedUnaryMinus = -c3_i6;
              }

              if ((real_T)c3_b_x < 0.0) {
                chartInstance->c3_vel_for_volL = c3_d_saturatedUnaryMinus;
              } else {
                chartInstance->c3_vel_for_volL = c3_b_x;
              }

              c3_updateDataWrittenToVector(chartInstance, 6U);
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_vel_for_volL, 12U);
              _SFD_SYMBOL_SCOPE_POP();
              chartInstance->c3_is_playing_mode = c3_IN_filter_state;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_filter_state = 1U;
              c3_enter_atomic_filter_state(chartInstance);
            } else {
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                           chartInstance->c3_sfEvent);
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_w_debug_family_names,
                c3_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargin, 0U,
                c3_sf_marshallOut, c3_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargout, 1U,
                c3_sf_marshallOut, c3_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U,
                c3_b_sf_marshallOut, c3_b_sf_marshallIn);
              c3_g_out = CV_EML_IF(10, 0, 0, *c3_up_polso);
              _SFD_SYMBOL_SCOPE_POP();
              if (c3_g_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U,
                             chartInstance->c3_sfEvent);
                chartInstance->c3_tp_wait_for_change = 0U;
                chartInstance->c3_is_playing_mode = c3_IN_NO_ACTIVE_CHILD;
                _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
                _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_x_debug_family_names,
                  c3_b_debug_family_var_map);
                _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargin, 0U,
                  c3_sf_marshallOut, c3_sf_marshallIn);
                _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargout, 1U,
                  c3_sf_marshallOut, c3_sf_marshallIn);
                chartInstance->c3_chord_relL = 7U;
                c3_updateDataWrittenToVector(chartInstance, 4U);
                _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_chord_relL, 10U);
                chartInstance->c3_vel_for_volL = 500;
                c3_updateDataWrittenToVector(chartInstance, 6U);
                _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_vel_for_volL,
                                      12U);
                _SFD_SYMBOL_SCOPE_POP();
                chartInstance->c3_is_playing_mode = c3_IN_filter_state;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
                chartInstance->c3_tp_filter_state = 1U;
                c3_enter_atomic_filter_state(chartInstance);
              } else {
                _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                             chartInstance->c3_sfEvent);
              }
            }
          }
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_filter_state(SFc3_SX_Hand0InstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  uint32_T c3_u1;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T *c3_changeO;
  uint16_T *c3_id;
  uint8_T *c3_chord_relO;
  int32_T *c3_vel_for_volO;
  c3_vel_for_volO = (int32_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_changeO = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_chord_relO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_id = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *c3_changeO = true;
  c3_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_changeO, 7U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
  c3_u1 = (uint32_T)*c3_id + 1U;
  if (CV_SATURATION_EVAL(4, 4, 0, 0, c3_u1 > 65535U)) {
    c3_u1 = 65535U;
  }

  *c3_id = (uint16_T)c3_u1;
  c3_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_id, 0U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_k_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 10U);
  *c3_chord_relO = chartInstance->c3_chord_relL;
  c3_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_chord_relO, 1U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 12U);
  *c3_vel_for_volO = chartInstance->c3_vel_for_volL;
  c3_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_vel_for_volO, 11U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_exit_internal_playing_mode(SFc3_SX_Hand0InstanceStruct
  *chartInstance)
{
  switch (chartInstance->c3_is_playing_mode) {
   case c3_IN_filter_state:
    CV_STATE_EVAL(3, 1, 1);
    chartInstance->c3_tp_filter_state = 0U;
    chartInstance->c3_is_playing_mode = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_wait_for_change:
    CV_STATE_EVAL(3, 1, 2);
    chartInstance->c3_tp_wait_for_change = 0U;
    chartInstance->c3_is_playing_mode = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(3, 1, 0);
    chartInstance->c3_is_playing_mode = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    break;
  }
}

static int32_T c3_abs(SFc3_SX_Hand0InstanceStruct *chartInstance, int32_T c3_x)
{
  int32_T c3_y;
  int32_T c3_b_x;
  int32_T c3_i7;
  int32_T c3_saturatedUnaryMinus;
  (void)chartInstance;
  c3_b_x = c3_x;
  c3_i7 = c3_b_x;
  if (c3_i7 <= MIN_int32_T) {
    c3_saturatedUnaryMinus = MAX_int32_T;
  } else {
    c3_saturatedUnaryMinus = -c3_i7;
  }

  if ((real_T)c3_b_x < 0.0) {
    c3_y = c3_saturatedUnaryMinus;
  } else {
    c3_y = c3_b_x;
  }

  return c3_y;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_SX_Hand0InstanceStruct *chartInstance;
  chartInstance = (SFc3_SX_Hand0InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_SX_Hand0InstanceStruct *chartInstance;
  chartInstance = (SFc3_SX_Hand0InstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_SX_Hand0InstanceStruct *chartInstance;
  chartInstance = (SFc3_SX_Hand0InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_b_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct
  *chartInstance, const mxArray *c3_sf_internal_predicateOutput, const char_T
  *c3_identifier)
{
  boolean_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  return c3_y;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_SX_Hand0InstanceStruct *chartInstance;
  chartInstance = (SFc3_SX_Hand0InstanceStruct *)chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_SX_Hand0_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("abs"), "name", "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_SX_Hand0InstanceStruct *chartInstance;
  chartInstance = (SFc3_SX_Hand0InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_b_sfEvent, const char_T *c3_identifier)
{
  int32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  return c3_y;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i8;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i8, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i8;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_SX_Hand0InstanceStruct *chartInstance;
  chartInstance = (SFc3_SX_Hand0InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_SX_Hand0InstanceStruct *chartInstance;
  chartInstance = (SFc3_SX_Hand0InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_b_tp_Chord_change_control, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_tp_Chord_change_control), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_Chord_change_control);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u2, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_Chord_change_control;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_SX_Hand0InstanceStruct *chartInstance;
  chartInstance = (SFc3_SX_Hand0InstanceStruct *)chartInstanceVoid;
  c3_b_tp_Chord_change_control = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_tp_Chord_change_control), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_Chord_change_control);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint16_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_SX_Hand0InstanceStruct *chartInstance;
  chartInstance = (SFc3_SX_Hand0InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint16_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint16_T c3_h_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_id, const char_T *c3_identifier)
{
  uint16_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_id), &c3_thisId);
  sf_mex_destroy(&c3_id);
  return c3_y;
}

static uint16_T c3_i_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint16_T c3_y;
  uint16_T c3_u3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u3, 1, 5, 0U, 0, 0U, 0);
  c3_y = c3_u3;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_id;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint16_T c3_y;
  SFc3_SX_Hand0InstanceStruct *chartInstance;
  chartInstance = (SFc3_SX_Hand0InstanceStruct *)chartInstanceVoid;
  c3_id = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_id), &c3_thisId);
  sf_mex_destroy(&c3_id);
  *(uint16_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_j_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_k_emlrt_marshallIn(SFc3_SX_Hand0InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_updateDataWrittenToVector(SFc3_SX_Hand0InstanceStruct
  *chartInstance, uint32_T c3_vectorIndex)
{
  (void)chartInstance;
  c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c3_vectorIndex, 0, 6, 1, 0)] = true;
}

static void c3_errorIfDataNotWrittenToFcn(SFc3_SX_Hand0InstanceStruct
  *chartInstance, uint32_T c3_vectorIndex, uint32_T c3_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c3_dataNumber, c3_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c3_vectorIndex, 0, 6, 1,
    0)]);
}

static void init_dsm_address_info(SFc3_SX_Hand0InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_SX_Hand0_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3845478493U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3580835403U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2237809666U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2529231985U);
}

mxArray *sf_c3_SX_Hand0_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("LTzmfkxrAXtq4T3TIcqklC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_SX_Hand0_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_SX_Hand0_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_SX_Hand0(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[75],T\"changeO\",},{M[1],M[20],T\"chord_altO\",},{M[1],M[19],T\"chord_relO\",},{M[1],M[18],T\"id\",},{M[1],M[100],T\"vel_for_volO\",},{M[3],M[99],T\"chord_relL\",},{M[3],M[101],T\"vel_for_volL\",},{M[8],M[0],T\"is_active_c3_SX_Hand0\",},{M[8],M[1],T\"is_active_Alterations_control\",},{M[8],M[2],T\"is_active_Chord_change_control\",}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[9],M[1],T\"is_Alterations_control\",},{M[9],M[2],T\"is_Chord_change_control\",},{M[9],M[97],T\"is_playing_mode\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 13, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_SX_Hand0_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_SX_Hand0InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_SX_Hand0InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _SX_Hand0MachineNumber_,
           3,
           7,
           12,
           0,
           13,
           1,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_SX_Hand0MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_SX_Hand0MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _SX_Hand0MachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,2,0,1,"id");
          _SFD_SET_DATA_PROPS(1,2,0,1,"chord_relO");
          _SFD_SET_DATA_PROPS(2,2,0,1,"chord_altO");
          _SFD_SET_DATA_PROPS(3,1,1,0,"v_x_polso");
          _SFD_SET_DATA_PROPS(4,1,1,0,"v_y_polso");
          _SFD_SET_DATA_PROPS(5,1,1,0,"v_z_polso");
          _SFD_SET_DATA_PROPS(6,1,1,0,"up_polso");
          _SFD_SET_DATA_PROPS(7,2,0,1,"changeO");
          _SFD_SET_DATA_PROPS(8,1,1,0,"is_sx_hand");
          _SFD_SET_DATA_PROPS(9,1,1,0,"v_limit");
          _SFD_SET_DATA_PROPS(10,0,0,0,"chord_relL");
          _SFD_SET_DATA_PROPS(11,2,0,1,"vel_for_volO");
          _SFD_SET_DATA_PROPS(12,0,0,0,"vel_for_volL");
          _SFD_EVENT_SCOPE(0,0);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,1);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,2);
          _SFD_CH_SUBSTATE_INDEX(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,2);
          _SFD_ST_SUBSTATE_INDEX(2,0,3);
          _SFD_ST_SUBSTATE_INDEX(2,1,6);
          _SFD_ST_SUBSTATE_COUNT(3,2);
          _SFD_ST_SUBSTATE_INDEX(3,0,4);
          _SFD_ST_SUBSTATE_INDEX(3,1,5);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(0,1);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(2,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,1,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(6,1,0,20,-1,24);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(4,1,0,44,-1,48);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(11,0,0,1,0,3,0,0,0,7,1);
        _SFD_CV_INIT_EML_SATURATION(11,0,0,138,-1,146);
        _SFD_CV_INIT_EML_SATURATION(11,0,1,32,-1,40);
        _SFD_CV_INIT_EML_SATURATION(11,0,2,85,-1,93);
        _SFD_CV_INIT_EML_IF(11,0,0,1,173,1,48);

        {
          static int condStart[] = { 1, 19, 47, 72, 100, 125, 152 };

          static int condEnd[] = { 14, 41, 66, 94, 119, 147, 171 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3, 4, -3, 5, -3, 6, -3
          };

          _SFD_CV_INIT_EML_MCDC(11,0,0,1,172,7,0,&(condStart[0]),&(condEnd[0]),
                                13,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(5,0,0,1,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(5,0,0,14,-1,22);
        _SFD_CV_INIT_EML_IF(5,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,20,1,20);
        _SFD_CV_INIT_EML(9,0,0,1,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(9,0,0,14,-1,22);
        _SFD_CV_INIT_EML_SATURATION(9,0,1,62,-1,76);
        _SFD_CV_INIT_EML_IF(9,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(7,0,0,1,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(7,0,0,14,-1,22);
        _SFD_CV_INIT_EML_IF(7,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,20,1,20);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,20,1,20);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)c3_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);

        {
          uint16_T *c3_id;
          uint8_T *c3_chord_relO;
          uint8_T *c3_chord_altO;
          int32_T *c3_v_x_polso;
          int32_T *c3_v_y_polso;
          int32_T *c3_v_z_polso;
          boolean_T *c3_up_polso;
          boolean_T *c3_changeO;
          boolean_T *c3_is_sx_hand;
          int32_T *c3_v_limit;
          int32_T *c3_vel_for_volO;
          c3_vel_for_volO = (int32_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c3_v_limit = (int32_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_is_sx_hand = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_changeO = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c3_up_polso = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_v_z_polso = (int32_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_v_y_polso = (int32_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_v_x_polso = (int32_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c3_chord_altO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_chord_relO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_id = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_id);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_chord_relO);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_chord_altO);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_v_x_polso);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_v_y_polso);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_v_z_polso);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_up_polso);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_changeO);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_is_sx_hand);
          _SFD_SET_DATA_VALUE_PTR(9U, c3_v_limit);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c3_chord_relL);
          _SFD_SET_DATA_VALUE_PTR(11U, c3_vel_for_volO);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c3_vel_for_volL);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _SX_Hand0MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "TMeKHdd5son9EKQqwzgFNF";
}

static void sf_opaque_initialize_c3_SX_Hand0(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_SX_Hand0InstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c3_SX_Hand0((SFc3_SX_Hand0InstanceStruct*) chartInstanceVar);
  initialize_c3_SX_Hand0((SFc3_SX_Hand0InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_SX_Hand0(void *chartInstanceVar)
{
  enable_c3_SX_Hand0((SFc3_SX_Hand0InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_SX_Hand0(void *chartInstanceVar)
{
  disable_c3_SX_Hand0((SFc3_SX_Hand0InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_SX_Hand0(void *chartInstanceVar)
{
  sf_gateway_c3_SX_Hand0((SFc3_SX_Hand0InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_SX_Hand0(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_SX_Hand0((SFc3_SX_Hand0InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_SX_Hand0();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c3_SX_Hand0(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_SX_Hand0();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_SX_Hand0((SFc3_SX_Hand0InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_SX_Hand0(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_SX_Hand0(S);
}

static void sf_opaque_set_sim_state_c3_SX_Hand0(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_SX_Hand0(S, st);
}

static void sf_opaque_terminate_c3_SX_Hand0(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_SX_Hand0InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_SX_Hand0_optimization_info();
    }

    finalize_c3_SX_Hand0((SFc3_SX_Hand0InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_SX_Hand0((SFc3_SX_Hand0InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_SX_Hand0(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c3_SX_Hand0((SFc3_SX_Hand0InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_SX_Hand0(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SX_Hand0_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(534787455U));
  ssSetChecksum1(S,(1682938243U));
  ssSetChecksum2(S,(1947702109U));
  ssSetChecksum3(S,(3214955260U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_SX_Hand0(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_SX_Hand0(SimStruct *S)
{
  SFc3_SX_Hand0InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_SX_Hand0InstanceStruct *)utMalloc(sizeof
    (SFc3_SX_Hand0InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_SX_Hand0InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_SX_Hand0;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_SX_Hand0;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_SX_Hand0;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_SX_Hand0;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_SX_Hand0;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_SX_Hand0;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_SX_Hand0;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_SX_Hand0;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_SX_Hand0;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_SX_Hand0;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_SX_Hand0;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_SX_Hand0_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_SX_Hand0(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_SX_Hand0(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_SX_Hand0(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_SX_Hand0_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
