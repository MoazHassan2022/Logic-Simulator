#pragma once
#include "Action.h"
#include "..\Components\SWITCH.h"

class AddSWITCH : public Action
{
private:
	//Parameters for rectangular area to be occupied by the switch
	int Cx, Cy;	//Center point of the switch
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut;
	Input* pIn;

	SWITCH *pA;	//Pointer to switch

	GraphicsInfo GInfo; //Gfx info to be used to construct the Switch

public:
	AddSWITCH(ApplicationManager *pApp);
	virtual ~AddSWITCH(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

