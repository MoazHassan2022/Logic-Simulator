#pragma once
#include "action.h"
#include "../ApplicationManager.h"

class GateBar: public Action
{
private:
	Output* pOut;
	Input *pIn;
public:
	GateBar(ApplicationManager *pApp);
	virtual ~GateBar(void);

	virtual void Execute();

	virtual void ReadActionParameters();
	virtual void Undo();
	virtual void Redo();
};

