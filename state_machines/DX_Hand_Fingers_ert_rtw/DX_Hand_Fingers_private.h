/*
 * File: DX_Hand_Fingers_private.h
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

#ifndef RTW_HEADER_DX_Hand_Fingers_private_h_
#define RTW_HEADER_DX_Hand_Fingers_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_s32_s32_s32_sat(int32_T a, int32_T b);

#endif                                 /* RTW_HEADER_DX_Hand_Fingers_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
