#ifndef __KEY_INTERRUPT_H_
#define __KEY_INTERRUPT_H_

///////////////////////////////////////////////////////////
//
// �ļ����ܣ������ж�ģʽ�İ�������
// �汾��V1.0
// ���ߣ�īε��MW��
// �޸�ʱ�䣺2024/08/03
//
///////////////////////////////////////////////////////////

#include "main.h"
#include "stm32g0xx_hal.h"

/* Key���� */
#define Key_Port		WAKE_GPIO_Port
#define Key_Pin			WAKE_Pin
#define Key_EXTI		WAKE_EXTI_IRQn

/**
  * @brief �����ж�ģʽ��ʼ��
  * @return ��
  */
void KEY_Inter_Init(void);

#endif
