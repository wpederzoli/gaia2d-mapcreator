#include "NewMapFrame.h"

wxBEGIN_EVENT_TABLE(NewMapFrame, wxMDIParentFrame)
    EVT_CLOSE(NewMapFrame::OnClose)
wxEND_EVENT_TABLE()

NewMapFrame::NewMapFrame(wxFrame* parent, int cols, int rows, int tw, int th, wxString name) : wxMDIParentFrame(parent, wxID_ANY, name, wxDefaultPosition, wxSize(800, 600) )
{
    wxSizer* vContainer = new wxBoxSizer(wxVERTICAL);
    wxSizer* hContainer = new wxBoxSizer(wxHORIZONTAL);

    wxPanel* mapEditor = new wxPanel(this);
    wxPanel* imageLoader = new wxPanel(this);
    
    TileField* t = new TileField(this, cols, rows, tw, th);

    mapEditor->SetBackgroundColour("White");
    imageLoader->SetBackgroundColour("LightGreen");

    vContainer->Add(t, 4, wxEXPAND, 0);
    vContainer->Add(imageLoader, 1, wxEXPAND, 0);

    wxPanel* layersPanel = new wxPanel(this);

    layersPanel->SetBackgroundColour("Grey");

    hContainer->Add(vContainer, 4, wxEXPAND, 0);
    hContainer->Add(layersPanel, 1, wxEXPAND, 0);

    SetSizer(hContainer);

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

