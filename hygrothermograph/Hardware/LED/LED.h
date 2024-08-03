#ifndef __LED_H_
#define __LED_H_

///////////////////////////////////////////////////////////
//
// 文件功能：LED的相关功能函数
// 版本：V1.1
// 作者：墨蔚（MW）
// 修改时间：2024/08/01
//
// 默认配置：推挽输出，无上拉无下拉，低速模式，高电平
//
///////////////////////////////////////////////////////////

#include "main.h"
#include "stm32g0xx_hal.h"

/* LED引脚，修改为main.h中自定义的名称或具体端口 */
#define LED_Port		GPIO_TEST_GPIO_Port
#define LED_Pin			GPIO_TEST_Pin

/**
  * @brief LED初始化
  * @return 无
  */
void LED_Init(void);

/**
  * @brief LED点亮
  * @return 无
  */
void LED_ON(void);

/**
  * @brief LED熄灭
  * @return 无
  */
void LED_OFF(void);

/**
  * @brief LED状态反转
  * @return 无
  */
void LED_Turn(void);

/**
  * @brief LED闪烁
  * @param Delay 闪烁间隔
  * @return 无
  */
void LED_Flash(uint32_t Delay);

#endif

///////////////////////////////////////////////////////////
//
// 更新日志：
// V1.0: 2024/01/06
//				基础功能
// V1.1: 2024/08/01
//				添加初始化函数
//
///////////////////////////////////////////////////////////
