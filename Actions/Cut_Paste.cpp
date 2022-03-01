#include "Cut_Paste.h"
#include "../ApplicationManager.h"

Cut_Paste::Cut_Paste(ApplicationManager *pApp):Action(pApp)
{
}

Cut_Paste::~Cut_Paste(void)
{
}

void Cut_Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Cut, Please click on the component");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Cut_Paste::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	int CompCount = pManager->GetCompCount();
	Component* CompList[200];
	pManager->GetCompList(CompList);
	GraphicsInfo GInfoCm;
	for(int i = 0; i<CompCount; i++){
		GInfoCm = CompList[i]->Getm_GfxInfo();
		if(((x>GInfoCm.x1)&&(x<GInfoCm.x2))&&((y>GInfoCm.y1)&&(y<GInfoCm.y2))){
			pManager->AddClipb(i);
			pManager->ClipExecute();
			pManager->RemoveComponent(i);
		}
	}


}


void Cut_Paste::Undo()
{}

void Cut_Paste::Redo()
{}