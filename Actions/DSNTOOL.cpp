#include "DSNTOOL.h"
#include "..\ApplicationManager.h"

DSNTOOL::DSNTOOL(ApplicationManager *pApp) :Action(pApp)
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
}

DSNTOOL::~DSNTOOL(void)
{}

void DSNTOOL::Execute()
{
	pOut->PrintMsg("Action: a click on the Design Toobar, Click anywhere");
}

void DSNTOOL::ReadActionParameters()
{}

void DSNTOOL::Undo()
{}

void DSNTOOL::Redo()
{}