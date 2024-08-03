#ifndef __74HC595_H_
#define __74HC595_H_

///////////////////////////////////////////////////////////
//
// 文件功能：使用3个74HC595驱动的2个三位共阴数码管
// 版本：V1.0
// 作者：墨蔚（MW）
// 修改时间：2024/08/01
//
// 默认配置：推挽输出，无上拉无下拉，低速模式，高电平
//
///////////////////////////////////////////////////////////

#include "main.h"
#include "stm32g0xx_hal.h"

#define Nixie1_SER_GPIO_Port 		GPIOB
#define Nixie1_SER_Pin 					GPIO_PIN_2
#define Nixie1_RCLK_GPIO_Port 	GPIOA
#define Nixie1_RCLK_Pin 				GPIO_PIN_8
#define Nixie1_SCLK_GPIO_Port 	GPIOA
#define Nixie1_SCLK_Pin 				GPIO_PIN_9
#define Nixie2_SER_GPIO_Port 		GPIOA
#define Nixie2_SER_Pin 					GPIO_PIN_0
#define Nixie2_RCLK_GPIO_Port 	GPIOA
#define Nixie2_RCLK_Pin 				GPIO_PIN_1
#define Nixie2_SCLK_GPIO_Port 	GPIOA
#define Nixie2_SCLK_Pin 				GPIO_PIN_2
#define DIG_SER_GPIO_Port 			GPIOA
#define DIG_SER_Pin 						GPIO_PIN_3
#define DIG_RCLK_GPIO_Port 			GPIOA
#define DIG_RCLK_Pin 						GPIO_PIN_4
#define DIG_SCLK_GPIO_Port 			GPIOA
#define DIG_SCLK_Pin 						GPIO_PIN_5

/**
  * @brief 数码管初始化
  * @return 无
  */
void Nixie_Init(void);

/**
  * @brief 设置数码管显示内容
  * @param data1 前三位数据
  * @param data2 后三位数据
  * @param dot1 小数点位置
  * @param dot2 小数点位置
  * @return 无
  */
void Nixie_SetData(uint16_t data1, uint16_t data2, uint8_t dot1, uint8_t dot2);

/**
  * @brief 使用定时器内显示数码管（定时器周期为1ms）
  * @return 无
  */
void Nixie_ShowData_TIM(void);

/**
  * @brief 在循环内显示数码管
  * @return 无
  */
void Nixie_ShowData_LOOP(void);

/**
  * @brief 关闭数码管显示
  * @return 无
  */
void Nixie_Close(void);

#endif
