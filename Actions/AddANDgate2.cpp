#include "AddANDgate2.h"
#include "..\ApplicationManager.h"
#include <iostream>

AddANDgate2::AddANDgate2(ApplicationManager *pApp):Action(pApp)
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
}

AddANDgate2::~AddANDgate2(void)
{
}

void AddANDgate2::ReadActionParameters()
{
	//Print Action Message
	pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	pA=new AND2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
	AddANDgate2* pAND = new AddANDgate2(pManager);
	// first you should make copy of the the action
	AddANDgate2* uuu = new AddANDgate2(pManager);
	*uuu = *this;
	//then call the function that get you the list and push back the cpoied action
	pManager->getlist().push_back(uuu);

}

void AddANDgate2::Undo()
{
	//here is for components only when make undo just delete the last gate
	int CompCount = pManager->GetCompCount();
	pManager->RemoveComponent(CompCount - 1);
}

void AddANDgate2::Redo()
{
	//here you should make new component with same info and add it to the comlist from AddComponent
	pA = new AND2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
	pOut->PrintMsg("No Label");
}

