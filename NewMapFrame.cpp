#include "NewMapFrame.h"

wxBEGIN_EVENT_TABLE(NewMapFrame, wxFrame)
    EVT_CLOSE(NewMapFrame::OnClose)
wxEND_EVENT_TABLE()

NewMapFrame::NewMapFrame(wxFrame* parent, int cols, int rows, int tw, int th, wxString name) : wxFrame(parent, wxID_ANY, name, wxDefaultPosition, wxSize(800, 600) )
{
    Show(true);
};

NewMapFrame::~NewMapFrame(){};

void NewMapFrame::OnClose(wxCloseEvent& evt)
{
    // MainMenuFrame* m = (MainMenuFrame*) GetParent();
    // m->RemoveElementFromStack(this);
    this->Destroy();
    evt.Skip();
};

