#ifndef __SHT40_H_
#define __SHT40_H_

///////////////////////////////////////////////////////////
//
// 文件功能：SHT的相关功能
// 版本：V1.0
// 作者：墨蔚（MW）
// 修改时间：2024/08/03
//
///////////////////////////////////////////////////////////

#include "main.h"
#include "stm32g0xx_hal.h"

/**
  * @brief SHT40读取温湿度
  * @param temp 温度
  * @param humi 湿度
  * @return 无
  */
void SHT40_GetTempHumi(float* temp, float* humi);

#endif
