#include "AddNORgate2.h"
#include "..\ApplicationManager.h"

AddNORgate2::AddNORgate2(ApplicationManager *pApp) :Action(pApp)
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	selected = false;
}

AddNORgate2::~AddNORgate2(void)
{
}

void AddNORgate2::ReadActionParameters()
{
	//Print Action Message
	pOut->PrintMsg("2-Input NOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNORgate2::Execute()
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
	pA = new NOR2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
	AddNORgate2* pAND = new AddNORgate2(pManager);
	// first you should make copy of the the action
	AddNORgate2* uuu = new AddNORgate2(pManager);
	*uuu = *this;
	//then call the function that get you the list and push back the cpoied action
	pManager->getlist().push_back(uuu);
}

void AddNORgate2::Undo()
{
	//here is for components only when make undo just delete the last gate
	int CompCount = pManager->GetCompCount();
	pManager->RemoveComponent(CompCount - 1);
}

void AddNORgate2::Redo()
{
	//here you should make new component with same info and add it to the comlist from AddComponent
	pA = new NOR2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}
