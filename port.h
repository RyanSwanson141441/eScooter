/*
 * port.h
 *
 *  Created on: Sep 19, 2017
 *      Author: ryan
 */

#ifndef PORT_H_
#define PORT_H_

/*******************************************
 *              configure_port()
 *
 * Configure Port 1 to:
 * - Receive button and beam break interrupts
 * Configure Port 4 to:
 * - Output useful debug information
 * Cofigure Port 7 to:
 * - Output Timer A0 to debug timer
 *******************************************/
void configure_port(void);


#endif /* PORT_H_ */
