//*****************************************************************************
//
// MSP432 - Scooter Design
// Garret Lemmon, Sonya Schuppan, Ryan Swanson
// ECEN 2440
//
//****************************************************************************

#include "msp.h"
#include "default.h"
#include "port.h"
#include "clock.h"
#include "timer.h"
#include "uart.h"
#include "Accelerometer.h"
#include "vars.h"
#include "scooter.h"

extern volatile uint32_t beam_break;
volatile uint32_t accel_Y;
SCOOT * scoot_struct;

void main(void){
	
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    __enable_interrupt(); // This enables interrupts globally for the CPU
    SYSCTL->NMI_CTLSTAT &= ~0x01;	//Disable CS as a source of NMI
    NVIC->ISER[0] |= 1 << 1;	//Enable CS interrupt
	NVIC->ISER[1] |= 1 << 3;	//Enable Port1 interrupt
	NVIC->ISER[0] |= 1 << 8;	//Enable Timer_A0 CCTL0 interrupt

    default_config();
    configure_port();
    configure_pcm();
    configure_clock();
    configure_timer();
    configure_uart();
    configure_ADC_accel();
    scoot_initialize(scoot_struct);

    while(1)
    {
        ADC14->CTL0 |= ADC14_CTL0_SC; // Start our ADC conversion from the accelerometer
        __sleep();
        convert_Accelerometer();      // Send our accelerometer data to the terminal

        scoot_struct->prev_dist = scoot_struct->cur_dist;   // Move current distance into previous distance
        scoot_struct->cur_dist = beam_break*(SPOKE_ARC);    // Calculate our current distance
    }
}
