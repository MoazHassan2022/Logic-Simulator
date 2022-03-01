#pragma once
#include "Action.h"
#include "../ApplicationManager.h"


class Redo12 :	public Action
{

private:
	Output* pOut;
	Input* pIn;
	
public:
	Redo12(ApplicationManager *pApp);
	virtual ~Redo12(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();



};
