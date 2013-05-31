#ifndef PIPECADPANEL_H
#define PIPECADPANEL_H

#include "wx/wx.h"
#include <wx/event.h>
#include "wx/window.h"
#include "wx/sizer.h"
#include <vector>

using namespace std;


class pipeCADpanel : public wxPanel
{
	// Tools Buttons
	wxButton* b_create_vertex;
	wxButton* b_create_edge;
	wxButton* b_remove;

	bool create_vertex,
		 create_edge,
		 remove;

    vector<wxPoint> vertex;
    wxPoint p_create_edge_begin;
    wxPoint p_create_edge_end;

    public:
    pipeCADpanel(wxFrame* parent);

    void paintEvent(wxPaintEvent& evt);
    void paintNow();
    void render(wxDC& dc);
    void mouseLeftDown(wxMouseEvent& evt);

    // Tools Functions
    void createVertex(wxCommandEvent& evt);
    void createEdge(wxCommandEvent& evt);
    void select(wxCommandEvent& evt);
    void removeElement(wxCommandEvent& evt);


    DECLARE_EVENT_TABLE()
};

#endif // PIPECADPANEL_H
