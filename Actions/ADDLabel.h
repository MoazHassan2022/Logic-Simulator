#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class AddLabel : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int q, e; // e is counter to determind the text that should to be display
	GraphicsInfo comp;
	Component* CompListv[200];
	Output* pOut;
	Input* pIn;


public:
	AddLabel(ApplicationManager* pApp);
	virtual ~AddLabel();

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

	



};
