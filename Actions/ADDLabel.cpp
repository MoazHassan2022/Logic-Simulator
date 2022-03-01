#include "AddLabel.h"
#include <iostream>


AddLabel::AddLabel(ApplicationManager* pApp) :Action(pApp),e(0)
{
	pManager->GetCompList(CompListv);
};

//Reads parameters required for action to execute
void AddLabel::ReadActionParameters() {


	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	int x, y;

	pOut->PrintMsg("Add label: Click on a component to add label to it");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	q = pManager->Iscomp(x,y,comp);
	if(q != -1)
		CompListv[q]->Label[e] = pIn->GetSrting(pOut);
};


//Execute action (code depends on action type)
void AddLabel::Execute() {
	ReadActionParameters();
	if(q != -1){
		CompListv[q]->setLabel(CompListv[q]->Label[e]);
		e++;
		AddLabel* pAND = new AddLabel(pManager);

		//then call the function that get you the list and push back the cpoied action
		
	}
};

void AddLabel::Undo() {
	Output* pOut = pManager->GetOutput();
	if(!CompListv[q]->Label[--e].empty() ){
		CompListv[q]->setLabel(CompListv[q]->Label[e]);
	}
	else
	{
		e++;
		pOut->PrintMsg("there is no label to undo doing it");
	}


};
void AddLabel::Redo() {
	Output* pOut = pManager->GetOutput();
	if (!CompListv[q]->Label[++e].empty()) {
		CompListv[q]->setLabel(CompListv[q]->Label[e]);
	}
	else
	{
		e--;
		pOut->PrintMsg("there is no label to redo it");
	}
};


AddLabel::~AddLabel() {};