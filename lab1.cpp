#include "hal.h"

bool break_animation = false; bool break_animation_nBTN = false;
unsigned int leds_num[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5,
                      GPIO_PIN_6, GPIO_PIN_8, GPIO_PIN_9,
                      GPIO_PIN_11, GPIO_PIN_12};
unsigned int sw_num[] = {GPIO_PIN_4, GPIO_PIN_8, GPIO_PIN_10, GPIO_PIN_12};
GPIO_PinState sw_now[4];



void turn_off_the_lights()
{
    for (int i = 0; i < 8; i++)
    {
        HAL_GPIO_WritePin(GPIOD, leds_num[i], GPIO_PIN_RESET);
    }
}

void cadr(int* i)
{
    if(*i == 0){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_SET);
    }
    else if(*i == 1){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(*i == 2){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(*i == 3){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(*i == 4){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(*i == 5){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_SET);
    }
    else if(*i == 6){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(*i == 7){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(*i == 8){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(*i == 9){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(*i == 10){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }
    else if(*i == 11){
        HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
    }

    *i += 1;
    *i %= 12;
}

void default_lights(){
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

void SW_mode(){
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

void nBTN_mode(){
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
}

bool check_SW(bool flag)
{
    while(1) {    
        for(int i = 0; i < 4; i++)
        {
            sw_now[i] = HAL_GPIO_ReadPin(GPIOE, sw_num[i]);
        }

        if (!sw_now[0] && sw_now[1] && !sw_now[2] && !sw_now[3])
        {
            break_animation = false;  
            flag = false; 
            return flag;
        }

        if(!flag){
            flag = true;
        }
        break_animation = true;
        turn_off_the_lights();
        for(int i = 0; i < 4; i++)
        {
            HAL_GPIO_WritePin(GPIOD, leds_num[i], sw_now[i]);
        }
        return flag;
    }
}

bool check_nBTN(bool flag, bool sw_flag) 
{
    if(sw_flag){
        return flag;
    }

    GPIO_PinState state = GPIO_PIN_SET;
    int i = 0;

    while(i < 500){
        state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15);
        if((state == GPIO_PIN_RESET) && (break_animation_nBTN == false))
        {
            if(!flag){
                flag = true;
            }
            break_animation_nBTN = true;
            break;
        }
        else if((state == GPIO_PIN_RESET) && (break_animation_nBTN == true)){
            break_animation_nBTN = false;
            flag = false;
            break;
        }
        i += 1;
    }

    if((state == GPIO_PIN_SET) && (flag == true)){
        break_animation_nBTN = true;
    }

    return flag;
}

int umain()
{
    int* counter;
    *counter = 0;
    bool sw_flag = false;
    bool nBTN_flag = false;

    while(1) {
        sw_flag = check_SW(sw_flag);
        HAL_Delay(500);
        nBTN_flag = check_nBTN(nBTN_flag, sw_flag);

        if(sw_flag){
            SW_mode();          
        }
        else if(nBTN_flag){
            nBTN_mode();
        }
        else{
            default_lights();
        }

        if (!(break_animation || break_animation_nBTN)) 
        {
            cadr(counter);
        }
        
    }
    return 0;
}