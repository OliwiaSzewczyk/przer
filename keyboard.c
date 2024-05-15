#include <LPC21xx.H>
#include "keyboard.h"

#define BUTTON0_bm (1<<4) 
#define BUTTON1_bm (1<<6) 
#define BUTTON2_bm (1<<5) 
#define BUTTON3_bm (1<<7) 

void KeyboardInit(void){
  IO0DIR &= ~((1<<4)|(1<<6)|(1<<5)|(1<<7));
}

enum KeyboardState eKeyboardRead(void){
  if((IO0PIN & (1<<4)) == 0){
    return BUTTON_0;
  }
	else if((IO0PIN & (1<<6)) == 0){
    return BUTTON_1;
  }
	else if((IO0PIN & (1<<5)) == 0){
    return BUTTON_2;
  }
	else if((IO0PIN & (1<<7)) == 0){
    return BUTTON_3;
  }
	else{
    return RELASED;
  }
}
