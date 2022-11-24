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

void updateTemp() {
	uint16_t test = get_max6675_code();
//	int dummySignBit = (test) >> 15;
	int openFlag = (test & 0b100) >> 2;
	int tempCode = test >> 3;
	float temp = tempCode * 0.25;
	temperatureSensor.temp = temp;
	temperatureSensor.openCircuit = (bool) openFlag;
}

uint16_t get_max6675_code() {
	uint16_t code = 0;
	HAL_GPIO_WritePin(CS_TEMP_GPIO_Port, CS_TEMP_Pin, GPIO_PIN_RESET);
//	HAL_Delay(100);
/*	HAL_StatusTypeDef status = */HAL_SPI_Receive(spi_handle_ptr, (uint8_t*)&code, 1, 100);
//	HAL_Delay(100);
	HAL_GPIO_WritePin(CS_TEMP_GPIO_Port, CS_TEMP_Pin, GPIO_PIN_SET);
//	HAL_Delay(100);
	return code;
}
