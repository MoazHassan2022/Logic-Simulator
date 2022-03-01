#include "Connection.h"
#include <iostream>
Connection::Connection(const GraphicsInfo& r_GfxInfo, OutputPin* pSrcPin, InputPin* pDstPin, Component* S, Component* D, int dp)
	:Component(r_GfxInfo), IsDeleted(0), IsSelected(0)
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	SrcCmpnt = S;
	DstCmpnt = D;
	DstPinN = dp;
}

void Connection::setSourcePin(OutputPin* pSrcPin)
{
	SrcPin = pSrcPin;
}

OutputPin* Connection::getSourcePin()
{
	return SrcPin;
}

OutputPin * Connection::Getm_OutputPin() {
	return SrcPin;
}

void Connection::setDestPin(InputPin* pDstPin)
{
	DstPin = pDstPin;
}

InputPin* Connection::getDestPin()
{
	return DstPin;
}

InputPin * Connection::Getm_InputPin(int i) {
	return DstPin;
}
int Connection::Getm_Inputs() {
	return -1;
}


void Connection::Operate()
{

	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus(  (STATUS)SrcPin->getStatus() );

}


void Connection::Draw(Output* pOut, bool selected, bool isdeleted)
{
	IsSelected = selected;
	IsDeleted = isdeleted;
	pOut->DrawConnection(m_GfxInfo, selected,IsDeleted);

	GraphicsInfo comp = m_GfxInfo;

	if (comp.x1 > comp.x2) {

		comp.x1 -= 50;	
		comp.y1 += 1;

	}
	else
	{
		
		comp.x1 += 50;
		comp.y1 += 1;

	}

	pOut->showString(comp, this->getlabel());
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}


bool Connection::GetIsSelected() {
	return IsSelected;
}
void Connection::SetIsSelected(bool Is) {
	IsSelected = Is;
}


bool Connection::GetIsDeleted() {
	return IsDeleted;
}
void Connection::SetIsDeleted(bool I) {
	IsDeleted = I;
}
bool Connection::GetIsConn() {
	return 1;
}

void Connection::sav(ofstream& Ofile, int n) {

}

Component* Connection::GetSrcComp()
{
	return SrcCmpnt;
}
Component* Connection::GetDstComp()
{
	return DstCmpnt;
}
int Connection::GetdstPnN()
{
	return DstPinN;
}
