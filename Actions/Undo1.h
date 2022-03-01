#ifndef _UNDO1_H
#define _UNDO1_H
#include "Action.h"
#include "../ApplicationManager.h"


class Undo1 :	public Action
{

private:
	Output* pOut;
	Input* pIn;
	
public:
	Undo1(ApplicationManager *pApp);
	virtual ~Undo1(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};

#endif