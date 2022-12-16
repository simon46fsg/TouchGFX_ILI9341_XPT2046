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
#include "FIR.h"

typedef struct {
	float temp;
	bool openCircuit; //true when no sensor is attached
	uint8_t dummySingBit; //always 0
	uint8_t D1;
	uint8_t D2;
}TemperatureSensor;


void temp_updateTemp(uint16_t temp_data);
uint16_t temp_getMAX6675Code();



#endif /* TEMP_SENSOR_H_ */
