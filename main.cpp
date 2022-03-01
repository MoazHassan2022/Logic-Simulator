
#include <iostream>
#include <sstream>
#include <cmath>

#include "Components/NOR2.h"

#include "ApplicationManager.h"

int main()
{
	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the drawing window
		AppManager.UpdateInterface();
	

	}while(ActType != EXIT);
		
	return 0;
}


/*
	GraphicsInfo comp = m_GfxInfo;
	comp.x1 += 10;	comp.y1 -= 20;
	pOut->showString(comp, this->getlabel());

*/