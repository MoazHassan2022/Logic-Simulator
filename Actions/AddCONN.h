#pragma once
#include "Action.h"
#include "../Components\Connection.h"
#include "../ApplicationManager.h"

class AddCONN : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	GraphicsInfo mGfxInfo;
	Component* CompListv[200];
	int compcount;
	InputPin * I;
	OutputPin * O;
	Connection* pA;
	Component* src;
	Component* dst;
	int DstPinN;
	int q1, q2;

public:
	AddCONN(ApplicationManager* pApp);
	virtual ~AddCONN();

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

	//detect if the clicked point is input or output or wrong place
	int DetectComponent(int , int  );

	int detectPin(int xi, int y1, Component *);



};
