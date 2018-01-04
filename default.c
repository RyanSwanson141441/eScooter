/*
 * default.c
 * Basic default port configuration according to Overview - Table 4.4 (Connection for Unused Pins)
 *
 *  Created on: Sep 12, 2017
 *      Author: lemmo
 */
#include "msp.h"

void default_config(){
	//Set all ports to DIO
	PA->SELC = 0x0000;
	PB->SELC = 0x0000;
	PC->SELC = 0x0000;
	PD->SELC = 0x0000;
	PE->SELC = 0x0000;
	//Set all ports to output
	PA->DIR = 0xFFFF;
	PB->DIR = 0xFFFF;
	PC->DIR = 0xFFFF;
	PD->DIR = 0xFFFF;
	PE->DIR = 0xFFFF;
	//Set all outputs low(no necessary but done for MCU protection)
	PA->OUT = 0x0000;
	PB->OUT = 0x0000;
	PC->OUT = 0x0000;
	PD->OUT = 0x0000;
	PE->OUT = 0x0000;
}


