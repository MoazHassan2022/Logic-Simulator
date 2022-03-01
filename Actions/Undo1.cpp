#include "Undo1.h"


Undo1::Undo1(ApplicationManager *pApp):Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

Undo1::~Undo1(void)
{
}

void Undo1::ReadActionParameters()
{
}

void Undo1::Execute()
{
	Action* LastAct = pManager->undooo();
	if (LastAct != NULL) {
		LastAct->Undo();
	}
}

void Undo1::Undo()
{}

void Undo1::Redo()
{}


