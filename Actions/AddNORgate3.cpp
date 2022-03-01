#include "AddNORgate3.h"
#include "..\ApplicationManager.h"

AddNORgate3::AddNORgate3(ApplicationManager *pApp) :Action(pApp)
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	selected = false;
}

AddNORgate3::~AddNORgate3(void)
{
}

void AddNORgate3::ReadActionParameters()
{
	//Print Action Message
	pOut->PrintMsg("3-Input NOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNORgate3::Execute()
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
	pA = new NOR3(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
	AddNORgate3* pAND = new AddNORgate3(pManager);
	// first you should make copy of the the action
	AddNORgate3* uuu = new AddNORgate3(pManager);
	*uuu = *this;
	//then call the function that get you the list and push back the cpoied action
	pManager->getlist().push_back(uuu);
}

void AddNORgate3::Undo()
{
	//here is for components only when make undo just delete the last gate
	int CompCount = pManager->GetCompCount();
	pManager->RemoveComponent(CompCount - 1);
}

void AddNORgate3::Redo()
{
	//here you should make new component with same info and add it to the comlist from AddComponent
	pA = new NOR3(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}
