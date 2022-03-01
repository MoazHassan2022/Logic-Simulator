#pragma once
#include "Action.h"
class Exit :
    public Action
{
public:
    Exit(ApplicationManager* pApp);
    ~Exit();

//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo() ;

	//To redo this action (code depends on action type)
	virtual void Redo() ;
};

