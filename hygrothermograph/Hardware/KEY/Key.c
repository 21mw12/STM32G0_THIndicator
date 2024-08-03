#include "Key.h"

void KEY_Init(void) {
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = WAKE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(WAKE_GPIO_Port, &GPIO_InitStruct);
}

KeyState KEY_GetState(void){
	if (HAL_GPIO_ReadPin(Key_Port, Key_Pin) == GPIO_PIN_RESET) {
		HAL_Delay(20);
		while (HAL_GPIO_ReadPin(Key_Port, Key_Pin) == GPIO_PIN_RESET);
		HAL_Delay(20);
		return KeyState_Push;
	}
	return KeyState_NoPush;
}
