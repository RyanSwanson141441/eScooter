/*
 * Accelerometer.h
 *
 *  Created on: Nov 5, 2017
 *      Author: ryan
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

/******************************************************
 *
 *              configure_ADC_accel()
 *
 * Configure the ADC to convert the X-direction of our
 * accelerometer force. This will be used to confirm
 * whether our scooter is moving forwards or backwards.
 *****************************************************/
void configure_ADC_accel(void);

/********************************************
 *              convert_Accelerometer()
 *
 * Convert our accelerometer data to forward
 * and backwards directional information
 ********************************************/
void convert_Accelerometer(void);

#endif /* ACCELEROMETER_H_ */
