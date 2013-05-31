
#include "pipeAPP.h"
#include "pipeCADframe.h"
#include "pipeCADpanel.h"


IMPLEMENT_APP(pipeAPP)

bool pipeAPP::OnInit()
{

    pipeCADframe *main_screen = new pipeCADframe(wxString(_T("Pipe CAD")),50,50,1200,600);

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    draw_panel = new pipeCADpanel((wxFrame*)main_screen);

    /*wxButton* b_create_vertex = new wxButton(main_screen, 1000, wxT("Create Vertex"), wxPoint(10,10), wxSize(96,23));
    Connect(1000, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pipeCADpanel::createVertex));

    wxButton* b_create_edge = new wxButton(main_screen, 1001, wxT("Create Edge"), wxPoint(10,50), wxSize(96,23));
    Connect(1001, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pipeCADpanel::createEdge));

    wxButton* b_remove = new wxButton(main_screen, 1002, wxT("Remove"), wxPoint(10,90), wxSize(96,23));
    Connect(1002, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pipeCADpanel::remove));

    wxStaticBox* staticbox = new wxStaticBox(main_screen, wxID_ANY, _("Tools"), wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);

    wxStaticBoxSizer* staticSizer = new wxStaticBoxSizer(staticbox, wxVERTICAL);

    sizer->Add(staticSizer, 0, wxGROW|wxALL, 5);*/
    sizer->Add(draw_panel, 1, wxEXPAND);
    /*staticSizer->Add(b_create_vertex, .1, wxEXPAND, 5);
    staticSizer->Add(b_create_edge, .1, wxEXPAND, 5);
    staticSizer->Add(b_remove, .1, wxEXPAND, 5);*/

    main_screen ->SetSizer(sizer);
    main_screen ->SetAutoLayout(true);

    main_screen->Show(true);
    SetTopWindow(main_screen);
    return true;

}
