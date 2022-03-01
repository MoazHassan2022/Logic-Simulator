#include "SIMU.h"
#include <iostream>
using namespace std;

SIMU::SIMU(ApplicationManager* pApp) :Action(pApp)
{

}
SIMU::~SIMU() {}

//Reads parameters required for action to execute
void SIMU::ReadActionParameters() {}
//Execute action (code depends on action type)
void SIMU::Execute()
{
	ReadActionParameters();
	int CompCount = pManager->GetCompCount();
	Component* CompList[200];
	pManager->GetCompList(CompList);
	

	/*
		for (int i = 1; i <= UI.width; i++)
			for (int j = 1; j <= UI.height; j++)
				for (int k = 0; k < CompCount; k++)
					if (CompList[k]->Getm_GfxInfo().x1 == i && CompList[k]->Getm_GfxInfo().y1 == j)
						CompList[k]->Operate();
*/
	




	
	for (int w = 0; w < CompCount; w++)
		for (int q = 0; q < CompCount; q++)
			for (int k = 0; k < CompCount; k++)
						CompList[k]->Operate();

						

	



	/*step 1 : Switches
	for (int i = 0; i < CompCount; i++)
	{
		Component* swtchpn = dynamic_cast<SWITCH*>(CompList[i]);
			if (swtchpn)
			{
				CompList[i]->Operate();
			}
	}


	for (int i = 0; i < CompCount; i++)
	{
		Component* ldchk = (dynamic_cast<LED*>(CompList[i]));
		Component* swthchk = (dynamic_cast<SWITCH*>(CompList[i]));


		if (!ldchk && !swthchk)
		{
			CompList[i]->Operate();
		}
	}
	for (int i = 0; i < CompCount; i++)
	{
		Component* ledpb = dynamic_cast<LED *>(CompList[i]);
		if (ledpb)
		{
			CompList[i]->Operate();
		}
	}*/

}

void SIMU::Undo() {}
void SIMU::Redo() {}

