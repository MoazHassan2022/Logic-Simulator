#include "LED.h"
#include <iostream>

LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut), IsDeleted(0), IsSelected(0)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void LED::Operate()
{
	//caclulate the output status as the LED of the two input pins
	
	(GetInputPinStatus(1) == HIGH) ? ( SetIsSelected(1) ) : ( SetIsSelected(0) );

	//Add you code here
}


// Function Draw
// Draws 1-input LED gate
void LED::Draw(Output* pOut, bool selected, bool IsDeleted)
{
	//Call output class LED pass gate drawing info to it.
	IsSelected = selected;
	pOut->DrawLED(m_GfxInfo, selected);

	GraphicsInfo comp = m_GfxInfo;
	comp.x1 += 10;	comp.y1 -= 20;
	pOut->showString(comp, this->getlabel());
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return -1;
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins[0].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}

void LED::setOutputStatus(STATUS s) {
	m_OutputPin.setStatus(s);
};


bool LED::GetIsSelected() {
	return IsSelected;
}

void LED::SetIsSelected(bool Is) {
	IsSelected = Is;
}



bool LED::GetIsDeleted() {
	return IsDeleted;
}
void LED::SetIsDeleted(bool I) {
	IsDeleted = I;
}
bool LED::GetIsConn() {
	return 0;
}
void LED::sav(ofstream& Ofile, int n) {
	Ofile << "LED         " << n << "    ";

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
