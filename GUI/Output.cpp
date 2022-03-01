#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = WHITE;
	UI.SelectColor = RED;
	UI.ConnColor = WHITE;
	UI.MsgColor = WHITE;
	UI.BkGrndColor = BLACK;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project: Logic Simulator");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen( (1021818) ,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}

//////////////////////////////////////////////////////////////////////////////////////////

string past;
//Shows the text on drawing area
void Output::showString(GraphicsInfo r_GfxInfo, string s) {
	if (!(s.empty())) {
		pWind->SetPen(UI.BkGrndColor);
		pWind->SetBrush(UI.BkGrndColor);
		pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + 70, r_GfxInfo.y1 + 20);
		pWind->SetPen(WHITE);
		pWind->SetBrush(WHITE);
		pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1, s);
		past = s;
	}
}

void Output::delettext(GraphicsInfo r_GfxInfo) {
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + 70, r_GfxInfo.y1 + 20);
	pWind->SetPen(WHITE);
	pWind->SetBrush(WHITE);

}



//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
void Output::DrawRect(GraphicsInfo g){
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(g.x1, g.y1, g.x2, g.y2);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_EXIT] = "Images\\Menu\\Menu_Exit.jpg";
	//TODO: Prepare image for each menu item and add it to the list
	MenuItemImages[ITM_ADD] = "Images\\Menu\\AddGate.jpg";
	MenuItemImages[ITM_SIMU] = "Images\\Menu\\Menu_SIM.jpg";
	MenuItemImages[ITM_SVE] = "Images\\Menu\\Menu_SAVE.jpg";
	MenuItemImages[ITM_LOD] = "Images\\Menu\\Menu_LOAD.jpg";
	MenuItemImages[ITM_SWCH] = "Images\\Menu\\Menu_SWCH.jpg";
	MenuItemImages[ITM_LED] = "Images\\Menu\\Menu_LED.jpg";
	MenuItemImages[ITM_Connection] = "images\\Menu\\Menu_Connection.jpg";
	MenuItemImages[ITM_Label] = "images\\Menu\\Menu_Label.jpg";
	MenuItemImages[ITM_EDIT] = "images\\Menu\\Menu_EDIT.jpg";
	MenuItemImages[ITM_EDITCONN] = "images\\Menu\\Menu_EditCONN.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\Menu_Redo.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\Menu_COPY.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\Menu_CUT.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\Menu_DELETE.jpg";



	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK,1);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the gate (toolbar) in the Design mode
void Output::CreateGatesToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	string GatesImages[ITM_GAT_CNT];

	GatesImages[ITM_AND2] = "Images\\Menu\\Menu_AND2.jpg";
	GatesImages[ITM_OR2] = "Images\\Menu\\Menu_OR2.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	GatesImages[ITM_BUFF] = "Images\\Menu\\Menu_BUFF.jpg";
	GatesImages[ITM_INV] = "Images\\Menu\\Menu_INV.jpg";

	GatesImages[ITM_NAND2] = "Images\\Menu\\Menu_NAND2.jpg";
	GatesImages[ITM_NOR2] = "Images\\Menu\\Menu_NOR2.jpg";
	GatesImages[ITM_XOR2] = "Images\\Menu\\Menu_XOR2.jpg";
	GatesImages[ITM_XNOR2] = "Images\\Menu\\Menu_XNOR2.jpg";

	GatesImages[ITM_AND3] = "Images\\Menu\\Menu_AND3.jpg";
	GatesImages[ITM_NOR3] = "Images\\Menu\\Menu_NOR3.jpg";
	GatesImages[ITM_XOR3] = "Images\\Menu\\Menu_XOR3.jpg";
	
	//Draw menu item one image at a time
	for (int i = 0; i < ITM_GAT_CNT; i++)
		pWind->DrawImage(GatesImages[i], i*UI.ToolItemWidth, UI.ToolBarHeight+1, UI.ToolItemWidth, UI.ToolBarHeight);

	pWind->SetPen(BLACK, 1);
	pWind->DrawLine(0, 0, 0, UI.height);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Deletes the gate (toolbar) in the Design mode
