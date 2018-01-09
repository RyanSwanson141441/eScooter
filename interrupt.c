/*
 * interrupt.c
 *
 *  Created on: Oct 20, 2017
 *      Author: lemmo
 */

#include "msp.h"
#include "interrupt.h"

volatile uint32_t beam_break;
extern uint32_t accel_Y;

void CS_IRQHandler(void)
{
	CS->KEY = 0x695A; // Unlock CS module for register access
	CS->CLRIFG = 0x0343;	//Clear CSIFG
	CS->KEY = 0;	// lock CS module for register access
}

void PORT1_IRQHandler(void)
{
	if(P1IFG & 0x20){	//statement for P1.5, Connected to scooter beam break
			P1IFG &= ~0x20;
			beam_break++; // Increment distance calculation
			return;
	}
	if(P1IFG & 0x02){	//statement for P1.1
			P1IFG &= ~0x02;
			return;
	}
	if(P1IFG & 0x10){	//statement for P1.4
			P1IFG &= ~0x10;
			return;
	}
}

void ADC14_IRQHandler(void)
{

    if(ADC14->IFGR0 & ADC14_IFGR0_IFG0)
    { // If our accelerometer is done converting our Y force, paste our value into accel_Y
        accel_Y = ADC14->MEM[0];
    }
}

void TA0_0_IRQHandler(void)
{
	TIMER_A0->CCTL[0] &= ~0x01;     // Clear the interrupt flag
	EUSCI_A0->TXBUF = 0x46;         // Send debug data
}
