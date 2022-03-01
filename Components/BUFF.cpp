#include "BUFF.h"

BUFF::BUFF(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(1, r_FanOut), IsDeleted(0), IsSelected(0)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void BUFF::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	(GetInputPinStatus(1) == LOW) ? (setOutputStatus( LOW )) : (setOutputStatus(HIGH));
	//Add you code here

	SetIsSelected(1);
}


// Function Draw
// Draws 1-input BUFF gate
void BUFF::Draw(Output* pOut, bool selected, bool IsDeleted )
{
	//Call output class and pass gate drawing info to it.
	IsSelected = selected;
	pOut->DrawBUFF(m_GfxInfo,selected);


	GraphicsInfo comp = m_GfxInfo;
	comp.x1 += 10;	comp.y1 -= 20;
	pOut->showString(comp, this->getlabel());
}

//returns status of outputpin
int BUFF::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFF::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFF::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

void BUFF::setOutputStatus(STATUS s) {
	m_OutputPin.setStatus(s);
};



bool BUFF::GetIsSelected() {
	return IsSelected;
}
void BUFF::SetIsSelected(bool Is) {
	IsSelected = Is;
}



bool BUFF::GetIsDeleted() {
	return IsDeleted;
}
void BUFF::SetIsDeleted(bool I) {
	IsDeleted = I;
}
bool BUFF::GetIsConn() {
	return 0;
}

void BUFF::sav(ofstream& Ofile, int n) {
	Ofile << "BUFFER      " << n << "    ";

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
