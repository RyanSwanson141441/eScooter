/*
 * interrupt.h
 *
 *  Created on: Oct 20, 2017
 *      Author: lemmo
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_


void CS_IRQHandler(void);

/********************************
 *      PORT1_IRQHandler()
 *
 * Port 1 Interrupt handler; Used
 * to count scooter wheel turns
 * and recieve button interrupts
 *********************************/
void PORT1_IRQHandler(void);

/********************************************
 *         TA0_0_IRQHandler()
 *
 * Sends debug data to the terminal after
 * every clock interrupt; useful for sending
 * scooter calculations after every interrupt
 ********************************************/
void TA0_0_IRQHandler(void);


#endif /* INTERRUPT_H_ */
