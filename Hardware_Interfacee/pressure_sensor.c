/*
 * pressure_sensor.c
 *
 *  Created on: 28.11.2022
 *      Author: simon
 */

#include "pressure_sensor.h"

extern ADC_HandleTypeDef hadc1;

PressureSensor pressureSensor;



/*
 *Output of sensor: 0.5V - 4.5V equals 0bar - 12bar
 *Voltage divider: 4.7k and 10k
 *ADC: 0V = 0x0000, 3.3V = 0xFFFF
 */
void pressure_convertADCtoPressure(uint16_t adc_data) {
	float outputVoltage = (float) adc_data * (3.3 / 0xFFFF) * ((4.7 + 10.0) / 10.0); //convert to original voltage range of sensor (0.5V - 4.5V)
	if (outputVoltage < 0.45 || outputVoltage > 4.55) {
		pressureSensor.outOfRange = true;
	} else {
		pressureSensor.outOfRange = false;
	}
	outputVoltage -= 0.5; //remove offset
	if (outputVoltage < 0) {
		outputVoltage = 0;
	}
	outputVoltage *= 12.0/4; //convert to bar
	pressureSensor.pressure = FIRFilter_pressure_Update(outputVoltage); //low pass filter
}

uint16_t pressure_readADC() {
	HAL_ADC_Start(&hadc1);
	return HAL_ADC_GetValue(&hadc1);
}


