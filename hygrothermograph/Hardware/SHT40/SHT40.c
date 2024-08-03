#include "SHT40.h"
#include "SHT40_Register.h"
#include "i2c.h"

void SHT40_GetTempHumi(float* temp, float* humi) {
	uint8_t writeData[1] = {SHT40_HP_Measure};
	uint8_t readData[6] = {0};
	
	HAL_I2C_Master_Transmit(&hi2c1, SHT40_Write, writeData, 1, HAL_MAX_DELAY);
	HAL_Delay(10);
	HAL_I2C_Master_Receive(&hi2c1, SHT40_Read, readData, 6, HAL_MAX_DELAY);
	
	*temp = (1.0 * 175 * (readData[0] << 8 | readData[1])) / 65535.0 - 45;
	*humi = (1.0 * 125 * (readData[0] << 8 | readData[1])) / 65535.0 - 6.0;
}
