#include "AddINV.h"
#include "..\ApplicationManager.h"

AddINV::AddINV(ApplicationManager *pApp) :Action(pApp)
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	selected = false;
}

AddINV::~AddINV(void)
{
}

void AddINV::ReadActionParameters()
{
	//Print Action Message
	pOut->PrintMsg("Inverter Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddINV::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	pA = new INV(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
	AddINV* pAND = new AddINV(pManager);
	// first you should make copy of the the action
	AddINV* uuu = new AddINV(pManager);
	*uuu = *this;
	//then call the function that get you the list and push back the cpoied action
	pManager->getlist().push_back(uuu);
}

void AddINV::Undo()
{
	//here is for components only when make undo just delete the last gate
	int CompCount = pManager->GetCompCount();
	pManager->RemoveComponent(CompCount - 1);
}

void AddINV::Redo()
{
	//here you should make new component with same info and add it to the comlist from AddComponent
	pA = new INV(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}


