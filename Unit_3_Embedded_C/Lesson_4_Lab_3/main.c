/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ibrahim Abo Elhassan
 * @brief          : Toggle LED on cortex_M4
 ******************************************************************************
*/

#define SYSCTL_RCGC2_R      (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DATA_R   (*((volatile unsigned long*)0x400253FC))
#define GPIO_PORTF_DIR_R    (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R    (*((volatile unsigned long*)0x4002551C))


int main()
{
    volatile unsigned long delay_count;
    SYSCTL_RCGC2_R = 0x20;

    // wait to make sure that GPIO is up.
    for(delay_count=0 ; delay_count <200 ; delay_count ++);

    GPIO_PORTF_DIR_R |= 1<<3; // making DIR is output at bit 3 in PORTF.
    GPIO_PORTF_DEN_R |= 1<<3;

    while(1)
    {
        GPIO_PORTF_DATA_R |= 1<<3;
        for(delay_count=0 ; delay_count <200000 ; delay_count ++);
        GPIO_PORTF_DATA_R &= ~(1<<3);
        for(delay_count=0 ; delay_count <200000 ; delay_count ++);

    } 

    return 0;
}

