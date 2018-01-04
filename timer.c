/*
 * timer.c
 *
 *  Created on: Oct 31, 2017
 *      Author: lemmo
 */


#include "timer.h"

void configure_timer(void){
	TIMER_A0->CTL = 0x0034;	//Reset and halt timer for config
	TIMER_A0->CTL = 0x0100; //CLK = ACLK; div = 1
	TIMER_A0->CCTL[0] = 0x0090;	//Enable timer interrupts
	TIMER_A0->CCR[0] = 16400;	//Reset value
	TIMER_A0->CTL |= 0x0010;	//Start timer in up-mode
}
