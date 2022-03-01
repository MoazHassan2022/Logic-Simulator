#include "ChangeSWCH.h"
#include "../ApplicationManager.h"

ChangeSWCH::ChangeSWCH(ApplicationManager *pApp):Action(pApp)
{
}

ChangeSWCH::~ChangeSWCH(void)
{
}

void ChangeSWCH::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Please click on the switch");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void ChangeSWCH::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	int CompCount = pManager->GetCompCount();
	Component* CompList[200];
	pManager->GetCompList(CompList);
	GraphicsInfo GInfoCm;
	for(int i = 0; i<CompCount; i++){
		GInfoCm = CompList[i]->Getm_GfxInfo();
		if (dynamic_cast<SWITCH*>(CompList[i])) {
			if (((x > GInfoCm.x1) && (x < GInfoCm.x2)) && ((y > GInfoCm.y1) && (y < GInfoCm.y2))) {
				int S = CompList[i]->GetOutPinStatus();
				if (S == 1) {
					CompList[i]->setOutputStatus(LOW);
					CompList[i]->SetIsSelected(false);
				}
				else {
					CompList[i]->setOutputStatus(HIGH);
					CompList[i]->SetIsSelected(true);
				}
			}
		}
	}
}


void ChangeSWCH::Undo()
{}

void ChangeSWCH::Redo()
{}