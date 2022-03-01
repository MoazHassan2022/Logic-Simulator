#include "SAV.h"
#include <fstream>
#include <iostream>
#include "../ApplicationManager.h"
using namespace std;


SAV::SAV(ApplicationManager* pApp) :Action(pApp) {}
SAV::~SAV() {}

void SAV::ReadActionParameters() {}

void SAV::Execute() 
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	Component* sc;
	Component* dc;
	int PN;
	int sID = 0;
	int dID = 0;

	ReadActionParameters();
	int CompCount = pManager->GetCompCount();
	Component* CompList[200];
	pManager->GetCompList(CompList);
	ofstream fsav ;
	fsav.open("Circuit.txt");
	if (fsav.is_open())
	{
		fsav << CompCount << endl;
		for (int i = 0; i < CompCount; i++)
		{
			if(!(CompList[i]->GetIsConn()))
			CompList[i]->sav( fsav, i);
		}
		fsav << "Connections" << endl;

		for (int i = 0; i < CompCount; i++)
		{
			if (CompList[i]->GetIsConn())
			{
				sc = (dynamic_cast<Connection*>(CompList[i]))->GetSrcComp();
				dc = (dynamic_cast<Connection*>(CompList[i]))->GetDstComp();
				PN = (dynamic_cast<Connection*>(CompList[i]))->GetdstPnN();
				if (PN == 0 || PN == 1 || PN == 2)
				{

				}
				else
				{
					PN = -1;
				}

				for (int j = 0; j < CompCount; j++)
				{
					if (sc == CompList[j])
					{
						sID = j;
					}
					if (dc == CompList[j])
					{
						dID = j;
					}
				}



				fsav << sID << "    " << dID << "    " << PN +1  << endl;

			}
		}

	}
	fsav << "-1\n";
	fsav.close();
	pOut->PrintMsg("Saved Successfully to file {Circuit.txt} ");

}

void SAV::Undo() {}

void SAV::Redo() {}
