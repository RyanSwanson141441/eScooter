/*
 * scooter.c
 *
 *  Created on: Oct 31, 2017
 *      Author: lemmo
 */
#include "scooter.h"

void scoot_initialize(SCOOT * scooter)
{
    scooter->cur_dist = 0;
    scooter->prev_dist = 0;
    scooter->time = 0;
    scooter->velocity = 0;
}


