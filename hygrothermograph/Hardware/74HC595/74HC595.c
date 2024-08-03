#include "74HC595.h"

/* 数码管数据 */
uint8_t NixieData[20] =  {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,		// 0 ~ 9
													0xbf, 0x86, 0xdb, 0xcf, 0xe6, 0xed, 0xfd, 0x87, 0xff, 0xef};	// 0.~ 9.

uint8_t NixieShowData[6] = {0,0,0,0,0,0};

#define DotOffest		10		// 显示小数点偏移量

/**
  * @brief 控制数码管1的74HC595写入数据
  * @param data 要写入数据
  * @return 无
  */
void Nixie1_74HC595_SendData(uint8_t data) {
	for (uint8_t i = 0; i < 8; i++) {
		/* 按位发送数据 */
		HAL_GPIO_WritePin(Nixie1_SER_GPIO_Port, Nixie1_SER_Pin, (data & (0x80 >> i)) ? GPIO_PIN_SET : GPIO_PIN_RESET);
		
		/* SCLK上升沿接收数据 */
		HAL_GPIO_WritePin(Nixie1_SCLK_GPIO_Port, Nixie1_SCLK_Pin,  GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie1_SCLK_GPIO_Port, Nixie1_SCLK_Pin,  GPIO_PIN_SET);
	}
	
	/* RCLK上升沿锁存 */
	HAL_GPIO_WritePin(Nixie1_RCLK_GPIO_Port, Nixie1_RCLK_Pin,  GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Nixie1_RCLK_GPIO_Port, Nixie1_RCLK_Pin,  GPIO_PIN_SET);
}

/**
  * @brief 控制数码管2的74HC595写入数据
  * @param data 要写入数据
  * @return 无
  */
void Nixie2_74HC595_SendData(uint8_t data) {
	for (uint8_t i = 0; i < 8; i++) {
		/* 按位发送数据 */
		HAL_GPIO_WritePin(Nixie2_SER_GPIO_Port, Nixie2_SER_Pin, (data & (0x80 >> i)) ? GPIO_PIN_SET : GPIO_PIN_RESET);
		
		/* SCLK上升沿接收数据 */
		HAL_GPIO_WritePin(Nixie2_SCLK_GPIO_Port, Nixie2_SCLK_Pin,  GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Nixie2_SCLK_GPIO_Port, Nixie2_SCLK_Pin,  GPIO_PIN_SET);
	}
	
	/* RCLK上升沿锁存 */
	HAL_GPIO_WritePin(Nixie2_RCLK_GPIO_Port, Nixie2_RCLK_Pin,  GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Nixie2_RCLK_GPIO_Port, Nixie2_RCLK_Pin,  GPIO_PIN_SET);
}

/**
  * @brief 控制数码管数据位的74HC595写入数据
  * @param data 要写入数据
  * @return 无
  */
void DIG_74HC595_SendData(uint8_t data) {
	for (uint8_t i = 0; i < 8; i++) {
		/* 按位发送数据 */
		HAL_GPIO_WritePin(DIG_SER_GPIO_Port, DIG_SER_Pin, (data & (0x80 >> i)) ? GPIO_PIN_SET : GPIO_PIN_RESET);
		
		/* SCLK上升沿接收数据 */
		HAL_GPIO_WritePin(DIG_SCLK_GPIO_Port, DIG_SCLK_Pin,  GPIO_PIN_RESET);
		HAL_GPIO_WritePin(DIG_SCLK_GPIO_Port, DIG_SCLK_Pin,  GPIO_PIN_SET);
	}
	
	/* RCLK上升沿锁存 */
	HAL_GPIO_WritePin(DIG_RCLK_GPIO_Port, DIG_RCLK_Pin,  GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DIG_RCLK_GPIO_Port, DIG_RCLK_Pin,  GPIO_PIN_SET);
}

void Nixie_Init(void) {
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
	
	GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = Nixie2_SER_Pin|Nixie2_RCLK_Pin|Nixie2_SCLK_Pin|DIG_SER_Pin
                          |DIG_RCLK_Pin|DIG_SCLK_Pin|Nixie1_RCLK_Pin|Nixie1_SCLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = Nixie1_SER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(Nixie1_SER_GPIO_Port, &GPIO_InitStruct);
	
	
  HAL_GPIO_WritePin(GPIOA, Nixie2_SER_Pin|Nixie2_RCLK_Pin|Nixie2_SCLK_Pin|DIG_SER_Pin
                          |DIG_RCLK_Pin|DIG_SCLK_Pin|Nixie1_RCLK_Pin|Nixie1_SCLK_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(Nixie1_SER_GPIO_Port, Nixie1_SER_Pin, GPIO_PIN_RESET);
}

void Nixie_SetData(uint16_t data1, uint16_t data2, uint8_t dot1, uint8_t dot2) {
	
	NixieShowData[0] = data1 / 100 % 10;
	NixieShowData[1] = data1 / 10 % 10;
	NixieShowData[2] = data1 % 10;
	NixieShowData[3] = data2 / 100 % 10;
	NixieShowData[4] = data2 / 10 % 10;
	NixieShowData[5] = data2 % 10;
	if (dot1 < 6) {
		NixieShowData[dot1] += 10;
	}
	if (dot2 < 6) {
		NixieShowData[dot2] += 10;	
	}
}

void Nixie_ShowData_TIM(void) {
	static uint8_t digIndex = 0xFE;
	static uint8_t cnt = 0;
	
	if (cnt == 6) cnt = 0;

	DIG_74HC595_SendData(digIndex);
	
	if (cnt < 3) {
		Nixie1_74HC595_SendData(NixieData[NixieShowData[cnt++]]);
	} else {
		Nixie2_74HC595_SendData(NixieData[NixieShowData[cnt++]]);
	}	
	
	if (digIndex == 0xDF) {
		digIndex = 0xFE;
	} else {
		digIndex = (digIndex << 1) | 0x01;
	}
}

void Nixie_ShowData_LOOP(void) {	
	uint8_t digIndex = 0xFE;

	for (uint8_t i = 0; i < 6; i++) {
		DIG_74HC595_SendData(digIndex);
		digIndex  = (digIndex << 1) | 0x01;
		
		if (i < 3) {
			Nixie1_74HC595_SendData(NixieData[NixieShowData[i]]);
		} else {
			Nixie2_74HC595_SendData(NixieData[NixieShowData[i]]);
		}
		
		HAL_Delay(2);
		Nixie1_74HC595_SendData(0x00);
	}
}

void Nixie_Close(void) {
	DIG_74HC595_SendData(0xFF);
	Nixie1_74HC595_SendData(0x00);
	Nixie1_74HC595_SendData(0x00);
}
