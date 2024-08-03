#ifndef __74HC595_H_
#define __74HC595_H_

///////////////////////////////////////////////////////////
//
// �ļ����ܣ�ʹ��3��74HC595������2����λ���������
// �汾��V1.0
// ���ߣ�īε��MW��
// �޸�ʱ�䣺2024/08/01
//
// Ĭ�����ã����������������������������ģʽ���ߵ�ƽ
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
  * @brief ����ܳ�ʼ��
  * @return ��
  */
void Nixie_Init(void);

/**
  * @brief �����������ʾ����
  * @param data1 ǰ��λ����
  * @param data2 ����λ����
  * @param dot1 С����λ��
  * @param dot2 С����λ��
  * @return ��
  */
void Nixie_SetData(uint16_t data1, uint16_t data2, uint8_t dot1, uint8_t dot2);

/**
  * @brief ʹ�ö�ʱ������ʾ����ܣ���ʱ������Ϊ1ms��
  * @return ��
  */
void Nixie_ShowData_TIM(void);

/**
  * @brief ��ѭ������ʾ�����
  * @return ��
  */
void Nixie_ShowData_LOOP(void);

/**
  * @brief �ر��������ʾ
  * @return ��
  */
void Nixie_Close(void);

#endif
