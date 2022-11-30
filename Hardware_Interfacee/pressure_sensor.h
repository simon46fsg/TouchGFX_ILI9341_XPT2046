/*
 * pressure_sensor.h
 *
 *  Created on: 28.11.2022
 *      Author: simon
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "main.h"
#include "stdbool.h"



typedef struct {
	float pressure;
	bool outOfRange;
}PressureSensor;

uint16_t pressure_readADC();
void pressure_convertADCtoPressure(uint16_t adc_data);

#endif /* PRESSURE_SENSOR_H_ */
