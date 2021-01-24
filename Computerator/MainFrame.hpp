#ifndef COMPUTERATOR_MAINFRAME
#define COMPUTERATOR_MAINFRAME

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
	double result, leftOperand, rightOperand;
	
protected:
	void OnPlus(wxCommandEvent &event);
	void OnMinus(wxCommandEvent &event);
	void UpdateLabel();
};

#endif // COMPUTERATOR_MAINFRAME
