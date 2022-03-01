#include "ApplicationManager.h"
#include <iostream>

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	Clipb = NULL;



	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	if(pComp->GetIsConn()!=1){
		GraphicsInfo CompG = pComp->Getm_GfxInfo();
		bool NotOverlap = true;
		bool NotOverlap2 = true;
		if(!((CompG.y1 > 2 * UI.ToolBarHeight) && (CompG.y2 < UI.height -UI.StatusBarHeight)))
			NotOverlap = false;
		for(int i = 0; i<CompCount; i++){
			if(CompList[i]->GetIsConn()!=1){
				GraphicsInfo CompG2 = CompList[i]->Getm_GfxInfo();
				if(!(((CompG.y1 == CompG2.y1)&&(CompG.x2 < CompG2.x1))||((CompG.x1 == CompG2.x1)&&(CompG.y2 < CompG2.y1))||
					((CompG.y1 == CompG2.y1)&&(CompG.x1 > CompG2.x2))||((CompG.x1 == CompG2.x1)&&(CompG.y1 > CompG2.y2))||
					((CompG.y2 < CompG2.y1)&&(CompG.x2 >= CompG2.x1)&&(CompG.x1 < CompG2.x1))||((CompG.y2 < CompG2.y1)&&(CompG.x1 <= CompG2.x2)&&(CompG.x2 > CompG2.x2))||
					((CompG.y1 > CompG2.y2)&&(CompG.x2 >= CompG2.x1)&&(CompG.x1 < CompG2.x1))||((CompG.y1 > CompG2.y2)&&(CompG.x1 <= CompG2.x2)&&(CompG.x2 > CompG2.x2))||
					((CompG.x1 > CompG2.x2)&&(CompG.y2 < CompG2.y1))||((CompG.x1 > CompG2.x2)&&(CompG.y1 > CompG2.y2))||
					((CompG.x2 < CompG2.x1)&&(CompG.y1 > CompG2.y2))||((CompG.x2 < CompG2.x1)&&(CompG.y2 < CompG2.y1))||
					((CompG.x1 > CompG2.x2)&&(CompG.y2 >= CompG2.y1)&&(CompG.y1 < CompG2.y1))||((CompG.x1 > CompG2.x2)&&(CompG.y1 <= CompG2.y2)&&(CompG.y2 > CompG2.y2))||
					((CompG.x2 < CompG2.x1)&&(CompG.y1 <= CompG2.y2)&&(CompG.y2 > CompG2.y2))||((CompG.x2 < CompG2.x1)&&(CompG.y2 >= CompG2.y1)&&(CompG.y1 < CompG2.y1)))){
						NotOverlap2 = false;
						break;
				}
			}
		}
		if(NotOverlap&&NotOverlap2)
			CompList[CompCount++] = pComp;	
	}
	else
		CompList[CompCount++] = pComp;	
}
////////////////////////////////////////////////////////////////////

int ApplicationManager::Iscomp(int& x, int& y, GraphicsInfo& gfx) {

	for (int i = 0; i < CompCount; i++) {
		GraphicsInfo GInfoCm = CompList[i]->Getm_GfxInfo();
		if (CompList[i]->GetIsConn() == true) {
			if (((x >= GInfoCm.x1 - 1) && (x <= GInfoCm.x2 + 1) && (y <= GInfoCm.y1 + 1) && (y >= GInfoCm.y2 - 1)) || ((x >= GInfoCm.x1 - 1) && (x <= GInfoCm.x2 + 1) && (y >= GInfoCm.y1 - 1) && (y <= GInfoCm.y2 + 1)) ||
				((x <= GInfoCm.x1 + 1) && (x >= GInfoCm.x2 - 1) && (y <= GInfoCm.y1 + 1) && (y >= GInfoCm.y2 - 1)) || ((x <= GInfoCm.x1 + 1) && (x >= GInfoCm.x2 + 1) && (y >= GInfoCm.y1 - 1) && (y <= GInfoCm.y2 + 1))) {
				gfx = GInfoCm;
				return i;
			}
		}
		else if (x > GInfoCm.x1 && x < GInfoCm.x2 && y > GInfoCm.y1 && y < GInfoCm.y2) {
			gfx = GInfoCm;
			return i;
		}
	}

	return -1;
};


