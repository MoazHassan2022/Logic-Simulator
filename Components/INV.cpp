#include "INV.h"

INV::INV(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(1, r_FanOut), IsDeleted(0), IsSelected(0)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void INV::Operate()
{
	//caclulate the output status as the INVing of the two input pins
	(GetInputPinStatus(1) == HIGH) ? (setOutputStatus(LOW)) : (setOutputStatus(HIGH));
	//Add you code here

	(GetInputPinStatus(1) == LOW) ? (SetIsSelected(1)) : (SetIsSelected(0));

}


// Function Draw
// Draws 1-input INV gate
void INV::Draw(Output* pOut, bool selected, bool IsDeleted )
{
	//Call output class INV pass gate drawing info to it.
	IsSelected = selected;
	pOut->DrawINV(m_GfxInfo,selected);
}

//returns status of outputpin
int INV::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INV::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void INV::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

void INV::setOutputStatus(STATUS s) {
	m_OutputPin.setStatus(s);
};



bool INV::GetIsSelected() {
	return IsSelected;
}
void INV::SetIsSelected(bool Is) {
	IsSelected = Is;
}



bool INV::GetIsDeleted() {
	return IsDeleted;
}
void INV::SetIsDeleted(bool I) {
	IsDeleted = I;
}
bool INV::GetIsConn() {
	return 0;
}

void INV::sav(ofstream& Ofile, int n) {
	Ofile << "INVERTER    " << n << "    ";

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
