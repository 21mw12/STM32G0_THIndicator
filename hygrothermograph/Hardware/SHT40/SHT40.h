#ifndef __SHT40_H_
#define __SHT40_H_

///////////////////////////////////////////////////////////
//
// �ļ����ܣ�SHT����ع���
// �汾��V1.0
// ���ߣ�īε��MW��
// �޸�ʱ�䣺2024/08/03
//
///////////////////////////////////////////////////////////

#include "main.h"
#include "stm32g0xx_hal.h"

/**
  * @brief SHT40��ȡ��ʪ��
  * @param temp �¶�
  * @param humi ʪ��
  * @return ��
  */
void SHT40_GetTempHumi(float* temp, float* humi);

#endif
