#include "Redo12.h"


Redo12::Redo12(ApplicationManager *pApp):Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

Redo12::~Redo12(void)
{
}

void Redo12::ReadActionParameters()
{
}

void Redo12::Execute()
{
	Action* LastAct = pManager->redooo();
	if(LastAct != NULL){
		LastAct->Redo();
	}
}

void Redo12::Undo()
{}

void Redo12::Redo()
{}


