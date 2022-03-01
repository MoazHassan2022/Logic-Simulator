#include "AddNANDgate2.h"
#include "..\ApplicationManager.h"

AddNANDgate2::AddNANDgate2(ApplicationManager *pApp) :Action(pApp)
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	selected = false;
}

AddNANDgate2::~AddNANDgate2(void)
{
}

void AddNANDgate2::ReadActionParameters()
{
	//Print Action Message
	pOut->PrintMsg("2-Input NAND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNANDgate2::Execute()
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
	pA = new NAND2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
	AddNANDgate2* pAND = new AddNANDgate2(pManager);
	// first you should make copy of the the action
	AddNANDgate2* uuu = new AddNANDgate2(pManager);
	*uuu = *this;
	//then call the function that get you the list and push back the cpoied action
	pManager->getlist().push_back(uuu);
}

void AddNANDgate2::Undo()
{
	//here is for components only when make undo just delete the last gate
	int CompCount = pManager->GetCompCount();
	pManager->RemoveComponent(CompCount - 1);
}

void AddNANDgate2::Redo()
{
	//here you should make new component with same info and add it to the comlist from AddComponent
	pA = new NAND2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

