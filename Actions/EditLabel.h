#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class EditLabel : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int q, e;
	GraphicsInfo comp;
	Component* CompListv[200];

public:
	EditLabel(ApplicationManager* pApp);
	virtual ~EditLabel();

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

	//detect if the clicked point is input or output or wrong place



};
