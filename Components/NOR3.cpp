#include "NOR3.h"

NOR3::NOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut), IsDeleted(0), IsSelected(0)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR3::Operate()
{
	//caclulate the output status as the NORing of the THREE input pins

	 (GetInputPinStatus(1) == HIGH || GetInputPinStatus(2) == HIGH || GetInputPinStatus(3) == HIGH)?
		(setOutputStatus(LOW)):(setOutputStatus(HIGH));

	//Add you code here
	 SetIsSelected(1);
}


// Function Draw
// Draws 3-input NOR gate
void NOR3::Draw(Output* pOut, bool selected, bool IsDeleted)
{
	//Call output class NOR pass gate drawing info to it.
	IsSelected = selected;
	pOut->DrawNOR3(m_GfxInfo,selected);

	GraphicsInfo comp = m_GfxInfo;
	comp.x1 += 10;	comp.y1 -= 20;
	pOut->showString(comp, this->getlabel());
}

//returns status of outputpin
int NOR3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

void NOR3::setOutputStatus(STATUS s) {
	m_OutputPin.setStatus(s);
};



bool NOR3::GetIsSelected() {
	return IsSelected;
}
void NOR3::SetIsSelected(bool Is) {
	IsSelected = Is;
}



bool NOR3::GetIsDeleted() {
	return IsDeleted;
}
void NOR3::SetIsDeleted(bool I) {
	IsDeleted = I;
}
bool NOR3::GetIsConn() {
	return 0;
}
void NOR3::sav(ofstream& Ofile, int n) {
	Ofile << "NOR3        " << n << "    ";

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