void Output::ClearGatesToolBar() const
{
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(BLACK);
	pWind->DrawRectangle(0, UI.ToolBarHeight+1, UI.width, 2*UI.ToolBarHeight+1);
}


//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	string SimMenuItemImages[ITM_SIM_CNT];
	SimMenuItemImages[ITM_SIM] = "Images\\Simulation\\Simulation_SIM.jpg";
	SimMenuItemImages[ITM_TRUTH] = "Images\\Simulation\\Simulation_TRUTH.jpg";
	SimMenuItemImages[ITM_TOOLS] = "Images\\Simulation\\Simulation_TOOLS.jpg";
	SimMenuItemImages[ITM_SAVE] = "Images\\Simulation\\Simulation_SAVE.jpg";
	SimMenuItemImages[ITM_LOAD] = "Images\\Simulation\\Simulation_LOAD.jpg";
	SimMenuItemImages[ITM_EXIT2] = "Images\\Simulation\\Simulation_EXIT2.jpg";
	SimMenuItemImages[ITM_CHANGESW] = "Images\\Simulation\\Simulation_CHANGESW.jpg";
	//Clear Design Toolbar
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(BLACK);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	
	//Draw Simulation menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(SimMenuItemImages[i], i*UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	//Draw a line under the simulation toolbar 
	pWind->SetPen(BLACK, 1);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//TODO: Add similar functions to draw all components

void Output::DrawBUFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_BUFF_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_BUFF.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_INV_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_INV.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND3.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR3.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR3.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawSwitch(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected) {	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_SWCH_Closed.jpg";
	}
	else
		GateImage = "Images\\Gates\\Gate_SWCH_Opened.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_LED_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_LED.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected, bool IsDeleted) const
{
	pWind->SetPen(WHITE);
	if ((r_GfxInfo.x1 < r_GfxInfo.x2) && (r_GfxInfo.y1 < r_GfxInfo.y2) || (r_GfxInfo.x1 < r_GfxInfo.x2) && (r_GfxInfo.y1 > r_GfxInfo.y2)) {
		if (selected) {
			if(IsDeleted)
				pWind->SetPen(UI.BkGrndColor);
			else
				pWind->SetPen(RED); }
		if(IsDeleted)
			pWind->SetPen(UI.BkGrndColor);

		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2 - 15, r_GfxInfo.y1);
		pWind->DrawLine(r_GfxInfo.x2 - 15, r_GfxInfo.y1, r_GfxInfo.x2 - 15, r_GfxInfo.y2);
		pWind->DrawLine(r_GfxInfo.x2 - 15, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
		
	}
	if ((r_GfxInfo.x1 > r_GfxInfo.x2) && (r_GfxInfo.y1 > r_GfxInfo.y2) || (r_GfxInfo.x1 > r_GfxInfo.x2) && (r_GfxInfo.y1 < r_GfxInfo.y2)) {
		if (selected) {
			if(IsDeleted)
				pWind->SetPen(UI.BkGrndColor);
			else
				pWind->SetPen(RED); }
		if(IsDeleted)
			pWind->SetPen(UI.BkGrndColor);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2 + 15, r_GfxInfo.y1);
		pWind->DrawLine(r_GfxInfo.x2 + 15, r_GfxInfo.y1, r_GfxInfo.x2 + 15, r_GfxInfo.y2);
		pWind->DrawLine(r_GfxInfo.x2 + 15, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
		
	}
	if ((r_GfxInfo.x1 == r_GfxInfo.x2) || (r_GfxInfo.y1 == r_GfxInfo.y2)) {
		if (selected) {
			if(IsDeleted)
				pWind->SetPen(UI.BkGrndColor);
			else
				pWind->SetPen(RED); }
		if(IsDeleted)
			pWind->SetPen(UI.BkGrndColor);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
		
	}
	//TODO: Add code to draw connection
}



Output::~Output()
{
	delete pWind;
}
