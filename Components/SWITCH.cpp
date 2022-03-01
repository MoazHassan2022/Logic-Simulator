#include "SWITCH.h"
#include <iostream>


SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(0, r_FanOut), IsDeleted(0), IsSelected(0)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void SWITCH::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void SWITCH::Draw(Output* pOut, bool selected, bool IsDeleted)
{
	//Call output class and pass gate drawing info to it.
	IsSelected = selected;
	pOut->DrawSwitch(m_GfxInfo, selected);

	GraphicsInfo comp = m_GfxInfo;
	comp.x1 += 10;	comp.y1 -= 20;
	pOut->showString(comp, this->getlabel());
}

//returns status of outputpin
int SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int SWITCH::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void SWITCH::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void SWITCH::setOutputStatus(STATUS s) {
	m_OutputPin.setStatus(s);
};


bool SWITCH::GetIsSelected() {
	return IsSelected;
}
void SWITCH::SetIsSelected(bool Is) {
	IsSelected = Is;
}

bool SWITCH::GetIsDeleted() {
	return IsDeleted;
}
void SWITCH::SetIsDeleted(bool I) {
	IsDeleted = I;
}
bool SWITCH::GetIsConn() {
	return 0;
}

void SWITCH::sav(ofstream& Ofile, int n) {
	Ofile << "SWITCH      " << n << "    ";

	if (this->getlabel() == "")
	{
		Ofile << "NoLabel";
	}
	else
	{
		Ofile << this->getlabel();
	}
	Ofile << "    " << this->getlabel() << "    " << this->Getm_GfxInfo().x1 << "    " << this->Getm_GfxInfo().y1 << endl;
}
