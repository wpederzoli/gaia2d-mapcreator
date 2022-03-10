#include "NewMapFrame.h"

wxBEGIN_EVENT_TABLE(NewMapFrame, wxFrame)
    EVT_CLOSE(NewMapFrame::OnClose)
    EVT_SLIDER(2001, NewMapFrame::OnZoomChange)
wxEND_EVENT_TABLE()

NewMapFrame::NewMapFrame(wxFrame* parent, int cols, int rows, int tw, int th, wxString name) : wxFrame(parent, wxID_ANY, name, wxDefaultPosition, wxSize(800, 600) )
{
    m_canvas = new Canvas(this);
    m_statusBar = this->CreateStatusBar(2, wxSTB_DEFAULT_STYLE, wxID_ANY);
    m_zoomSlider = new wxSlider(m_statusBar, 2001, 50, 1, 100);
    m_statusBar->SetStatusText(wxString("Zoom: ") << m_zoomSlider->GetValue() << wxString("%"), 1);

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

