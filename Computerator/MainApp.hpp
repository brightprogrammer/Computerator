#ifndef COMPUTERRATOR_MAINAPP
#define COMPUTERRATOR_MAINAPP

#include "MainFrame.hpp"

class MainApp : public wxApp{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MainApp);
DECLARE_APP(MainApp);

#endif // COMPUTERRATOR_MAINAPP
