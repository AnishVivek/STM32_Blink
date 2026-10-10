#include "stm32f1xx.h" 

void SystemClock_Config(void);
static void MX_GPIO_Init_BareMetal(void);

void main(void)
{
  SystemClock_Config();
  MX_GPIO_Init_BareMetal();

  while (1)
  {
    if ((GPIOA->IDR & (1 << 0)) == 0) 
    {
        GPIOC->ODR |= (1 << 13); 
    }
    else
    {
        GPIOC->ODR &= ~(1 << 13); 
    }
  }
}

static void MX_GPIO_Init_BareMetal(void)
{
  RCC->APB2ENR |= (1 << 2) | (1 << 4);


  GPIOC->CRH &= ~(0xF << 20); 
  GPIOC->CRH |= (0x2 << 20);  
  GPIOC->ODR &= ~(1 << 13);   

  
  GPIOA->CRL &= ~(0xF << 0);
  GPIOA->CRL |= (0x8 << 0);   
  GPIOA->ODR |= (1 << 0);     
}

void SystemClock_Config(void)
{
}
