#pragma once
#include "Action.h"
#include "..\Components\LED.h"

class AddLED: public Action
{
private:
	//Parameters for rectangular area to be occupied by the led
	int Cx, Cy;	//Center point of the led
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	bool selected; //Tells whether the component is selected or not

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut;
	Input* pIn;

	LED *pA;	//Pointer to led

	GraphicsInfo GInfo; //Gfx info to be used to construct the LED

public:
	AddLED(ApplicationManager *pApp);
	virtual ~AddLED(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();



};

