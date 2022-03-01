#include "AddBUFF.h"
#include "..\ApplicationManager.h"

AddBUFF::AddBUFF(ApplicationManager *pApp) :Action(pApp)
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	selected = false;
}

AddBUFF::~AddBUFF(void)
{
}

void AddBUFF::ReadActionParameters()
{
	//Print Action Message
	pOut->PrintMsg("Buffer Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddBUFF::Execute()
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
	pA = new BUFF(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
	AddBUFF* pAND = new AddBUFF(pManager);
	// first you should make copy of the the action
	AddBUFF* uuu = new AddBUFF(pManager);
	*uuu = *this;
	//then call the function that get you the list and push back the cpoied action
	pManager->getlist().push_back(uuu);
}

void AddBUFF::Undo()
{
	//here is for components only when make undo just delete the last gate
	int CompCount = pManager->GetCompCount();
	pManager->RemoveComponent(CompCount - 1);
}

void AddBUFF::Redo()
{
	//here you should make new component with same info and add it to the comlist from AddComponent
	pA = new BUFF(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}


