#ifndef COMPUTERATOR_MAINFRAME
#define COMPUTERATOR_MAINFRAME

#include "wx/event.h"
#include "wx/sizer.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include <vector>
#include <memory>

class MainFrame : public wxFrame
{
	wxDECLARE_EVENT_TABLE();
public:
	MainFrame();

protected:
	//pXYZ means that pXYZ is a pointer and XYZ is the real name of object
	wxPanel *pTopPanel; //top panel
	wxBoxSizer *pTopBoxSizer, //sizer of top panel
			   *pSubBoxSizer, //sizer inside top panel
			   *pTextCtrlSizer, //sizer for TextCtrl
			   *pKeypadSizer, //will contains the keypad numbers and right keypad sizer
			   *pRightKeypadSizer; //will contain buttons : -, + and result
	wxGridSizer *pLeftKeypadSizer; //sizer for our buttons 
	wxTextCtrl *pTextCtrl; //we will enter operations here
	
	//buttons
	std::vector<std::shared_ptr<wxButton>> Buttons; //buttons for 0-9
	wxButton *pButtonAdd, *pButtonSub, *pButtonDiv, *pButtonMul, 
			 *pButton00, *pButtonClr, *pButtonRes, *pButtonDecm; 

	wxCommandEvent e; //empty event

	double result = 0;
	std::string leftOp = "", rightOp = "";

	//current active operand
	enum Operand {LEFT_OPERAND, RIGHT_OPERAND};
	enum Operation {ADD, SUB, MUL, DIV};
	Operand currentOperand = LEFT_OPERAND;
	Operation currentOperation;

	void OnAdd(wxCommandEvent &event);
	void OnSub(wxCommandEvent &event);
	void OnDiv(wxCommandEvent &event);
	void OnMul(wxCommandEvent &event);
	void OnClr(wxCommandEvent &event);
	void OnDecm(wxCommandEvent &event);
	void OnRes(wxCommandEvent &event);
	void OnButton0(wxCommandEvent &event);
	void OnButton1(wxCommandEvent &event);
	void OnButton2(wxCommandEvent &event);
	void OnButton3(wxCommandEvent &event);
	void OnButton4(wxCommandEvent &event);
	void OnButton5(wxCommandEvent &event);
	void OnButton6(wxCommandEvent &event);
	void OnButton7(wxCommandEvent &event);
	void OnButton8(wxCommandEvent &event);
	void OnButton9(wxCommandEvent &event);
	void OnButton00(wxCommandEvent &event);
	void UpdateRes();
	void OnKeypad(wxKeyEvent &event);
};

#endif // COMPUTERATOR_MAINFRAME
