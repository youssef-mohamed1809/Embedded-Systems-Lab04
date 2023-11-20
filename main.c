#include "tm4c123gh6pm.h"
#include "dio.h"

#define NUM_POSITION 2


int main(void){
        int nums[] = {1, 2, 3, 4, 5};
    Dio_Init('F');
    if((!DIO_ReadPin(GPIO_PORTF_DATA_R, 0) && !DIO_ReadPin(GPIO_PORTF_DATA_R, 4))){
        Dio_WritePort(GPIO_PORTF_DATA_R, 0x1E);
    }
    else if(nums[NUM_POSITION] % 2 == 0 && (!DIO_ReadPin(GPIO_PORTF_DATA_R, 0) || !DIO_ReadPin(GPIO_PORTF_DATA_R, 4))){
        Dio_WritePin(GPIO_PORTF_DATA_R, 2, 1);
    }else if(nums[NUM_POSITION] % 2 == 1 && (!DIO_ReadPin(GPIO_PORTF_DATA_R, 0) || !DIO_ReadPin(GPIO_PORTF_DATA_R, 4))){
        Dio_WritePin(GPIO_PORTF_DATA_R, 1, 1);
    }
    return 0;
}