Action * ApplicationManager::undooo() {
	if (!Aundo.empty()) {
		Aredo.push_front( Aundo.back() );
		Aundo.pop_back();
		return Aredo.front();
	}
	return NULL;
}

Action* ApplicationManager::redooo() {

	if (!Aredo.empty()) {
		Aundo.push_back(Aredo.front());
		Aredo.pop_front();
		return Aundo.back();
	}

	return NULL;
}

list <Action *>& ApplicationManager::getlist() {
	return (Aundo);
};


void ApplicationManager::RemoveComponent(int k){

	if(CompCount >= 6){
		if(CompList[CompCount - 5]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-6; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 6]->SetIsDeleted(true);
		}
		else if(CompList[CompCount - 4]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-5; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 5]->SetIsDeleted(true);
		}
		else if(CompList[CompCount - 3]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-4; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 4]->SetIsDeleted(true);
		}

		else if(CompList[CompCount - 2]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-3; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 3]->SetIsDeleted(true);
		}
		else if(CompList[CompCount - 1]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-2; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 2]->SetIsDeleted(true);
		}
		else{
			for(int i = k; i<CompCount-1; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount -1]->SetIsDeleted(true);
		}

	}
	else if(CompCount >=5){
		if(CompList[CompCount - 4]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-5; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 5]->SetIsDeleted(true);
		}
		else if(CompList[CompCount - 3]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-4; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 4]->SetIsDeleted(true);
		}

		else if(CompList[CompCount - 2]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-3; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 3]->SetIsDeleted(true);
		}
		else if(CompList[CompCount - 1]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-2; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 2]->SetIsDeleted(true);
		}
		else{
			for(int i = k; i<CompCount-1; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount -1]->SetIsDeleted(true);
		}
	}
	else if(CompCount >=4){
		if(CompList[CompCount - 3]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-4; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 4]->SetIsDeleted(true);
		}

		else if(CompList[CompCount - 2]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-3; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 3]->SetIsDeleted(true);
		}
		else if(CompList[CompCount - 1]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-2; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 2]->SetIsDeleted(true);
		}
		else{
			for(int i = k; i<CompCount-1; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount -1]->SetIsDeleted(true);
		}
	}
	else if(CompCount >=3){
		if(CompList[CompCount - 2]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-3; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 3]->SetIsDeleted(true);
		}
		else if(CompList[CompCount - 1]->GetIsDeleted() == true){
			for(int i = k; i<CompCount-2; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount - 2]->SetIsDeleted(true);
		}
		else{
			for(int i = k; i<CompCount-1; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount -1]->SetIsDeleted(true);
		}
	}
	else{
		if(CompCount >0){
			for(int i = k; i<CompCount-1; i++){
				Component* temp = CompList[i];
				CompList[i] = CompList[i+1];
				CompList[i+1] = temp;
			}
			CompList[CompCount -1]->SetIsDeleted(true);
		}

	}

	//CompList[k]->SetIsDeleted(true);
}

