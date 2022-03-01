#include "GateBar.h"
#include "..\ApplicationManager.h"

GateBar::GateBar(ApplicationManager *pApp) :Action(pApp)
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
}

GateBar::~GateBar(void)
{}

void GateBar::Execute()
{
	pOut->CreateGatesToolBar();
}

void GateBar::ReadActionParameters()
{}

void GateBar::Undo()
{}

void GateBar::Redo()
{}