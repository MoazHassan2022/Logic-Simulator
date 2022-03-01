#ifndef _SIMMODE_H
#define _SIMMODE_H
#include "Action.h"
#include "..\ApplicationManager.h"
	

class SimMode :	public Action
{

private:
	Output* pOut;
	Input* pIn;
	
public:
	SimMode(ApplicationManager *pApp);
	virtual ~SimMode(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif