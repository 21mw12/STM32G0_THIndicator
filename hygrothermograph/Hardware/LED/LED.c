#include "LED.h"

void LED_Init(void) {
  /* 开启时钟 */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /* 端口初始化 */
	GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_Port, &GPIO_InitStruct);

  /* 默认高电平 */
  HAL_GPIO_WritePin(LED_Port, LED_Pin, GPIO_PIN_SET);
}

void LED_ON(void) {
	HAL_GPIO_WritePin(LED_Port, LED_Pin, GPIO_PIN_SET);
}

void LED_OFF(void) {
	HAL_GPIO_WritePin(LED_Port, LED_Pin, GPIO_PIN_RESET);
}

void LED_Turn(void) {
	HAL_GPIO_WritePin(LED_Port, LED_Pin, !HAL_GPIO_ReadPin(LED_Port, LED_Pin));
}

void LED_Flash(uint32_t Delay) {
	LED_Turn();
	HAL_Delay(Delay);
}
