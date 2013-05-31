#include "pipeCADpanel.h"
#include "pipeCADframe.h"


BEGIN_EVENT_TABLE(pipeCADpanel, wxPanel)

EVT_PAINT(pipeCADpanel::paintEvent)

EVT_LEFT_DOWN(pipeCADpanel::mouseLeftDown)

END_EVENT_TABLE()

pipeCADpanel::pipeCADpanel(wxFrame* parent) : wxPanel(parent)
{
    SetWindowStyle(wxFULL_REPAINT_ON_RESIZE);

    wxButton* b_create_vertex = new wxButton(this, 1000, wxT("Create Vertex"), wxPoint(20,20), wxSize(110,25));
    Connect(1000, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pipeCADpanel::createVertex));

    wxButton* b_create_edge = new wxButton(this, 1001, wxT("Create Edge"), wxPoint(20,60), wxSize(110,25));
    Connect(1001, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pipeCADpanel::createEdge));

    wxButton* b_remove = new wxButton(this, 1002, wxT("Remove"), wxPoint(20,100), wxSize(110,25));
    Connect(1002, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pipeCADpanel::removeElement));

    wxStaticBox* staticbox = new wxStaticBox(this, wxID_ANY, _("Tools"), wxPoint(0,0), wxSize(150,600), wxTAB_TRAVERSAL);

    wxStaticBoxSizer* staticSizer = new wxStaticBoxSizer(staticbox, wxVERTICAL);

    staticSizer->Add(b_create_vertex, .1, wxEXPAND, 5);
    staticSizer->Add(b_create_edge, .1, wxEXPAND, 5);
    staticSizer->Add(b_remove, .1, wxEXPAND, 5);
    p_create_edge_begin = wxPoint(0,0);
    p_create_edge_end = wxPoint(0,0);
    create_vertex = false;
    create_edge = false;
    remove = false;

}

void pipeCADpanel::render(wxDC&  dc)
{
    if(!vertex.empty())
        for(int i = 0; i < vertex.size(); i++)
            dc.DrawCircle(vertex[i].x, vertex[i].y, 10);
    if(p_create_edge_begin != wxPoint(0,0))
    {
        dc.DrawCircle(p_create_edge_begin.x, p_create_edge_begin.y, 10);
        if(p_create_edge_end != wxPoint(0,0))
        {
            dc.DrawCircle(p_create_edge_end.x, p_create_edge_end.y, 10);
            dc.DrawLine(p_create_edge_begin.x, p_create_edge_begin.y, p_create_edge_end.x, p_create_edge_end.y);
            p_create_edge_begin = wxPoint(0,0);
            p_create_edge_end = wxPoint(0,0);
        }

    }


}

void pipeCADpanel::paintEvent(wxPaintEvent& evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void pipeCADpanel::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void pipeCADpanel::mouseLeftDown(wxMouseEvent& evt)
{
    wxClientDC dc(this);
    if(create_vertex)
    {
        wxPoint p_aux = evt.GetLogicalPosition(dc);
        vertex.push_back(p_aux);
        render(dc);
    }
    if(create_edge)
    {
        if(p_create_edge_begin == wxPoint(0,0))
            p_create_edge_begin = evt.GetLogicalPosition(dc);
        else if(p_create_edge_end == wxPoint(0,0))
            p_create_edge_end = evt.GetLogicalPosition(dc);
        render(dc);

    }
    if(remove)
    {
        //render(dc);
    }


}

void pipeCADpanel::createVertex(wxCommandEvent& evt)
{
    if(!create_vertex)
    {
        create_vertex = true;
        create_edge = false;
        remove = false;
    }
    else
        create_vertex = false;

}

void pipeCADpanel::createEdge(wxCommandEvent& evt)
{
    if(!create_edge)
    {
        create_edge = true;
        create_vertex = false;
        remove = false;
    }
    else
        create_edge = false;

}

void pipeCADpanel::removeElement(wxCommandEvent& evt)
{
    if(!remove)
    {
        remove = true;
        create_vertex = false;
        create_edge = false;
    }
    else
       remove = false;

}


