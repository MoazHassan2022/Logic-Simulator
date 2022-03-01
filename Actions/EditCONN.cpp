#include "EditCONN.h"


EditCONN::EditCONN(ApplicationManager* pApp) :Action(pApp), O(0)
{
	pManager->GetCompList(CompListv);
	compcount= pManager->GetCompCount();
};

//Reads parameters required for action to execute
void EditCONN::ReadActionParameters() {

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	int x, y;

	pOut->PrintMsg("Editing Connection: select the pin you want to change");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	q1 = DetectComponent(x, y);

	int Found = -2;
	int Found2 = -2;
	switch(q1)
	{
	case 1:
		mGfxInfo.x1 = x; mGfxInfo.y1 = y;

		for (int i = 0; i < compcount; i++){
			if(CompListv[i]->GetIsConn() == 1){
				GraphicsInfo OldCONN = CompListv[i]->Getm_GfxInfo();

				if(((mGfxInfo.x1 >= OldCONN.x2 -2)&&(mGfxInfo.x1 <= OldCONN.x2 +2))&&((mGfxInfo.y1 >= OldCONN.y2 -2)&&(mGfxInfo.y1 <= OldCONN.y2 +2))){
					mGfxInfo.x2 = OldCONN.x1; mGfxInfo.y2 = OldCONN.y1;
					O = CompListv[i]->Getm_OutputPin();
					src = CompListv[i]; //nlknknlkn
					Found = i;
					pOut->PrintMsg("Editing Connection: select the new pin");
					pIn->GetPointClicked(x, y);
					pOut->ClearStatusBar();
					q2 = DetectComponent(x, y);

					switch (q2)
					{
					case 1:
						mGfxInfo.x1 = x; mGfxInfo.y1 = y;
						break;

					case -1:
						mGfxInfo.x1 = x; mGfxInfo.y1 = y;
						break;

					default:
						break;
					}
				}
				else if(((mGfxInfo.x1 >= OldCONN.x1 -2)&&(mGfxInfo.x1 <= OldCONN.x1 +2))&&((mGfxInfo.y1 >= OldCONN.y1 -2)&&(mGfxInfo.y1 <= OldCONN.y1 +2))){
					mGfxInfo.x2 = OldCONN.x2; mGfxInfo.y2 = OldCONN.y2;
					O = CompListv[i]->Getm_OutputPin();
					src = CompListv[i]; //nlknknlkn
					Found = i;
					pOut->PrintMsg("Editing Connection: select the new pin");
					pIn->GetPointClicked(x, y);
					pOut->ClearStatusBar();
					q2 = DetectComponent(x, y);


					switch (q2)
					{
					case 1:
						mGfxInfo.x1 = x; mGfxInfo.y1 = y;
						break;

					case -1:
						mGfxInfo.x1 = x; mGfxInfo.y1 = y;
						break;

					default:
						break;
					}
				}
			}
		}
		if(Found!=-2)
			pManager->RemoveComponent(Found);
		break;

	case -1:

		mGfxInfo.x1 = x; mGfxInfo.y1 = y;
		for (int i = 0; i < compcount; i++){
			if(CompListv[i]->GetIsConn() == 1){
				GraphicsInfo OldCONN = CompListv[i]->Getm_GfxInfo();
				if(((mGfxInfo.x1 >= OldCONN.x1 -2)&&(mGfxInfo.x1 <= OldCONN.x1 +2))&&((mGfxInfo.y1 >= OldCONN.y1 -2)&&(mGfxInfo.y1 <= OldCONN.y1 +2))){
					mGfxInfo.x2 = OldCONN.x2; mGfxInfo.y2 = OldCONN.y2;
					Connection* P = dynamic_cast<Connection*>(CompListv[i]);
					DstPinN = P->GetdstPnN();
					I = CompListv[i]->Getm_InputPin(DstPinN);
					dst = CompListv[i]; //lmllnklnknj
					Found2 = i;
					pOut->PrintMsg("Editing Connection: select the new pin");
					pIn->GetPointClicked(x, y);
					pOut->ClearStatusBar();
					q2 = DetectComponent(x, y);


					switch (q2)
					{
					case 1:
						mGfxInfo.x1 = x; mGfxInfo.y1 = y;
						break;

					case -1:
						mGfxInfo.x1 = x; mGfxInfo.y1 = y;
						break;

					default:
						break;
					}
				}

				else if(((mGfxInfo.x1 >= OldCONN.x2 -2)&&(mGfxInfo.x1 <= OldCONN.x2 +2))&&((mGfxInfo.y1 >= OldCONN.y2 -2)&&(mGfxInfo.y1 <= OldCONN.y2 +2))){
					mGfxInfo.x2 = OldCONN.x1; mGfxInfo.y2 = OldCONN.y1;
					Connection* P = dynamic_cast<Connection*>(CompListv[i]);
					DstPinN = P->GetdstPnN();
					I = CompListv[i]->Getm_InputPin(DstPinN);
					dst = CompListv[i]; //lmllnklnknj
					Found2 = i;
					pOut->PrintMsg("Editing Connection: select the new pin");
					pIn->GetPointClicked(x, y);
					pOut->ClearStatusBar();
					q2 = DetectComponent(x, y);


					switch (q2)
					{
					case 1:
						mGfxInfo.x1 = x; mGfxInfo.y1 = y;
						break;

					case -1:
						mGfxInfo.x1 = x; mGfxInfo.y1 = y;
						break;

					default:
						break;
					}
				}
			}
		}
		if(Found2 != -2)
			pManager->RemoveComponent(Found2);
		break;

	default:
		break;
	}



};


