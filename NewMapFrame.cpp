#include "NewMapFrame.h"

wxBEGIN_EVENT_TABLE(NewMapFrame, wxFrame)
wxEND_EVENT_TABLE()

NewMapFrame::NewMapFrame(wxFrame* parent) : wxFrame(parent, wxID_ANY, "map", wxDefaultPosition, wxSize(800, 600) )
{
    Show(true);
};

NewMapFrame::~NewMapFrame(){};

