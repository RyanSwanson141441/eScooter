/*
 * port.c
 *
 *  Created on: Sep 19, 2017
 *      Author: lemmo
 */
#include "msp.h"
#include "port.h"

void configure_port(void){
/* Port configuration code here for the switches or LEDs */
	P1REN |= 0x32; //Enable res on P1.1/P1.4/P1.5
	P1DIR &= ~0x32; //Dir INPUT for P1.1/P1.4/P1.5
	P1OUT |= 0x12; //Output HIGH P1.1/P1.4
	P1OUT &= ~0x20; //Output LOW P1.5
/* NVIC Port Interrupt Enable Code */ // Enable Port1 interrupt in the NVIC
	P1IES |= 0x12; //Interrupt on high-low edge for P1.1/P1.4
	P1IES &= ~0x20; //Interrupt on low-high edge for P1.5
	P1IFG = 0x00; //Clear all P1 interrupt flags
	P1IE |= 0x32; //Enable interrupt P1.1/P1.4/P1.5
/* Port configuration to output MCLK to 4.3 */
    P4->DIR |= 0x08;	//P4.3 to output
    P4->OUT &= ~0x08;	//P4.3 to low
    P4->SEL0 |= 0x08;	//P4.3 to primary mode
    P4->SEL1 &= ~0x08;
/* Port configuration to output SMCLK to P7.0 */
	P7->DIR |= 0x01;	//P7.0 to output
	P7->OUT &= ~0x01;	//P7.0 to low
	P7->SEL0 |= 0x01;	//P7.0 to primary mode
	P7->SEL1 &= ~0x01;
/* Port configuration to output TA0C0 to P7.3 */
	P7->DIR |= 0x08;	//P7.3 to output
	P7->OUT &= ~0x08;	//P7.3 to low
	P7->SEL0 |= 0x08;	//P7.3 to primary mode
	P7->SEL1 &= ~0x08;
}
