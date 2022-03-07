#include "MainMenuFrame.h"

wxBEGIN_EVENT_TABLE(MainMenuFrame, wxFrame)
    EVT_BUTTON(NEW_BUTTON_ID, MainMenuFrame::OnNew)
    EVT_BUTTON(LOAD_BUTTON_ID, MainMenuFrame::OnLoad)
    EVT_BUTTON(EXIT_BUTTON_ID, MainMenuFrame::OnExit)
wxEND_EVENT_TABLE()

MainMenuFrame::MainMenuFrame() : wxFrame(NULL, wxID_ANY, "Gaia Map Creator", wxPoint(200, 100), wxSize(800, 600))
{
    newMapWindows = new std::stack<NewMapFrame*>();
    setup = NULL;

    mainPanel = new wxPanel(this, wxID_ANY);
    newButton = new wxButton(mainPanel, NEW_BUTTON_ID, "New map", wxDefaultPosition, wxSize(100, 50) );
    loadButton = new wxButton(mainPanel, LOAD_BUTTON_ID, "Load map", wxDefaultPosition, wxSize(100, 50) );
    exitButton = new wxButton(mainPanel, EXIT_BUTTON_ID, "Exit", wxDefaultPosition, wxSize(100, 50) );

    wxBoxSizer* vSizer = new wxBoxSizer(wxVERTICAL);
    vSizer->Add(newButton, wxSizerFlags().Center() );
    vSizer->Add(loadButton, wxSizerFlags().Center() );
    vSizer->Add(exitButton, wxSizerFlags().Center() );
    mainPanel->SetSizer(vSizer);

    wxBoxSizer* frameSizer = new wxBoxSizer(wxVERTICAL);
    frameSizer->Add(mainPanel, wxSizerFlags().Center() );
    SetSizer(frameSizer);

    mainPanel->Show(true);
};

MainMenuFrame::~MainMenuFrame()
{ 
    delete newMapWindows;
    delete mainPanel, newButton, loadButton, exitButton;
};

void MainMenuFrame::OnNew(wxCommandEvent& evt)
{
    setup = new SetupMapFrame(this);
    this->Enable(false);
    // NewMapFrame* nm = new NewMapFrame(this);
    // newMapWindows->push(nm);
    // winId++;
};

void MainMenuFrame::OnLoad(wxCommandEvent& evt)
{};

void MainMenuFrame::OnExit(wxCommandEvent& evt)
{
    while(!newMapWindows->empty() )
    {
        delete newMapWindows->top();
        newMapWindows->pop();
    }
    
    Close(true);
};

void MainMenuFrame::RemoveElementFromStack(NewMapFrame* f)
{
    for(int i = 0; i < newMapWindows->size(); i++)
    {
        NewMapFrame* n = newMapWindows->top();
        newMapWindows->pop();
        if(!(n == f) )
            newMapWindows->push(n);
        else
            break;
    }
}