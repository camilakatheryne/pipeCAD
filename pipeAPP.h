#ifndef PIPEAPP_H
	#define PIPEAPP_H

#include <wx/app.h>
#include "pipeCADpanel.h"

class pipeAPP : public wxApp {

public:
    //BasicPipeFrame *main_screen;
	pipeCADpanel *draw_panel;
	virtual bool OnInit();

};


#endif


