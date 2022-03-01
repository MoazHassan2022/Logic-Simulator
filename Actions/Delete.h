#ifndef _DELETE_H
#define _DELETE_H

#include "Action.h"

#include "../Components\Component.h"

class Delete :	public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int x, y;	//Center point of the gate
	
public:
	Delete(ApplicationManager *pApp);
	virtual ~Delete(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif