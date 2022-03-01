#include "Input.h"
#include "Output.h"
#define ESCAPE 27
#define Enter 13
#define BackSpace 8 

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut)
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar
	pOut->PrintMsg("Hello, please enter text..");
	string text;
	char c = 0;
	while ((pWind->WaitKeyPress(c))) {

		if ((int)c == Enter) {
			pOut->ClearStatusBar();
			return text;
		}
		else if ((int)c == ESCAPE) {
			pOut->ClearStatusBar();
			return "";
		}
		else if ((int)c == BackSpace) {
			if (text.length() < 1)
				pOut->PrintMsg("Back space is pressed and there no text to delete");
			else {
				text.pop_back();
				pOut->PrintMsg(text);
			}
		}
		else
		{
			text += c;
			pOut->PrintMsg(text);

		}

	}


}

bool prsnt = false;
//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction(Output* pOut) const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADD:
				{
					if (prsnt)
					{
						pOut->ClearGatesToolBar();
						prsnt = false;
						return Destroy_Gates;
					}
					else
					{
						pOut->CreateGatesToolBar();
						prsnt = true;
						return Gate_Bar;
					}

				}
			case ITM_SIMU:	return SIM_MODE;
			case ITM_SVE:	return SAVE;
			case ITM_LOD:	return LOAD;
			case ITM_SWCH:	return ADD_Switch;
			case ITM_LED:	return ADD_LED;
			case ITM_Connection: return ADD_CONNECTION;
			case ITM_Label: return ADD_Label;
			case ITM_EDIT: return EDIT_Label;
			case ITM_EDITCONN: return EDIT_CONN;
			case ITM_DELETE: return DEL;
			case ITM_REDO: return REDO;
			case ITM_UNDO: return UNDO;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_EXIT:	return EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on one of the gates
		if (prsnt && y >= UI.ToolBarHeight && y < 2 * UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_AND2:	return ADD_AND_GATE_2;
			case ITM_OR2:	return ADD_OR_GATE_2;
			case ITM_INV:	return ADD_INV;
			case ITM_BUFF:	return ADD_Buff;
			case ITM_NOR2:	return ADD_NOR_GATE_2;
			case ITM_NAND2:	return ADD_NAND_GATE_2;
			case ITM_XOR2:	return ADD_XOR_GATE_2;
			case ITM_XNOR2:	return ADD_XNOR_GATE_2;
			case ITM_AND3:	return ADD_AND_GATE_3;
			case ITM_NOR3:	return ADD_NOR_GATE_3;
			case ITM_XOR3:	return ADD_XOR_GATE_3;
			}
		}

		//[3] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[4] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_SIM:	return SIM;
			case ITM_TRUTH:	return Create_TruthTable;
			case ITM_CHANGESW: return Change_Switch;
			case ITM_TOOLS:	return DSN_MODE;
			case ITM_SAVE:	return SAVE;
			case ITM_LOAD:	return LOAD;
			case ITM_EXIT2:	return EXIT;
			}
		}

		//[3] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}


Input::~Input()
{
}