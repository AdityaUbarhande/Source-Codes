
#include<stdint.h>

uint32_t *GPIO_MODER_p = (uint32_t*)0x40020C00;		//BASE ADDR OF MODER
uint32_t *GPIO_ODR = (uint32_t*)0x40020C14;			//BASE ADDR OF ODR
uint32_t *RCC_AHB1ENR = (uint32_t*)0x40023830;		//BASE ADDR OF RCC_AHB1ENR

int main(void)
{
	//STEP 1: ENABLE THE CLOCK ACCESS TO GPIOD
	*RCC_AHB1ENR |= (1 << 3);

	//STEP 2: SET THE MODE TO OUTPUT
	*GPIO_MODER_p |= (1 << 28);

	//STEP 3: ENABLE THE LED PIN
	*GPIO_ODR |= (1 << 14);


	while(1);
}
