#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class DSNTOOL: public Action
{
private:
	//Get a Pointer to the Input / Output Interfaces
	Output * pOut;
	Input * pIn;
public:
	DSNTOOL(ApplicationManager *pApp);
	virtual ~DSNTOOL(void);

	virtual void Execute();

	virtual void ReadActionParameters();
	virtual void Undo();
	virtual void Redo();
};

