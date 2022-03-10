#include "NewMapFrame.h"

wxBEGIN_EVENT_TABLE(NewMapFrame, wxFrame)
    EVT_CLOSE(NewMapFrame::OnClose)
    EVT_SLIDER(2001, NewMapFrame::OnZoomChange)
wxEND_EVENT_TABLE()

NewMapFrame::NewMapFrame(wxFrame* parent, int cols, int rows, int tw, int th, wxString name) : wxFrame(parent, wxID_ANY, name, wxDefaultPosition, wxSize(800, 600) )
{
    wxSizer* vSizer = new wxBoxSizer(wxVERTICAL);
    wxSizer* hSizer = new wxBoxSizer(wxHORIZONTAL);

    assetsPanel = new LoadAssetsPanel(this);
    
    wxPanel* pb = new wxPanel(this);
    pb->SetBackgroundColour("LightBlue");

    hSizer->Add(vSizer, 3, wxEXPAND, 0);
    hSizer->Add(pb, 1, wxEXPAND, 0);

    m_canvas = new Canvas(this, cols, rows, tw);
    m_statusBar = this->CreateStatusBar(2, wxSTB_DEFAULT_STYLE, wxID_ANY);
    m_zoomSlider = new wxSlider(m_statusBar, 2001, 50, 1, 100);
    m_statusBar->SetStatusText(wxString("Zoom: ") << m_zoomSlider->GetValue() << wxString("%"), 1);

    vSizer->Add(m_canvas, 3, wxEXPAND, 0);
    vSizer->Add(assetsPanel, 1, wxEXPAND, 0);

    SetSizer(hSizer);
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

void NewMapFrame::OnZoomChange(wxCommandEvent& evt) 
{
    m_statusBar->SetStatusText(wxString("Zoom: ") << m_zoomSlider->GetValue() << wxString("%"), 1);
    m_canvas->setPixelSize(m_zoomSlider->GetValue() );
    evt.Skip();
};

