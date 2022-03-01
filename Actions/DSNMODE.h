#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class DSNMODE: public Action
{
private:
	//Get a Pointer to the Input / Output Interfaces
	Output * pOut;
	Input * pIn;
public:
	DSNMODE(ApplicationManager *pApp);
	virtual ~DSNMODE(void);

	virtual void Execute();

	virtual void ReadActionParameters();
	virtual void Undo();
	virtual void Redo();
};

