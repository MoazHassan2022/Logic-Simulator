#include "AND2.h"
#include <iostream>

AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut) ,IsDeleted(0) , IsSelected(0)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	 (GetInputPinStatus(1) == LOW || GetInputPinStatus(2) == LOW)?(setOutputStatus(LOW)):(setOutputStatus(HIGH));
	//Add you code here


	 SetIsSelected(1);

}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut, bool selected, bool IsDeleted)
{
	//Call output class and pass gate drawing info to it.
	IsSelected = selected;
	pOut->DrawAND2(m_GfxInfo, selected);

	GraphicsInfo comp = m_GfxInfo;
	comp.x1 += 10;	comp.y1 -= 20;
	pOut->showString(comp, this->getlabel());
}


//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

void AND2::setOutputStatus(STATUS s) {
	m_OutputPin.setStatus(s);
};



bool AND2::GetIsSelected() {
	return IsSelected;
}
void AND2::SetIsSelected(bool Is) {
	IsSelected = Is;
}



bool AND2::GetIsDeleted() {
	return IsDeleted;
}
void AND2::SetIsDeleted(bool I) {
	IsDeleted = I;
}
bool AND2::GetIsConn() {
	return 0;
}
void AND2::sav(ofstream& Ofile, int n) {
	Ofile << "AND2        " << n << "    ";

	if (this->getlabel() == "")
	{
		Ofile << "NoLabel";
	}
	else
	{
		Ofile << this->getlabel();
	}
	Ofile << "    " << this->Getm_GfxInfo().x1 << "    " << this->Getm_GfxInfo().y1 << endl;
}
