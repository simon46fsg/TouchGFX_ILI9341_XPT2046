/*
 * temp_sensor.h
 *
 *  Created on: Nov 23, 2022
 *      Author: simon
 */

#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "main.h"
#include "stdbool.h"

typedef struct {
	float temp;
	bool openCircuit;
}TemperatureSensor;


void updateTemp();
uint16_t get_max6675_code();



#endif /* TEMP_SENSOR_H_ */