//Execute action (code depends on action type)
void EditCONN::Execute() {

	ReadActionParameters();
	if(((q1 == -1)&&(q2 == 1))||((q1 == 1)&&(q2 == -1))||((q1 == 1)&&(q2 == 1))||((q1 == -1)&&(q2 == -1))){
		pManager->UpdateInterface();
		pA = new Connection(mGfxInfo, O , I, src, dst, DstPinN);
		pManager->AddComponent(pA);
		EditCONN* pAND = new EditCONN(pManager);
		EditCONN* uuu = new EditCONN(pManager);
		*uuu = *this;
		//then call the function that get you the list and push back the cpoied action
		pManager->getlist().push_back(uuu);
	}
};

void EditCONN::Undo() {
	int CompCount = pManager->GetCompCount();
	pManager->RemoveComponent(CompCount - 1);
};
void EditCONN::Redo() {
	pA = new Connection(mGfxInfo, O , I, src, dst, DstPinN);
	pManager->AddComponent(pA);
};


int EditCONN::DetectComponent(int xi,int y1) {

	for (int i = 0; i < compcount; i++)
	{
		int v = detectPin( xi,  y1, CompListv[i]);
		if (v == 0 || v == 1 || v == 2 || v == -1) {

			if (v == 0 || v == 1 || v == 2)
			{
				I = CompListv[i]->Getm_InputPin(v);
				dst = CompListv[i];
				DstPinN = v;
				return 1;
			}
			else if (v == -1) {
				O = CompListv[i]->Getm_OutputPin();
				src = CompListv[i];
				return -1;
			}

		}

	}


	return 0;
};


int EditCONN::detectPin(int xi, int yi, Component * comp) {

	GraphicsInfo cp = comp->Getm_GfxInfo();
	int x = comp->Getm_Inputs();
	if (x == 3) {
		if( (xi > cp.x1 - 8) && (xi < cp.x1 + 8)){
			if (  (yi < cp.y1 +15 + 5) && (yi > cp.y1 + 15 - 5)) {
				// this is the input 1
				return 0;
			}
			else if ( (yi < cp.y1 + 25 + 5) && (yi > cp.y1 + 25 - 5) )
			{
				// this is the input 2
				return 1;
			}
			else if ( (yi < cp.y1 + 35 + 5) && (yi > cp.y1 + 35 - 5) )
			{
				// this is the input 3
				return 2;
			}
		}
		else if((xi > cp.x2 - 8) && (xi < cp.x2 + 8))
		{
			if ((yi < cp.y1 + 25 + 8) && (yi > cp.y1 + 25 - 8)) {
				//this is the output 
				return -1;
			}
		}

		//end of the gate has 3-inputs
	}
	else if (x == 2) {
		if ((xi > cp.x1 - 8) && (xi < cp.x1 + 8)) {
			if ((yi < cp.y1 + 15 + 5) && (yi > cp.y1 + 15 - 5)) {
				// this is the input 1
				return 0;
			}
			else if ((yi < cp.y1 + 35 + 5) && (yi > cp.y1 + 35 - 5))
			{
				// this is the input 2
				return 1;
			}
		}	
		else if ((xi > cp.x2 - 8) && (xi < cp.x2 + 8))
		{
			if ((yi < cp.y1 + 25 + 8) && (yi > cp.y1 + 25 - 8)) {
				//this is the output 
				return -1;
			}
		}
		//end of the gate has 2-inputs
	}
	else if (x == 1) {
		if ((xi > cp.x1 +25 - 8) && (xi < cp.x1 +25 + 8)) {
			if ((yi < cp.y2 + 5) && (yi > cp.y2 - 5)) {
				// this is the input of led
				return 0;
			}
		}
		else if ((xi > cp.x1 - 8) && (xi < cp.x1 + 8)) {
			if ((yi < cp.y1 + 25 + 5) && (yi > cp.y1 + 25 - 5)) {
				// this is the input 1 of a gate
				return 0;
			}
		}
		else if ((xi > cp.x2 - 8) && (xi < cp.x2 + 8))
		{
			if ((yi < cp.y1 + 25 + 8) && (yi > cp.y1 + 25 - 8)) {
				//this is the output 
				return -1;
			}
		}
		//end of the LED has 1-inputs
	}
	else if(x == 0){
		if ((xi > cp.x1 - 8) && (xi < cp.x1 + 8)) {
			if ((yi < cp.y1 + 25 + 5) && (yi > cp.y1 + 25 - 5)) {
				// this is the input 1
				return -1;
			}
		}
		else if ((xi > cp.x2 - 8) && (xi < cp.x2 + 8))
		{
			if ((yi < cp.y1 + 25 + 8) && (yi > cp.y1 + 25 - 8)) {
				//this is the output 
				return -1;
			}
		}
	}



	return 9;
};




EditCONN::~EditCONN() {};



