#include "XOR3.h"

XOR3::XOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut), IsDeleted(0), IsSelected(0)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR3::Operate()
{
	//caclulate the output status as the XORing of the two input pins
	int n{ 0 };
	for (int i = 1; i <= 3; i++)
		(GetInputPinStatus(i) == HIGH) ? (n++) : (n);

	(n % 2 == 1) ? (setOutputStatus(HIGH)) : (setOutputStatus(LOW));

	//Add you code here

	SetIsSelected(1);

}


// Function Draw
// Draws 3-input XOR gate
void XOR3::Draw(Output* pOut, bool selected, bool IsDeleted)
{
	//Call output class XOR pass gate drawing info to it.
	IsSelected = selected;
	pOut->DrawXOR3(m_GfxInfo,selected);

	GraphicsInfo comp = m_GfxInfo;
	comp.x1 += 10;	comp.y1 -= 20;
	pOut->showString(comp, this->getlabel());
}

//returns status of outputpin
int XOR3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

void XOR3::setOutputStatus(STATUS s) {
	m_OutputPin.setStatus(s);
};


bool XOR3::GetIsSelected() {
	return IsSelected;
}
void XOR3::SetIsSelected(bool Is) {
	IsSelected = Is;
}



bool XOR3::GetIsDeleted() {
	return IsDeleted;
}
void XOR3::SetIsDeleted(bool I) {
	IsDeleted = I;
}
bool XOR3::GetIsConn() {
	return 0;
}

void XOR3::sav(ofstream& Ofile, int n) {
	Ofile << "XOR3        " << n << "    ";

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