////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(OutputInterface); 	
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;

	case ADD_Label:
		pAct = new AddLabel(this);
		break;

	case ADD_CONNECTION:
		pAct = new AddCONN(this);
		break;

	case EDIT_Label:
		pAct = new EditLabel(this);
		break;


	case Gate_Bar:
		pAct = new GateBar(this);
		break;

	case Destroy_Gates:
		pAct = new DESTROYGATES(this);
		break;

	case DEL:
		pAct = new Delete(this);
		break;

	case SELECT:
		pAct = new Select(this);
		break;

	case ADD_Switch:
		pAct = new AddSWITCH(this);
		break;

	case Change_Switch:
		pAct = new ChangeSWCH(this);
		break;

	case SIM_MODE:
		pAct = new SimMode(this);
		break;

	case UNDO:
		pAct = new Undo1(this);
		break;


	case DSN_MODE:
		pAct = new DSNMODE(this);
		break;

	case DSN_TOOL:
		pAct = new DSNTOOL(this);
		break;

	case REDO:
		pAct = new Redo12(this);
		break;


	case COPY:
		pAct = new Copy_Paste(this);
		break;

	case CUT:
		pAct = new Cut_Paste(this);
		break;


	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		break;

	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;

	case ADD_INV:
		pAct = new AddINV(this);
		break;

	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;

	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;

	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;

	case ADD_AND_GATE_3:
		pAct = new AddANDgate3(this);
		break;

	case ADD_NOR_GATE_3:
		pAct = new AddNORgate3(this);
		break;

	case ADD_XOR_GATE_3:
		pAct = new AddXORgate3(this);
		break;

	case ADD_Buff:
		pAct = new AddBUFF(this);
		break;

	case ADD_LED:
		pAct = new AddLED(this);
		break;

		/*case Create_TruthTable:
		pAct = new CREATE_TRUTHTABLE(this);
		break;

		case MOVE:
		pAct = new MOV(this);
		break;
		*/
		case SAVE:
		pAct = new SAV(this);
		break;
		/*
		case LOAD:
		pAct = new LOD(this);
		break;

		*/		
		case EDIT_CONN:
		pAct = new EditCONN(this);
		break;
		/*
		case STATUS_BAR:
		pAct = new STATUSBAR(this);
		break;*/

		/*case SIM_TOOL:
		pAct = new SIMU_TOOL(this);
		break;*/

	case SIM:
		pAct = new SIMU(this);
		break;

	case EXIT:
		pAct = new Exit(this);
		break;

	}
	if (pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	if (CompCount != 0) {
		for (int i = CompCount - 1; i >= 0; i--) {
			if (CompList[i]->GetIsDeleted() == true) {
				GraphicsInfo g = CompList[i]->Getm_GfxInfo();
				if (CompList[i]->GetIsConn() == 1) {
					CompList[i]->Draw(OutputInterface, 0, 1);
					GraphicsInfo compconn = g;
					compconn.x1 -= 10; compconn.y1 += 30;
					if (compconn.x1 > compconn.x2) {

						compconn.x1 -= 38;
						compconn.y1 -= 27;

					}
					else
					{

						compconn.x1 += 55;
						compconn.y1 -= 27;

					}


					OutputInterface->delettext(compconn);
				}
				else {
					OutputInterface->DrawRect(g);
					GraphicsInfo comptext = g;
					comptext.x1 += 10; comptext.y1 -= 20;
					OutputInterface->delettext(comptext);
				}
				delete CompList[i];
				CompCount--;
			}
		}
	}
	for (int i = 0; i < CompCount; i++) {
		bool IsSelected = CompList[i]->GetIsSelected();
		CompList[i]->Draw(OutputInterface, IsSelected);

	}


}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

int ApplicationManager::GetCompCount(){
	return CompCount;
}
void ApplicationManager::GetCompList(Component** CoLi){
	for(int i = 0; i<CompCount; i++){
		CoLi[i] = CompList[i];
	}
}


////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;

}

void ApplicationManager::AddClipb(int k)
{

	delete Clipb;
	if (dynamic_cast<AND2*>(CompList[k])) {
		Clipb = new AddANDgate2(this);
	}
	if (dynamic_cast<AND3*>(CompList[k])) {
		Clipb = new AddANDgate3(this);
	}
	if (dynamic_cast<OR2*>(CompList[k])) {
		Clipb = new AddORgate2(this);
	}
	if (dynamic_cast<BUFF*>(CompList[k])) {
		Clipb = new AddBUFF(this);
	}
	if (dynamic_cast<INV*>(CompList[k])) {
		Clipb = new AddINV(this);
	}
	if (dynamic_cast<LED*>(CompList[k])) {
		Clipb = new AddLED(this);
	}
	if (dynamic_cast<NAND2*>(CompList[k])) {
		Clipb = new AddNANDgate2(this);
	}
	if (dynamic_cast<NOR2*>(CompList[k])) {
		Clipb = new AddNORgate2(this);
	}
	if (dynamic_cast<NOR3*>(CompList[k])) {
		Clipb = new AddNORgate3(this);
	}
	if (dynamic_cast<XOR2*>(CompList[k])) {
		Clipb = new AddXORgate2(this);
	}
	if (dynamic_cast<XOR3*>(CompList[k])) {
		Clipb = new AddXORgate3(this);
	}
	if (dynamic_cast<XNOR2*>(CompList[k])) {
		Clipb = new AddXNORgate2(this);
	}
	if (dynamic_cast<SWITCH*>(CompList[k])) {
		Clipb = new AddSWITCH(this);
	}

}

void ApplicationManager::ClipExecute(){
	if(Clipb != NULL)
		Clipb->Execute();
}

Action* ApplicationManager::GetClip()
{
	return Clipb;
}
