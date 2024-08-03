#ifndef __KEY_H_
#define __KEY_H_

///////////////////////////////////////////////////////////
//
// 文件功能：按键的相关功能函数
// 版本：V1.1
// 作者：墨蔚（MW）
// 修改时间：2024/08/01
//
// 默认配置：上拉
//
///////////////////////////////////////////////////////////

#include "main.h"
#include "stm32g0xx_hal.h"

/* Key引脚，修改为main.h中自定义的名称或具体端口 */
#define Key_Port		WAKE_GPIO_Port
#define Key_Pin			WAKE_Pin

typedef enum {
	KeyState_NoPush = 0,	// 按键未被按下
	KeyState_Push			// 按键被按下
} KeyState;

/**
  * @brief 按键初始化
  * @return 无
  */
void KEY_Init(void);

/**
  * @brief 获得按键的状态
  * @return 按键状态
  */
KeyState KEY_GetState(void);

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
