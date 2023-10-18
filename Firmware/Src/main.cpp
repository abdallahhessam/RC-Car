#include "main.h"
#include "uart.h"
#include "mcal.h"
#include "motor.h"


int main(void)
{
 	 USART *ble = new(USART1Instance) USART(USART1Instance);
 	 RCC->APB2ENR |= (1<<2);
 	 RCC->APB2ENR |= (1<<3);
 	 RCC->APB2ENR |= (1<<4);

 	 GPIOC->CRH = (3<<20);
     GPIOC->CRH |= (3<<24);


 	 GPIOA->CRL  = (3<<20); //A5 M1
 	 GPIOB->CRL  = (3<<4);  //B1 M1
 	 GPIOA->CRL |= (3<<24); //A6 M1
 	 GPIOA->CRL |= (3<<16); //A4 M2
 	 GPIOA->CRL |= (3<<0);  //A0 M2
 	 GPIOB->CRL |= (3<<0);  //B0 M2

 	 GPIOA->CRL |= (3<<12); //A3 Front light
  	 GPIOB->CRH  = (3<<4);  //B9 Horn

 	 Motor m1(motor1_config);
 	 Motor m2(motor2_config);
 	 Robot robot(m1, m2);
 	 while (1)
  {
	 char control= ble->read();
	 switch (control) {
     case 'F':
//		  ble->sendString("Car Forward\r\n");
		  robot.Forward();
		  GPIOC->ODR = (1<<13);
       break;
     case 'B':
//		  ble->sendString("Car Backward\r\n");
		  robot.Backward();
		  GPIOC->ODR = (1<<13);
       break;
     case 'L':
//		  ble->sendString("Car Turn Left\r\n");
		  robot.Left();
		  GPIOC->ODR = (1<<14);
       break;
     case 'R':
//		  ble->sendString("Car Turn Right\r\n");
		  robot.Right();
		  GPIOC->ODR = (1<<14);
       break;
     case 'S':
//		  ble->sendString("Car Stop\r\n");
		  robot.Stop();
		  GPIOC->ODR &=~ (1<<13);
		  GPIOC->ODR &=~ (1<<14);
       break;
     case 'W':
//		  ble->sendString("Car Front light ON\r\n");
		  GPIOA->ODR = (1<<3);
      break;
     case 'w':
//		  ble->sendString("Car Front light OFF\r\n");
    	  GPIOA->ODR &=~ (1<<3);
    	break;
     case 'V':
//		  ble->sendString("Car Horn ON\r\n");
		  GPIOB->ODR = (1<<9);
      break;
     case 'v':
//		  ble->sendString("Car Horn OFF\r\n");
		  GPIOB->ODR &=~ (1<<9);
      break;
	}
  }
}
