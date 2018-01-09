/*
 * scooter.h
 *
 *  Created on: Oct 31, 2017
 *      Author: Lemmon
 */

#ifndef SCOOTER_H_
#define SCOOTER_H_
#include "msp.h"

typedef struct SCOOT_t{
	volatile uint32_t cur_dist;
	volatile uint32_t prev_dist;
	volatile float velocity;
	volatile float time;
} SCOOT;

/*******************************************
 *          scoot_initialize()
 *
 * A function that initializes a scooter
 * structure that stores our variables
 ******************************************/
void scoot_initialize(SCOOT * scooter);

#endif /* SCOOTER_H_ */
