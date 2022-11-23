/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * This file is generated by TouchGFX Generator 4.20.0.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>
#include "../../Display_drivers/ili9341.h"
#include "../../Display_drivers/FT6236_t3.h"

FT6236_t3 touchcontroller(0, 0);
TouchEvent touchevent;



void STM32TouchController::init()
{
    /**
     * Initialize touch controller and driver
     *
     */
	touchcontroller.begin();
}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
    /**
     * By default sampleTouch returns false,
     * return true if a touch has been detected, otherwise false.
     *
     * Coordinates are passed to the caller by reference by x and y.
     *
     * This function is called by the TouchGFX framework.
     * By default sampleTouch is called every tick, this can be adjusted by HAL::setTouchSampleRate(int8_t);
     *
     */

	touchevent = touchcontroller.currentTouchEvent();
	x = 320-touchevent.location.x;
	y = 240-(touchevent.location.y-80);
	if(touchevent.type == 1) {
		return true;
	}else{
		return false;
	}

}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
