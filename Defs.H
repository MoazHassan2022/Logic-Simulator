#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	CRT_GTBAR,			//Creates gate toolbar
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection
	EDIT_CONN,

	Create_TruthTable,	//Create Truth Table of the Circuit

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode
	COPY,
	CUT,

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

	Gate_Bar,	//Gate toolbar created
	Destroy_Gates,	//Gate toolbar destroyed
	SIM_TOOL,	//A click on an empty place in the simulation tool bar
	SIM,		//Simulate

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};


enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here

	ITM_ADD,		//Add Gate
	ITM_SIMU,		//Simulate
	ITM_SVE,		//Save
	ITM_LOD,		//Load
	ITM_SWCH,		//Switch
	ITM_LED,		//LED
	ITM_Connection, //Connection
	ITM_EDITCONN,
	ITM_Label,		//Label
	ITM_EDIT,		// Edit Label 
	ITM_DELETE,     //Delete
	ITM_UNDO,       //Undo
	ITM_REDO,       //REDO
	ITM_COPY,
	ITM_CUT,
	ITM_EXIT,		//Exit item

	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum

};

enum GateItem
{
	ITM_AND2,		//AND gate item in menu
	ITM_OR2,		//OR gate item in menu

	//TODO: Add more items names here

	ITM_BUFF,		//Buffer gate
	ITM_INV,		//Inverter gate

	ITM_NAND2,		//2-input NAND gate
	ITM_NOR2,		//2-input NOR gate
	ITM_XOR2,		//2-input XOR gate
	ITM_XNOR2,		//2-input XNOR gate

	ITM_AND3,		//3-input AND gate
	ITM_NOR3,		//3-input NOR gate
	ITM_XOR3,		//3-input XOR gate

	ITM_GAT_CNT
};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_SIM,	//Simulate menu item
	ITM_TRUTH,  //Truth table menu item
	ITM_CHANGESW,
	ITM_TOOLS,  // Add gate menu item
	ITM_SAVE,
	ITM_LOAD,
	ITM_EXIT2,


	//TODO:Add more items names here

	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5	//Default fan out of 2-input AND gate
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1, y1, x2, y2;
};

#ifndef NULL
#define NULL 0
#endif

#endif