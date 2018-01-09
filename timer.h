/*
 * timer.h
 *
 *  Created on: Oct 31, 2017
 *      Author: lemmo
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "msp.h"

/********************************************
 *          configure_timer()
 *
 * Configure Timer A0 to:
 * - Interrupt every half-second
 * - Connected to send debug data to terminal
 ********************************************/
void configure_timer(void);



#endif /* TIMER_H_ */
