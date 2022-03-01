#ifndef _ChangeSWCH_H
#define _ChangeSWCH_H
#include "Action.h"
#include "../Components\SWITCH.h"
#include "../Components\Component.h"


class ChangeSWCH :	public Action
{

private:
	int x,y;
	
public:
	ChangeSWCH(ApplicationManager *pApp);
	virtual ~ChangeSWCH(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif