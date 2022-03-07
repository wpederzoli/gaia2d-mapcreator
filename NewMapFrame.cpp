#include "NewMapFrame.h"

wxBEGIN_EVENT_TABLE(NewMapFrame, wxFrame)
    EVT_CLOSE(NewMapFrame::OnClose)
wxEND_EVENT_TABLE()

NewMapFrame::NewMapFrame(wxFrame* parent) : wxFrame(parent, wxID_ANY, "map", wxDefaultPosition, wxSize(800, 600) )
{
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

