#ifndef __KEY_INTERRUPT_H_
#define __KEY_INTERRUPT_H_

///////////////////////////////////////////////////////////
//
// 文件功能：采用中断模式的按键功能
// 版本：V1.0
// 作者：墨蔚（MW）
// 修改时间：2024/08/03
//
///////////////////////////////////////////////////////////

#include "main.h"
#include "stm32g0xx_hal.h"

/* Key配置 */
#define Key_Port		WAKE_GPIO_Port
#define Key_Pin			WAKE_Pin
#define Key_EXTI		WAKE_EXTI_IRQn

/**
  * @brief 按键中断模式初始化
  * @return 无
  */
void KEY_Inter_Init(void);

#endif
