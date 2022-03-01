#include "Select.h"
#include "../ApplicationManager.h"

Select::Select(ApplicationManager *pApp):Action(pApp)
{
}

Select::~Select(void)
{
}

void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message


	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Select::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	int CompCount = pManager->GetCompCount();
	Component* CompList[200];
	pManager->GetCompList(CompList);
	GraphicsInfo GInfoCm;
	for(int i = 0; i<CompCount; i++){
		GInfoCm = CompList[i]->Getm_GfxInfo();
		int j = CompList[i]->Getm_Inputs();
		Component * c1 = dynamic_cast<LED*>(CompList[i]);
		Component* c2 = dynamic_cast<SWITCH*>(CompList[i]);
		if((c1 == NULL) && (c2 == NULL)){
			if(CompList[i]->GetIsConn() == true){
				if(((x>=GInfoCm.x1-1)&&(x<=GInfoCm.x2+1)&&(y<=GInfoCm.y1+1)&&(y>=GInfoCm.y2-1))||((x>=GInfoCm.x1-1)&&(x<=GInfoCm.x2+1)&&(y>=GInfoCm.y1-1)&&(y<=GInfoCm.y2+1))||((x<=GInfoCm.x1+1)&&(x>=GInfoCm.x2-1)&&(y<=GInfoCm.y1+1)&&(y>=GInfoCm.y2-1))||((x<=GInfoCm.x1+1)&&(x>=GInfoCm.x2+1)&&(y>=GInfoCm.y1-1)&&(y<=GInfoCm.y2+1))){
				bool WasSelected = CompList[i]->GetIsSelected();
				if(WasSelected==true){
					CompList[i]->SetIsSelected(false);
				}
				else{
					CompList[i]->SetIsSelected(true);
				}
				}
			}
			else if(((x>GInfoCm.x1)&&(x<GInfoCm.x2))&&((y>GInfoCm.y1)&&(y<GInfoCm.y2))){
				bool WasSelected = CompList[i]->GetIsSelected();
				if(WasSelected==true){
					CompList[i]->SetIsSelected(false);
				}
				else{
					CompList[i]->SetIsSelected(true);
				}

			}
		}


	}
}


void Select::Undo()
{}

void Select::Redo()
{}