#include "hal.h"


const int INITIAL = 500;
const int T = 250;
const int leds_num[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_11, GPIO_PIN_12};
int cnt = 0; 

int frame = 0, mul = 0;

void cadr() {
    if(cnt == 0){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(cnt == 1){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(cnt == 2){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(cnt == 3){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(cnt == 4){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(cnt == 5){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_SET);
    }
    else if(cnt == 6){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_SET);
    }
    else if(cnt == 7){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_SET);
    }

    cnt += 1;
    cnt %= 8;
}

int get_sw_value() {
	unsigned int sw_num[] = {GPIO_PIN_12, GPIO_PIN_10, GPIO_PIN_8, GPIO_PIN_4};
	int num = 0, pow = 1;
	for (int i = 0; i < 4; i++) {
		num += pow * HAL_GPIO_ReadPin(GPIOE, sw_num[i]);
		pow <<= 1;
	}
	return num;
}

void handle_sw() {
	int sw = get_sw_value();
	if (mul != sw) {
		mul = sw;
		WRITE_REG(TIM6_ARR, 500 + mul * T);
	}
}

int umain() {
	registerTIM6_IRQHandler(cadr);
	__enable_irq();

	WRITE_REG(TIM6_ARR, 500);
	WRITE_REG(TIM6_DIER, TIM_DIER_UIE);
	WRITE_REG(TIM6_PSC, 0);

	WRITE_REG(TIM6_CR1, TIM_CR1_CEN);

	while (1) handle_sw();

	return 0;
}