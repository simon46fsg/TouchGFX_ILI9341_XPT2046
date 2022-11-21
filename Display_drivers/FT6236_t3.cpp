//
//  FT6236_t3.cpp
//
//  Created by Renaud Calmont on 24/11/2016.
//  MIT Licence.
//

#include "FT6236_t3.h"

FT6236_t3::FT6236_t3(uint8_t addr, uint8_t irq) {
    _addr = addr;
    _irq = irq;
}

void FT6236_t3::begin() {
	HAL_GPIO_WritePin(T_RESET_GPIO_Port, T_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(T_RESET_GPIO_Port, T_RESET_Pin, GPIO_PIN_SET);
    writeFT6236TouchRegister(0, 0); // device mode = Normal
    writeFT6236TouchRegister(0xA4, 0x00); // Interrupt polling mode
}

TouchEvent FT6236_t3::currentTouchEvent() {
    TouchEvent current;
    current.type = TouchIDLE;
//    attention = digitalRead(_irq);
    attention = HAL_GPIO_ReadPin(T_INT_GPIO_Port, T_INT_Pin);
    
    if (!attention && oldAttention) {
        uint8_t count = readFT6236TouchLocation(touchLocations, 1);
        if (count) {
            /*for (uint8_t i = 0; i < count; i++) {} Ignore multitouch */
            current.type = TouchSTART;
            current.location.x = touchLocations[0].y;
            current.location.y = 320 - touchLocations[0].x;
        }
        else {
        }
    }

    oldAttention = attention;
    return current;
}

void FT6236_t3::writeFT6236TouchRegister(uint8_t reg, uint8_t val) {
//    Wire.beginTransmission(_addr);
//    Wire.write(reg);
//    Wire.write(val);
//    Wire.endTransmission();
	uint8_t buf[2];
	buf[0] = reg;
	buf[1] = val;
    i2c2_status = HAL_I2C_Master_Transmit(&hi2c2, FT6236_ADDR, buf, 2, 100);
    if(i2c2_status != HAL_OK) {
    		HAL_Delay(1);
    	}

}

uint8_t FT6236_t3::readFT6236TouchLocation(TouchLocation *pLoc, uint8_t num) {
    uint8_t retVal = 0;
    uint8_t i;
    uint8_t k;
  
    do {
        if (!pLoc) break; // must have a buffer
        if (!num)  break; // must be able to take at least one
    
        uint8_t status = readFT6236TouchRegister(2);
    
        static uint8_t tbuf[40];
    
        if ((status & 0x0f) == 0) break; // no points detected
    
        uint8_t hitPoints = status & 0x0f;
    
        readFT6236TouchAddr( 0x03, tbuf, hitPoints*6);
    
        for (k=0,i = 0; (i < hitPoints*6)&&(k < num); k++, i += 6) {
            pLoc[k].x = (tbuf[i+0] & 0x0f) << 8 | tbuf[i+1];
            pLoc[k].y = (tbuf[i+2] & 0x0f) << 8 | tbuf[i+3];
        }
    
        retVal = k;
    
    }
    while (0);
  
    return retVal;
}

uint8_t FT6236_t3::readFT6236TouchRegister(uint8_t reg) {
//    Wire.beginTransmission(_addr);
//    Wire.write(reg);  // register 0
//    uint8_t retVal = Wire.endTransmission();

	uint8_t retVal = 0;
	i2c2_status = HAL_I2C_Master_Transmit(&hi2c2, FT6236_ADDR, &reg, 1, 100);
	if(i2c2_status == HAL_OK) {
		i2c2_status = HAL_I2C_Master_Receive(&hi2c2, FT6236_ADDR, &retVal, 1, 100);
	}
	if(i2c2_status != HAL_OK) {
		HAL_Delay(1);
	}
  
//    Wire.requestFrom(_addr, uint8_t(1) );    // request 6 uint8_ts from slave device #2
//
//    if (Wire.available()) {
//        retVal = Wire.read();
//    }


  
    return retVal;
}

uint8_t FT6236_t3::readFT6236TouchAddr(uint8_t regAddr, uint8_t *pBuf, uint8_t len) {
//    Wire.beginTransmission(_addr);
//    Wire.write(regAddr);  // register 0
//    Wire.endTransmission();
//
//    Wire.requestFrom(_addr, len);    // request 1 bytes from slave device #2
  
//    uint8_t i;
//    for (i = 0; (i < len) && Wire.available(); i++) {
//        pBuf[i] = Wire.read();
//    }

	i2c2_status = HAL_I2C_Master_Transmit(&hi2c2, FT6236_ADDR, &regAddr, 1, 100);
	if(i2c2_status == HAL_OK) {
		i2c2_status = HAL_I2C_Master_Receive(&hi2c2, FT6236_ADDR, pBuf, len, 100);
	}
	if(i2c2_status != HAL_OK) {
			HAL_Delay(1);
		}

  
	uint8_t i = len - 1; //i ist dumm
    return i;
}
