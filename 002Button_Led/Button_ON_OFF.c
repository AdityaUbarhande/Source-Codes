#include<stdint.h>

int main(void)
{
	uint32_t *RCC_AHB1ENR = (uint32_t*)0x40023830;
	uint32_t *GPIO_MODER_A = (uint32_t*)0x40020000;
	uint32_t *GPIO_MODER_D = (uint32_t*)0x40020C00;
	uint32_t *GPIO_IDR = (uint32_t*)0x40020010;
	uint32_t *GPIO_ODR = (uint32_t*)0x40020C14;
	uint32_t *GPIO_PUPDR = (uint32_t*)0x4002000C;

	//STEP 1: ENABLING THE CLOCK FOR GPIOA AND GPIOD
	*RCC_AHB1ENR |= (9 << 0);		//THIS ENABLES THE CLOCK OF BOTH PORTS.

	//STEP 2: SETTING THE MODE TO INPUT AND OUTPUT RESPECTIVELY.
	*GPIO_MODER_A &= ~(3 << 0);		//SET THE MODE OF PA0 TO INPUT.
	*GPIO_MODER_D |= (1 << 30);	//SET THE MODE OF PD15 TO OUTPUT.

	//STEP 3: SETTING PULL_DOWN.
	*GPIO_PUPDR |= (1 << 1); 		//0b1 << 1

	//STEP 4: READING INPUTS AND GIVING OUTPUTS.

	while(1)
	{

		if(*GPIO_IDR & (1 << 0))
		{
			//SET THE LED
			*GPIO_ODR |= (1 << 15);
		}
		else
		{
			//TURN OFF THE LED
			*GPIO_ODR &= ~(1 << 15);
		}

	}

	for(;;);		//infinite loop
}

