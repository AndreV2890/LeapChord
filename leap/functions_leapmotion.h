#ifndef FUNCTIONS_LEAPMOTION_H_
#define FUNCTIONS_LEAPMOTION_H_

#include "../leap/Leap.h"
#include "../leap/LeapMath.h"
#include "../project/project_library.h"

using namespace Leap;

ControllerSxMsgType hand_sx_read_controller(Controller*);

ControllerDxMsgType hand_dx_read_controller(Controller*);

boolean_T change_modality(Controller*,int*,int);

boolean_T confirm_modality(Controller*);

#endif /* FUNCTIONS_LEAPMOTION_H_ */
