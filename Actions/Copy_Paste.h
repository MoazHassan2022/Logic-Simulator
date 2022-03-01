#ifndef _COPY_PASTE_H
#define _COPY_PASTE_H
#include "Action.h"
#include "../Components/Component.h"


class Copy_Paste :	public Action
{

private:
	int x,y;
	
public:
	Copy_Paste(ApplicationManager *pApp);
	virtual ~Copy_Paste(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif