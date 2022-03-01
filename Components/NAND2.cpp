#include "NAND2.h"

NAND2::NAND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut), IsDeleted(0), IsSelected(0)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NAND2::Operate()
{
	//caclulate the output status as the NANDing of the two input pins

	 (GetInputPinStatus(1) == LOW || GetInputPinStatus(2) == LOW)?
		setOutputStatus(HIGH) :	setOutputStatus(LOW);


	 SetIsSelected(1);


	//Add you code here
}


// Function Draw
// Draws 2-input NAND gate
void NAND2::Draw(Output* pOut, bool selected, bool IsDeleted )
{
	//Call output class NAND pass gate drawing info to it.
	IsSelected = selected;
	pOut->DrawNAND2(m_GfxInfo,selected);

	GraphicsInfo comp = m_GfxInfo;
	comp.x1 += 10;	comp.y1 -= 20;
	pOut->showString(comp, this->getlabel());

}

//returns status of outputpin
int NAND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

void NAND2::setOutputStatus(STATUS s) {
	m_OutputPin.setStatus(s);
};



bool NAND2::GetIsSelected() {
	return IsSelected;
}
void NAND2::SetIsSelected(bool Is) {
	IsSelected = Is;
}



bool NAND2::GetIsDeleted() {
	return IsDeleted;
}
void NAND2::SetIsDeleted(bool I) {
	IsDeleted = I;
}
bool NAND2::GetIsConn() {
	return 0;
}

void NAND2::sav(ofstream& Ofile, int n) {
	Ofile << "NAND2       " << n << "    ";

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
