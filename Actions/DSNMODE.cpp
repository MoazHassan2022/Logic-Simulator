#include "DSNMODE.h"
#include "..\ApplicationManager.h"

DSNMODE::DSNMODE(ApplicationManager *pApp) :Action(pApp)
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
}

DSNMODE::~DSNMODE(void)
{}

void DSNMODE::Execute()
{
	pOut->CreateDesignToolBar();
}

void DSNMODE::ReadActionParameters()
{}

void DSNMODE::Undo()
{}

void DSNMODE::Redo()
{}