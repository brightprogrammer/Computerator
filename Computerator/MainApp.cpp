#include "MainApp.hpp"
#include <exception>

bool MainApp::OnInit(){
	
	MainFrame *frame = new MainFrame;
	frame->Show();
	
	return true;
}

