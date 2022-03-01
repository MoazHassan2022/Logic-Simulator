#pragma once
#include "Action.h"
#include "..\Components/Component.h"
#include "..\Components\SWITCH.h"
#include "..\ApplicationManager.h"

class SIMU :public Action
{
private:
	Output* pOut;
	Input* pIn;
public:
	SIMU(ApplicationManager* pApp);
	virtual ~SIMU();

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

