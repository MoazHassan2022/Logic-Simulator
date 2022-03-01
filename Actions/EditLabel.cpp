#include "EditLabel.h"
#include <iostream>


EditLabel::EditLabel(ApplicationManager* pApp) :Action(pApp), e(0)
{
	pManager->GetCompList(CompListv);
};

//Reads parameters required for action to execute
void EditLabel::ReadActionParameters() {


	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	int x, y;

	pOut->PrintMsg("Edit label: click on a component to edit its label");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	q = pManager->Iscomp(x, y, comp);


	if(q != -1)
		CompListv[q]->Label[e] = pIn->GetSrting(pOut);
};


//Execute action (code depends on action type)
void EditLabel::Execute() {
	ReadActionParameters();
	if(q != -1){
		CompListv[q]->setLabel(CompListv[q]->Label[e]);
		e++;
	}
};

void EditLabel::Undo() {
	Output* pOut = pManager->GetOutput();
	if (!CompListv[q]->Label[--e].empty()) {
		CompListv[q]->setLabel(CompListv[q]->Label[e]);
	}
	else
	{
		e++;
		pOut->PrintMsg("there is no label to undo doing it");
	}
};


void EditLabel::Redo() {

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


EditLabel::~EditLabel() {};



