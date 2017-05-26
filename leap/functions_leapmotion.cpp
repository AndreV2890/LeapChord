#include "../leap/functions_leapmotion.h"

#include <pthread.h>
#include <math.h>



using namespace Leap;

pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;	// mutex on the frame reading

ControllerSxMsgType hand_sx_read_controller(Controller* c)
{
ControllerSxMsgType msg;
Frame f;
HandList hands;

	pthread_mutex_lock(&mux);
	f = c->frame();
	pthread_mutex_unlock(&mux);

	hands = f.hands();
	msg.id_frame = f.id();

	msg.is_sx_hand = 0;

	for (HandList::const_iterator hl = hands.begin(); hl != hands.end(); ++hl)
	{
		const Hand hand = *hl;
		Vector position = hand.palmPosition();
		Vector handSpeed = hand.palmVelocity();
		if(hand.isLeft())
		{
			msg.position.x = position.x;
			msg.position.y = position.y;
			msg.position.z = position.z;

			//hand.palmNormal().y > 0 palm oriented up, < 0 palm oriented down
			msg.palm_normal = (hand.palmNormal().y > 0)?1:0;

			msg.velocity.x = (int) handSpeed.x;
			msg.velocity.y = (int) handSpeed.y;
			msg.velocity.z = (int) handSpeed.z;

			msg.is_sx_hand = 1;

			return msg;
		}
	}

	return msg;
}


ControllerDxMsgType hand_dx_read_controller(Controller* c)
{
ControllerDxMsgType msg;
Frame f;
HandList hands;

	pthread_mutex_lock(&mux);
	f = c->frame();
	pthread_mutex_unlock(&mux);

	hands = f.hands();
	msg.id_frame = f.id();
	msg.hand = 0;
	msg.init = false;
	for (HandList::const_iterator hl = hands.begin(); hl != hands.end(); ++hl)
	{
		Hand hand = *hl;
		if(hand.isRight())
		{
			msg.init = ((hand.palmNormal().y > 0)?true:false);
			msg.hand = 1;	// right hand found

			Vector handSpeed = hand.palmVelocity();
			const int palm_y = hand.palmPosition().y;
			FingerList fingers = f.fingers();
			msg.hand_speed = handSpeed.y;

			for(FingerList::const_iterator fl = fingers.begin(); fl != fingers.end(); fl++)
			{
				const Finger finger = *fl;

				// calculate relative y-axis between palm and finger tip

				if(finger.type()==0)
				{
					msg.thumb = palm_y - finger.tipPosition().y;
				}
				else if(finger.type()==1)
				{
					msg.index = palm_y - finger.tipPosition().y;
				}
				else if(finger.type()==2)
				{
					msg.middle = palm_y - finger.tipPosition().y;
				}
				else if(finger.type()==3)
				{
					msg.ring = palm_y - finger.tipPosition().y;
				}
				else if(finger.type()==4)
				{
					msg.pinky = palm_y - finger.tipPosition().y;
				}
			}

			return msg;
		}
	}

	return msg;
}

boolean_T change_modality(Controller* c,int* i,int module)
{
Frame f;
HandList hands;

	pthread_mutex_lock(&mux);
	f = c->frame();
	pthread_mutex_unlock(&mux);

	hands = f.hands();
	for (HandList::const_iterator hl = hands.begin(); hl != hands.end(); ++hl)
	{
		const Hand hand = *hl;
		if(hand.isRight())
		{
			FingerList fingers = f.fingers();
			for(FingerList::const_iterator fl = fingers.begin(); fl != fingers.end(); fl++)
			{
				const Finger finger = *fl;

				// searching index finger
				if(finger.type()==1)
				{
					int velocity = finger.tipVelocity().x;

					// finger is moving to left
					if (velocity < (-500))
					{
						(*i) = ((*i)+(module-1))%module;
						return true;
					}
					// finger is moving to right
					else if (velocity > 500)
					{
						(*i) = ((*i)+1)%module;
						return true;
					}
				}
			}
		}
	}
	return false;
}

boolean_T confirm_modality(Controller* c)
{
Frame f;
HandList hands;

	pthread_mutex_lock(&mux);
	f = c->frame();
	pthread_mutex_unlock(&mux);

	hands = f.hands();
	for (HandList::const_iterator hl = hands.begin(); hl != hands.end(); ++hl)
	{
		const Hand hand = *hl;
		if(hand.isRight())
		{
			FingerList fingers = f.fingers();
			for(FingerList::const_iterator fl = fingers.begin(); fl != fingers.end(); fl++)
			{
				const Finger finger = *fl;

				// searching index
				if(finger.type()==1)
				{
					int velocity = finger.tipVelocity().z;

					// control if the button is pressed
					if (velocity < (-800)) return true;
				}
			}
		}
	}

	return false;
}
