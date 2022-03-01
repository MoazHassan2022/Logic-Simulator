#include "Exit.h"
#include <iostream>
using namespace std;


Exit::Exit(ApplicationManager* pApp) :Action(pApp)
 {}
Exit::~Exit() {}

//Reads parameters required for action to execute
void Exit::ReadActionParameters(){}

//Execute action (code depends on action type)
void Exit::Execute() { exit; }

//To undo this action (code depends on action type)
void Exit::Undo(){}

//To redo this action (code depends on action type)
void Exit::Redo(){}


