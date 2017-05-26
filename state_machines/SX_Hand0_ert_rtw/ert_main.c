/*
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "SX_Hand0.h"                  /* Model's header file */
#include "rtwtypes.h"

static RT_MODEL_SX_Hand0_SymType SX_Hand0_M_;
static RT_MODEL_SX_Hand0_SymType *const SX_Hand0_M = &SX_Hand0_M_;/* Real-time model */
static D_Work_SX_Hand0_SymType SX_Hand0_DWork;/* Observable states */
static ExternalInputs_SX_Hand0_SymType SX_Hand0_U;/* External inputs */
static ExternalOutputs_SX_Hand_SymType SX_Hand0_Y;/* External outputs */

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL_SX_Hand0_SymType *const SX_Hand0_M)
{
  static boolean_T OverrunFlag = 0;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(SX_Hand0_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  SX_Hand0_step(SX_Hand0_M, &SX_Hand0_U, &SX_Hand0_Y);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  SX_Hand0_M->ModelData.dwork = &SX_Hand0_DWork;

  /* Initialize model */
  SX_Hand0_initialize(SX_Hand0_M, &SX_Hand0_U, &SX_Hand0_Y);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.4 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(SX_Hand0_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(SX_Hand0_M) == (NULL)) {
    /*  Perform other application tasks here */
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  SX_Hand0_terminate(SX_Hand0_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
