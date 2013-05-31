#include "pipeCADframe.h"
#include "pipeCADpanel.h"

enum
{
    idMenuQuit,
    idMenuAbout,

};

BEGIN_EVENT_TABLE(pipeCADframe, wxFrame)
    EVT_MENU(idMenuQuit, pipeCADframe::MenuQuit)
    EVT_MENU(idMenuAbout, pipeCADframe::MenuAbout)
END_EVENT_TABLE()

pipeCADframe::pipeCADframe(wxString title, int x, int y, int width, int height):
   wxFrame(NULL,wxID_ANY,title,wxPoint(x,y),wxSize(width,height))
{
    CreateStatusBar();
    SetStatusText(wxString(_T("Pipe CAD")));

    wxMenu *menuFile = new wxMenu();
    menuFile->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    menuFile->AppendSeparator();
    menuFile->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));

    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(menuFile,_("&File"));

    SetMenuBar(menuBar);


}

void pipeCADframe::MenuQuit(wxCommandEvent& event)
{

   int ans = wxMessageBox(wxString(_T("Do you want finished the application?")),wxString(_T("Confirmation")),
                           wxYES_NO | wxICON_QUESTION, this);
   if(ans == wxYES)
      Close(true);

}

void pipeCADframe::MenuAbout(wxCommandEvent& event)
{
    wxMessageBox(wxString(_T("This application...")),wxString(_T("About...")),
                          wxOK | wxICON_INFORMATION);

}

