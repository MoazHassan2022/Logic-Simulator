#include "Delete.h"
#include "../ApplicationManager.h"

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
}

Delete::~Delete(void)
{
}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Action: Delete, Click on any component");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Delete::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	int CompCount = pManager->GetCompCount();
	Component* CompList[200];
	pManager->GetCompList(CompList);
	GraphicsInfo GInfoCm;
	bool found = false;
	for (int i = 0; i < CompCount; i++) {
		GInfoCm = CompList[i]->Getm_GfxInfo();
		if (CompList[i]->GetIsConn() == false) {
			if ((x > GInfoCm.x1) && (x < GInfoCm.x2) && (y > GInfoCm.y1) && (y < GInfoCm.y2))
			{
				GraphicsInfo GInfoCm2;

				//delete for connecetion
				for (int k = 0; k < CompCount; k++)
				{
					GInfoCm2 = CompList[k]->Getm_GfxInfo();
					if (CompList[k]->GetIsConn()) {
						if (dynamic_cast<LED*>(CompList[i])) {
							if (((GInfoCm2.x1 >= GInfoCm.x1 + 25 - 5) && (GInfoCm2.x1 <= GInfoCm.x2 + 25 + 5) && (GInfoCm2.y1 <= GInfoCm.y2 + 5) && (GInfoCm2.y1 >= GInfoCm.y2 - 5)) ||
								((GInfoCm2.x2 >= GInfoCm.x1 + 25 - 5) && (GInfoCm2.x2 <= GInfoCm.x2 + 25 + 5) && (GInfoCm2.y2 <= GInfoCm.y2 + 5) && (GInfoCm2.y2 >= GInfoCm.y2 - 5)))
								pManager->RemoveComponent(k);
						}
						if (((GInfoCm2.x1 >= GInfoCm.x2 - 5) && (GInfoCm2.x1 <= GInfoCm.x2 + 5) &&
							(GInfoCm2.y1 <= GInfoCm.y2 - 25 + 5) && (GInfoCm2.y1 >= GInfoCm.y2 - 25 - 5)) ||
							((GInfoCm2.x2 >= GInfoCm.x2 - 5) && (GInfoCm2.x2 <= GInfoCm.x2 + 5) &&
								(GInfoCm2.y2 <= GInfoCm.y2 - 25 + 5) && (GInfoCm2.y2 >= GInfoCm.y2 - 25 - 5)) ||
							(((GInfoCm2.x2 <= GInfoCm.x1 + 5) && (GInfoCm2.x2 >= GInfoCm.x1 - 5)) &&
								((GInfoCm2.y2 <= GInfoCm.y1 + 15 + 5) && (GInfoCm2.y2 >= GInfoCm.y1 + 15 - 5)) ||
								((GInfoCm2.y2 <= GInfoCm.y1 + 25 + 5) && (GInfoCm2.y2 >= GInfoCm.y1 + 25 - 5)) ||
								((GInfoCm2.y2 <= GInfoCm.y1 + 35 + 5) && (GInfoCm2.y2 >= GInfoCm.y1 + 35 - 5))) ||
							(((GInfoCm2.x1 <= GInfoCm.x1 + 5) && (GInfoCm2.x1 >= GInfoCm.x1 - 5)) &&
								((GInfoCm2.y1 <= GInfoCm.y1 + 15 + 5) && (GInfoCm2.y1 >= GInfoCm.y1 + 15 - 5)) ||
								((GInfoCm2.y1 <= GInfoCm.y1 + 25 + 5) && (GInfoCm2.y1 >= GInfoCm.y1 + 25 - 5)) ||
								((GInfoCm2.y1 <= GInfoCm.y1 + 35 + 5) && (GInfoCm2.y1 >= GInfoCm.y1 + 35 - 5))))
						{

							pManager->RemoveComponent(k);
						}
					}
				}
				pManager->RemoveComponent(i);
				found = true;
			}
			
		}
	}
	if (!found) {
		for (int i = 0; i < CompCount; i++) {
			GInfoCm = CompList[i]->Getm_GfxInfo();
			if (CompList[i]->GetIsConn() == true) {
				if (((x >= GInfoCm.x1 - 1) && (x <= GInfoCm.x2 + 1) && (y <= GInfoCm.y1 + 1) && (y >= GInfoCm.y2 - 1)) || ((x >= GInfoCm.x1 - 1) && (x <= GInfoCm.x2 + 1) && (y >= GInfoCm.y1 - 1) && (y <= GInfoCm.y2 + 1)) || ((x <= GInfoCm.x1 + 1) && (x >= GInfoCm.x2 - 1) && (y <= GInfoCm.y1 + 1) && (y >= GInfoCm.y2 - 1)) || ((x <= GInfoCm.x1 + 1) && (x >= GInfoCm.x2 + 1) && (y >= GInfoCm.y1 - 1) && (y <= GInfoCm.y2 + 1))) {
					pManager->RemoveComponent(i);
				}
			}
		}
	}

}

void Delete::Undo()
{}

void Delete::Redo()
{}

