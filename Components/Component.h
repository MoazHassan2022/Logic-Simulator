#pragma once
#include "..\Defs.h"
#include "..\GUI\Output.h"
#include "OutputPin.h"
#include "InputPin.h"
#include <fstream>

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
	bool IsSelected, IsDeleted;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
public:
	string Label[20];
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut, bool selected=0, bool IsDeleted=0 ) = 0;	//for each component to Draw itself
	
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	void setLabel(string label);
	string getlabel();

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual OutputPin* Getm_OutputPin() { return NULL; };
	virtual InputPin * Getm_InputPin(int i) { return NULL; };
	virtual int Getm_Inputs() = 0;
	virtual bool GetIsSelected() = 0;
	virtual void SetIsSelected(bool Is) = 0;

	virtual bool GetIsDeleted() = 0;
	virtual void SetIsDeleted(bool) = 0;
	virtual bool GetIsConn() = 0;
	virtual	void setOutputStatus(STATUS s) =0 ;
	virtual void sav(ofstream& Ofile, int n) =0 ;


	GraphicsInfo Getm_GfxInfo();
	


	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

