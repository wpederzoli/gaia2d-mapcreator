#include "NewMapFrame.h"

wxBEGIN_EVENT_TABLE(NewMapFrame, wxFrame)
    EVT_CLOSE(NewMapFrame::OnClose)
wxEND_EVENT_TABLE()

NewMapFrame::NewMapFrame(wxFrame* parent, int cols, int rows, int tw, int th, wxString name) : wxFrame(parent, wxID_ANY, name, wxDefaultPosition, wxSize(800, 600) )
{
    wxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    
    wxPanel* topPanel = new wxPanel(this, wxID_ANY);
    wxPanel* bottomPanel = new wxPanel(this, wxID_ANY);

    topPanel->SetBackgroundColour(12312);
    bottomPanel->SetBackgroundColour(23238);
    
    wxButton* loadBtn = new wxButton(bottomPanel, wxID_ANY, "Load sprite");

    sizer->Add(loadBtn, 0, wxALIGN_LEFT, 0);
    sizer->Add(topPanel, 3, wxEXPAND, 0);
    sizer->Add(bottomPanel, 1, wxEXPAND, 0);

    SetSizer(sizer);

    Show(true);
};

NewMapFrame::~NewMapFrame(){};

void NewMapFrame::OnClose(wxCloseEvent& evt)
{
    MainMenuFrame* m = (MainMenuFrame*) GetParent();
    m->RemoveElementFromStack(this);

    this->Destroy();
    evt.Skip();
};

