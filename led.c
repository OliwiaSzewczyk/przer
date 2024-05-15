#include <LPC21xx.H>
#include "led.h"

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

void LedInit(void){
	IO1DIR|= (1<<16)|(1<<17)|(1<<18)|(1<<19);
	IO1CLR= (1<<16)|(1<<17)|(1<<18)|(1<<19);
	IO1SET= (1<<16);
}

void LedOn(unsigned char ucLedIndeks){
	IO1CLR= (1<<16)|(1<<17)|(1<<18)|(1<<19);
  switch (ucLedIndeks){
    case 0:
      IO1SET=(1<<16);
      break;
    case 1:
      IO1SET=(1<<17);
      break;
    case 2:
			IO1SET=(1<<18);
      break;
		case 3:
			IO1SET=(1<<19);
      break;
		default:
			break;
	}
}

enum Direction {LEFT,RIGHT};

void LedStep(enum Direction eDirection){
	static unsigned int uiCurrentLed = 0;
	switch(eDirection){
	  case LEFT:
      uiCurrentLed = (uiCurrentLed+1)%4;
		  break;
    case RIGHT:
      uiCurrentLed = (uiCurrentLed+3)%4;
		  break;
		default:
			break;
  }
  LedOn(uiCurrentLed);
}

void LedStepLeft(void){
  LedStep(LEFT);
}

void LedStepRight(void){
  LedStep(RIGHT);
}
