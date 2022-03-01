#include "SimMode.h"


SimMode::SimMode(ApplicationManager *pApp):Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->PrintMsg("Action: Activating Simulation mode");
}

SimMode::~SimMode(void)
{
}

void SimMode::ReadActionParameters()
{
}

void SimMode::Execute()
{
	pOut->CreateSimulationToolBar();
}


void SimMode::Undo()
{}

void SimMode::Redo()
{}