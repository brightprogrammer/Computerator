#include "MainFrame.hpp"
#include "wx/gdicmn.h"
#include "wx/gtk/textctrl.h"
#include "wx/gtk/textentry.h"
#include "wx/sizer.h"

enum {  BUTTON_0 = 1000,
		BUTTON_1 = 1001,
		BUTTON_2 = 1002,
		BUTTON_3 = 1003,
		BUTTON_4 = 1004,
		BUTTON_5 = 1005,
		BUTTON_6 = 1006,
		BUTTON_7 = 1007,
		BUTTON_8 = 1008,
		BUTTON_9 = 1009,
		BUTTON_ADD = 1010,
		BUTTON_SUB = 1011,
		BUTTON_MUL = 1012,
		BUTTON_DIV = 1013,
		BUTTON_00 = 1014,
		BUTTON_CLR = 1015,
		BUTTON_RES = 1016,
		BUTTON_DECM = 1017
	};

//event table
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
//	EVT_BUTTON(PLUS_BUTTON_CLICKED_EVENT_ID, MainFrame::OnPlus)
//	EVT_BUTTON(MINUS_BUTTON_CLICKED_EVENT_ID, MainFrame::OnMinus)
wxEND_EVENT_TABLE()

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Computerator"){
	pTopBoxSizer = new wxBoxSizer(wxVERTICAL);
	pTopPanel = new wxPanel(this, wxID_ANY);
	//add TopPanel to TopBoxSizer with proportion = 1 and make it expand on frame resize
	//also add 0px border to all sides
	pTopBoxSizer->Add(pTopPanel, 0, wxEXPAND | wxALL, 1);
	//add the TopBoxSizer to this
	this->SetSizer(pTopBoxSizer);

	//sub sizer in which we will add child objects
	//this sizer is a child of pTopPanel, i.e inside it
	pSubBoxSizer = new wxBoxSizer(wxVERTICAL); //we will add new widgets vertically
	pTopPanel->SetSizer(pSubBoxSizer); //wx widgets will query this sizer to get minimum size
	// pTopPanel->SetMinSize(wxSize(200, 300));

	//text control for entering operations
	pTextCtrl = new wxTextCtrl(pTopPanel, wxID_ANY);
	//horizontal sizer for TextControl
	pTextCtrlSizer = new wxBoxSizer(wxHORIZONTAL);
	pTextCtrlSizer->Add(pTextCtrl, 1, wxRIGHT | wxLEFT | wxTOP, 10);
	//add this sizer to SubBoxSizer
	pSubBoxSizer->Add(pTextCtrlSizer, 0, wxEXPAND);

	//create buttons
	wxSize buttonSize = wxDefaultSize;
	pButtonClr = new wxButton(pTopPanel, BUTTON_CLR, "Clr", wxDefaultPosition, buttonSize);
	pButtonDiv = new wxButton(pTopPanel, BUTTON_DIV, "/", wxDefaultPosition, buttonSize);
	pButtonMul = new wxButton(pTopPanel, BUTTON_MUL, "x", wxDefaultPosition, buttonSize);
	pButton00 = new wxButton(pTopPanel, BUTTON_00, "00", wxDefaultPosition, buttonSize);
	pButtonDecm = new wxButton(pTopPanel, BUTTON_DECM, ".", wxDefaultPosition, buttonSize);
	pButtonSub = new wxButton(pTopPanel, BUTTON_SUB, "-"); //these 3 buttons will be on the right side
	pButtonAdd = new wxButton(pTopPanel, BUTTON_ADD, "+");
	pButtonRes = new wxButton(pTopPanel, BUTTON_RES, "=");
	Buttons.push_back(std::shared_ptr<wxButton>(new wxButton(pTopPanel, BUTTON_0, "0", wxDefaultPosition, buttonSize)));
	Buttons.push_back(std::shared_ptr<wxButton>(new wxButton(pTopPanel, BUTTON_1, "1", wxDefaultPosition, buttonSize)));
	Buttons.push_back(std::shared_ptr<wxButton>(new wxButton(pTopPanel, BUTTON_2, "2", wxDefaultPosition, buttonSize)));
	Buttons.push_back(std::shared_ptr<wxButton>(new wxButton(pTopPanel, BUTTON_3, "3", wxDefaultPosition, buttonSize)));
	Buttons.push_back(std::shared_ptr<wxButton>(new wxButton(pTopPanel, BUTTON_4, "4", wxDefaultPosition, buttonSize)));
	Buttons.push_back(std::shared_ptr<wxButton>(new wxButton(pTopPanel, BUTTON_5, "5", wxDefaultPosition, buttonSize)));
	Buttons.push_back(std::shared_ptr<wxButton>(new wxButton(pTopPanel, BUTTON_6, "6", wxDefaultPosition, buttonSize)));
	Buttons.push_back(std::shared_ptr<wxButton>(new wxButton(pTopPanel, BUTTON_7, "7", wxDefaultPosition, buttonSize)));
	Buttons.push_back(std::shared_ptr<wxButton>(new wxButton(pTopPanel, BUTTON_8, "8", wxDefaultPosition, buttonSize)));
	Buttons.push_back(std::shared_ptr<wxButton>(new wxButton(pTopPanel, BUTTON_9, "9", wxDefaultPosition, buttonSize)));

	//add grid sizer for buttons
	pLeftKeypadSizer = new wxGridSizer(5, 3, 10, 10);
	pLeftKeypadSizer->Add(pButtonClr);
	pLeftKeypadSizer->Add(pButtonDiv);
	pLeftKeypadSizer->Add(pButtonMul);
	pLeftKeypadSizer->Add(Buttons[7].get());
	pLeftKeypadSizer->Add(Buttons[8].get());
	pLeftKeypadSizer->Add(Buttons[9].get());
	pLeftKeypadSizer->Add(Buttons[4].get());
	pLeftKeypadSizer->Add(Buttons[5].get());	
	pLeftKeypadSizer->Add(Buttons[6].get());
	pLeftKeypadSizer->Add(Buttons[1].get());
	pLeftKeypadSizer->Add(Buttons[2].get());
	pLeftKeypadSizer->Add(Buttons[3].get());
	pLeftKeypadSizer->Add(pButton00);
	pLeftKeypadSizer->Add(Buttons[0].get());
	pLeftKeypadSizer->Add(pButtonDecm);

	//right keypad sizer for -/+/= buttons
	pRightKeypadSizer = new wxBoxSizer(wxVERTICAL);
	pRightKeypadSizer->Add(pButtonSub, 1, wxEXPAND | wxALL, 10);
	pRightKeypadSizer->Add(pButtonAdd, 2, wxEXPAND | wxALL, 10);
	pRightKeypadSizer->Add(pButtonRes, 2, wxEXPAND | wxALL, 10);

	//sizer for keypad
	pKeypadSizer = new wxBoxSizer(wxHORIZONTAL);
	pKeypadSizer->Add(pLeftKeypadSizer, 3, wxEXPAND | wxTOP, 10);
	pKeypadSizer->Add(pRightKeypadSizer, 1, wxEXPAND);

	//add KeypadSizer to SubBoxSizer
	pSubBoxSizer->Add(pKeypadSizer);
	this->SetMinSize(pSubBoxSizer->GetMinSize());
	this->SetSize(pSubBoxSizer->GetSize());
	
	Centre();
}

void MainFrame::OnPlus(wxCommandEvent &event){
}

void MainFrame::OnMinus(wxCommandEvent &event){
}

void MainFrame::UpdateLabel(){
}