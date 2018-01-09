/*
 * uart.h
 *
 *  Created on: Nov 2, 2017
 *      Author: lemmo
 */

#ifndef UART_H_
#define UART_H_

#include "msp.h"

void configure_uart(void);

/****************************************
 *        UART_send_n()
 *
 * Send ASCII data to the transmit buffer
 * to be stored for serial transmit later
 ***************************************/

void UART_send_n(uint8_t * data, uint32_t length);

/***********************************
 *      UART_send_byte()
 *
 * Takes in data of size less than
 * 255 bytes and transmits it to the
 *           console
 **********************************/

void UART_send_byte(uint8_t data);

/***********************************
 *              ftoa()
 *
 * Function used to output a float
 *     variable to a terminal
 ***********************************/
void ftoa(float number);

#endif /* UART_H_ */
