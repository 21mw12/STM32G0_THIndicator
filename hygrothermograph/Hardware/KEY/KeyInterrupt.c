#include "KeyInterrupt.h"

void KEY_Inter_Init(void) {
  __HAL_RCC_GPIOB_CLK_ENABLE();
  
	GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = Key_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(Key_Port, &GPIO_InitStruct);

  /* 中断配置，1优先级，0子优先级 */
  HAL_NVIC_SetPriority(Key_EXTI, 1, 0);
  HAL_NVIC_EnableIRQ(Key_EXTI);
}

/**
  * 若不使用CubeMX生成中断，则需要释放下面函数
  * 注意要修改为对应的中断函数
  * 再从写如以下的处理函数：
  *   void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)
  * 	void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin)
  */
//void EXTI4_15_IRQHandler(void) {
//  HAL_GPIO_EXTI_IRQHandler(Key_Pin);
//}
