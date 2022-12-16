/*
 * temp_sensor.c
 *
 *  Created on: Nov 23, 2022
 *      Author: simon
 */

#include "temp_sensor.h"

extern SPI_HandleTypeDef hspi2;
SPI_HandleTypeDef* spi_handle_ptr = &hspi2;

TemperatureSensor temperatureSensor;

void temp_updateTemp(uint16_t temp_data) {
	uint8_t dummySignBit = (temp_data) >> 15;
	uint8_t openFlag = (temp_data & 0b100) >> 2;
	int tempCode = temp_data >> 3;
	float temp = tempCode * 0.25;
	temperatureSensor.temp = FIRFilter_temp_Update(temp);
	temperatureSensor.openCircuit = (bool) openFlag;
	temperatureSensor.dummySingBit = dummySignBit;
}

uint16_t temp_getMAX6675Code() {
	uint16_t code = 0;
	HAL_GPIO_WritePin(CS_TEMP_GPIO_Port, CS_TEMP_Pin, GPIO_PIN_RESET);
	HAL_SPI_Receive(spi_handle_ptr, (uint8_t*)&code, 1, 100);
	HAL_GPIO_WritePin(CS_TEMP_GPIO_Port, CS_TEMP_Pin, GPIO_PIN_SET);
	return code;
}
