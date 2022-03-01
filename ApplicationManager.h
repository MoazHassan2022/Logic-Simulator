#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include <list>
#include <iterator>

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Actions\AddANDgate2.h"
#include "Actions/Delete.h"
#include "Actions/AddCONN.h"
#include "Actions/Select.h"
#include "Actions/EditLabel.h"
#include "Actions/ADDLabel.h"
#include "Actions/DESTROYGATES.h"
#include "Actions/GateBar.h"
#include "Actions/SimMode.h"
#include "Actions/Undo1.h"
#include "Actions/Redo12.h"
#include "Actions/ChangeSWCH.h"
#include "Actions/AddSWITCH.h"
#include "Actions/DSNMODE.h"
#include "Actions/DSNTOOL.h"
#include "Actions\Copy_Paste.h"
#include "Actions\Cut_Paste.h"
#include "Actions/AddANDgate3.h"
#include "Actions/AddBUFF.h"
#include "Actions/AddCONN.h"
#include "Actions/AddINV.h"
#include "Actions/ADDLabel.h"
#include "Actions/AddLED.h"
#include "Actions/AddNANDgate2.h"
#include "Actions/AddNORgate2.h"
#include "Actions/AddNORgate3.h"
#include "Actions/AddORgate2.h"
#include "Actions/AddSWITCH.h"
#include "Actions/AddXNORgate2.h"
#include "Actions/AddXORgate2.h"
#include "Actions/AddXORgate3.h"
#include "Actions/ChangeSWCH.h"
#include "Actions/Copy_Paste.h"
#include "Actions/Cut_Paste.h"
#include "Actions/SIMU.h"
#include "Actions/Exit.h"
#include "Actions/SAV.h"
#include "Actions/EditCONN.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Action* Clipb;

	list <Action * > Aundo;
	list <Action * > Aredo;

public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	int GetCompCount();
	void GetCompList(Component** CoLi);
	void RemoveComponent(int);
	int	Iscomp(int& x, int& y, GraphicsInfo& gfx);

	//waer
	Action* undooo();
	Action* redooo();
	list <Action*>& getlist();
	void AddClipb(int k);
	void ClipExecute();
	Action* GetClip();


	//destructor
	~ApplicationManager();
};

#endif