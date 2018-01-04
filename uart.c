/*
 * uart.c
 *
 *  Created on: Nov 2, 2017
 *      Author: lemmo
 */


#include "uart.h"

void configure_uart(void){
	//UART-P1.2:RX; P1.3:TX (P1.2/P1.3 Primary)
	P1->SEL0 |= 0x0C;
	P1->SEL1 &= 0x0C;

	// Configure UART (921600 Baud)
	EUSCI_A0->CTLW0 |= 0x01; // Put eUSCI in reset

	EUSCI_A0->CTLW0 = 0x0081; // Select Frame parameters and clock source
	EUSCI_A0->BRW = 0x0001; // Set Baud Rate
	EUSCI_A0->MCTLW = 0x00A1; // Set first stage modulator bits (if necessary)

	EUSCI_A0->CTLW0 &= ~0x01; // Initialize eUSCI
}

void UART_send_n(uint8_t * data, uint32_t length)
{
    int i;
    for(i= 0; i<length; i++){
        UART_send_byte(data[i]);
    }
}

void UART_send_byte(uint8_t data)
{
    while(!(EUSCI_A0->IFG & 0x0002));               // Wait for Transmit buffer to be empty and ready to transmit,
    EUSCI_A0->TXBUF = data;
}

void ftoa(float number)
{
uint16_t integer = (uint16_t)number;
uint16_t decimal = (number - integer)*1000; //(number % 1)*1000

UART_send_byte(((integer % 1000)/100)+48); //decimal ascii val for hundreds place (because integer division always rounds down so number/100 will be 1 if number = 145, and 48 is the decimal offset for ascii numbers (ascii 0 is decimal 48)
UART_send_byte(((integer % 100)/10)+48); //decimal ascii val for tens place (because number % 100 will be between 0 and 99 so it doesnt care about hundreds place
UART_send_byte(((integer % 10)/1)+48); //decimal ascii val for ones place (number % 10 will only care about ones place)
UART_send_byte(0x2E); //decimal point
UART_send_byte(((decimal % 1000)/100)+48);
UART_send_byte(((decimal % 100)/10)+48);
UART_send_byte(((decimal % 10)/1)+48);

}
