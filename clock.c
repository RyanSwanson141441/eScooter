/*
 * clock.c
 *
 *  Created on: Oct 10, 2017
 *      Author: lemmo
 */

#include "msp.h"
#include "clock.h"

void configure_pcm(void){
	while(PCM->CTL1 & 0x0100);	//wait for pcm_busy to be clear
	PCM->CTL0 = 0x695A0001;	//set pcm to AM_LDO_VCORE1
	while(PCM->CTL1 & 0x0100);	//wait for pcm_busy to be clear
	PCM->CTL0 = 0x695A0005;	//set pcm to AM_DCDC_VCORE1
	while(PCM->CTL1 & 0x0100);	//wait for pcm_busy to be clear
}

void configure_clock(void){
	PJ->SEL0 |= 0x08; //PJ.3 to HFXT
	PJ->SEL1 &= ~0x08;
	CS->KEY = 0x695A; // Unlock CS module for register access
	CS->CTL2 = 0x00610003;	//tune HFXT for 48MHz
	CS->CTL1 = 0x10010055;	//MCLK = HFXT; SMCLK = HFXT/2
	CS->IE |= 0x0200;
	CS->KEY = 0;	// lock CS module for register access
}
