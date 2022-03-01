#include "XOR2.h"

XOR2::XOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut), IsDeleted(0), IsSelected(0)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR2::Operate()
{
	//caclulate the output status as the XORing of the two input pins
	(GetInputPinStatus(1) != GetInputPinStatus(2)) ? (setOutputStatus(HIGH)) : (setOutputStatus(LOW));
	//Add you code here
	SetIsSelected(1);

}


// Function Draw
// Draws 2-input XOR gate
void XOR2::Draw(Output* pOut, bool selected, bool IsDeleted )
{
	//Call output class XOR pass gate drawing info to it.
	IsSelected = selected;
	pOut->DrawXOR2(m_GfxInfo,selected);

	GraphicsInfo comp = m_GfxInfo;
	comp.x1 += 10;	comp.y1 -= 20;
	pOut->showString(comp, this->getlabel());
}

//returns status of outputpin
int XOR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

void XOR2::setOutputStatus(STATUS s) {
	m_OutputPin.setStatus(s);
};



bool XOR2::GetIsSelected() {
	return IsSelected;
}
void XOR2::SetIsSelected(bool Is) {
	IsSelected = Is;
}



bool XOR2::GetIsDeleted() {
	return IsDeleted;
}
void XOR2::SetIsDeleted(bool I) {
	IsDeleted = I;
}
bool XOR2::GetIsConn() {
	return 0;
}

void XOR2::sav(ofstream& Ofile, int n) {
	Ofile << "XOR2        " << n << "    ";

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
