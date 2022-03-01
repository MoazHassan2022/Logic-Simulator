#include "DESTROYGATES.h"
#include "..\ApplicationManager.h"

DESTROYGATES::DESTROYGATES(ApplicationManager *pApp) :Action(pApp)
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
}

DESTROYGATES::~DESTROYGATES(void)
{}

void DESTROYGATES::Execute()
{
	pOut->ClearGatesToolBar();
}

void DESTROYGATES::ReadActionParameters()
{}

void DESTROYGATES::Undo()
{
}

void DESTROYGATES::Redo()
{
}