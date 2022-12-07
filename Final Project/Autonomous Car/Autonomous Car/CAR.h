/*
 * CAR.h
 *
 * Created: 11/28/2022 12:03:24 AM
 *  Author: Rafik
 */ 


#ifndef CAR_H_
#define CAR_H_

#define modes 1
#define self 0
#define uart 1


#define forward	 0
#define right	 1
#define left	 2
#define backward 3


#define US_ERROR		-1      // we're defining two more variables two know if the ultrasonic sensor is working or not
#define	US_NO_OBSTACLE	-2

void HCSR04Init();
void HCSR04Trigger();

u16 GetPulseWidth(void);

void ServoRotation_RIGHT(void);
void ServoRotation_LEFT(void);
void ServoRotation_MID(void);


#endif /* CAR_H_ */