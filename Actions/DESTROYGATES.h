#pragma once
#include "action.h"
#include "../ApplicationManager.h"


class DESTROYGATES : public Action
{
private:
	//Get a Pointer to the Input / Output Interfaces
	Output * pOut;
	Input * pIn;
public:
	DESTROYGATES(ApplicationManager *pApp);
	virtual ~DESTROYGATES(void);

	virtual void Execute();

	virtual void ReadActionParameters();
	virtual void Undo();
	virtual void Redo();
};

