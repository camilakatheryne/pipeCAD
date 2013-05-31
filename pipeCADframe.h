#ifndef PIPECADFRAME_H
	#define PIPECADFRAME_H


#include "pipeAPP.h"
#include "wx/wx.h"


class pipeCADframe: public wxFrame
{
    public:
       pipeCADframe(wxString title, int x, int y, int width, int height);

       DECLARE_EVENT_TABLE()
    private:
        void MenuQuit(wxCommandEvent& event);
        void MenuAbout(wxCommandEvent& event);

};

#endif

