#pragma once

/*
  Class LED
  -----------
  represent the 1-input LED gate
*/

#include "Gate.h"

class LED:public Gate
{
	bool IsSelected, IsDeleted;
public:
	LED(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the LED 
	virtual void Draw(Output* pOut, bool selected, bool IsDeleted = false);	//Draws LED 

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual	void setOutputStatus(STATUS s);

	virtual bool GetIsSelected();
	virtual void SetIsSelected(bool Is);

	virtual bool GetIsDeleted();
	virtual void SetIsDeleted(bool);
	virtual bool GetIsConn();
	virtual void sav(ofstream& Ofile, int n);



};
