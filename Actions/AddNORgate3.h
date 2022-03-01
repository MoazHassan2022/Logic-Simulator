#pragma once
#include "action.h"
#include "..\Components\NOR3.h"

class AddNORgate3: public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	bool selected; //Tells whether the component is selected or not

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut;
	Input* pIn;

	NOR3 *pA;	//Pointer to AND Gate

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
public:
	AddNORgate3(ApplicationManager *pApp);
	virtual ~AddNORgate3(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

