#include "SetupMapFrame.h"

wxBEGIN_EVENT_TABLE(SetupMapFrame, wxFrame)
wxEND_EVENT_TABLE()

SetupMapFrame::SetupMapFrame(wxFrame* parent) : wxFrame(parent, wxID_ANY, "Setup map", wxDefaultPosition, wxSize(400, 200))
{
    mainPanel = new wxPanel(this, wxID_ANY);
    input = new wxTextCtrl(mainPanel, wxID_ANY);
    mainPanel->Show(true);

    Show(true);
};

SetupMapFrame::~SetupMapFrame()
{
    GetParent()->Enable(true);
};