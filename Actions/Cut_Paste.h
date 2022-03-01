#ifndef _CUT_PASTE_H
#define _CUT_PASTE_H
#include "Action.h"
#include "../Components/Component.h"


class Cut_Paste :	public Action
{

private:
	int x,y;
	
public:
	Cut_Paste(ApplicationManager *pApp);
	virtual ~Cut_Paste(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif