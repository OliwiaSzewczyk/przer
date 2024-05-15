#include <LPC21xx.H>
#include "timer.h"

#define COUNTER_ENABLE_bm (1<<0)
#define COUNTER_RESET_bm (1<<1)
#define INTERRUPT_ON_MR0_bm (1<<0)
#define RESET_ON_MR0_bm (1<<1)

void InitTimer0(void){
	T0TCR = COUNTER_ENABLE_bm;
}

void WaitOnTimer0(unsigned int uiTime){
	T0TCR |= COUNTER_RESET_bm;	
	InitTimer0();
	while(T0TC < (uiTime*15)){
  }
}

void InitTimer0Match0(unsigned int uiDelayTime) {
	T0MR0 = (uiDelayTime*15);
	T0MCR = (INTERRUPT_ON_MR0_bm | RESET_ON_MR0_bm);
	
	T0TCR = COUNTER_RESET_bm;
	InitTimer0();
}

void WaitOnTimer0Match0(void) {
	while((T0IR & INTERRUPT_ON_MR0_bm) == 0) {
	}
	T0IR |= INTERRUPT_ON_MR0_bm;
}

