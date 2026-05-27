#include "led.h"
#include "keyboard.h"


int iTimeDelay;
int iStepCounter;


enum LedState {RIGHT_DIRECTION, LEFT_DIRECTION, STOP, LEFT_RIGHT_5};										//Zadanie 6 //BUTTON 3 5 razy od prawej do lewej




void Delay(int iMiliseconds)
{

  int iLoopIteration;
  iTimeDelay = (iMiliseconds * 5456);

  for(iLoopIteration = 0 ; iLoopIteration < iTimeDelay ; iLoopIteration++)
  {

  }
}


int main()
{
	

	enum LedState eLedState = STOP;													//ZADANIE 6
		
	
  LedInit();
  KeyboardInit();
  while(1)
  {
		

			switch(eLedState)
			{
				case STOP:
					if(eKeyboardRead() == BUTTON_0)
					{
						eLedState = LEFT_DIRECTION;
					}
					if(eKeyboardRead() == BUTTON_2)
					{
						eLedState = RIGHT_DIRECTION;
					}
					else if(eKeyboardRead() == BUTTON_3)
					{
						eLedState = LEFT_RIGHT_5;
					}
					
					break;
					
				  case RIGHT_DIRECTION:
					if(eKeyboardRead() == RELASED)
					{
						LedStepRight();
					}
					else if(eKeyboardRead() == BUTTON_1)
					{
						eLedState = STOP;
					}
					break;
					
					case LEFT_DIRECTION:
					if(eKeyboardRead() == RELASED)
					{
						LedStepLeft();
					}
					else if(eKeyboardRead() == BUTTON_1)
					{
						eLedState = STOP;
					}
					
					break;
					
				case LEFT_RIGHT_5:
					if(eKeyboardRead() == RELASED)
					{
						if(iStepCounter < 20)
						{
							LedStepLeft();
							iStepCounter++;
						}
						else
						{
							iStepCounter = 0;
							eLedState = STOP;
						}
					}
				
					break;	
			}
			Delay(100);
  }
}
