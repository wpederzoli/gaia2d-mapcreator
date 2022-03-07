#include "MainMenuFrame.h"

wxBEGIN_EVENT_TABLE(MainMenuFrame, wxMDIParentFrame)
    EVT_MENU(FILE_MENU_EXIT, MainMenuFrame::OnExit)
    EVT_MENU(FILE_MENU_OPEN, MainMenuFrame::OnOpen)
wxEND_EVENT_TABLE()

MainMenuFrame::MainMenuFrame() : wxMDIParentFrame(NULL, wxID_ANY, "Gaia Map Creator", wxDefaultPosition, wxSize(800, 600))
{
    m_menuBar = new wxMenuBar;
    SetMenuBar(m_menuBar);

    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(FILE_MENU_NEW, "New");
    fileMenu->Append(FILE_MENU_OPEN, "Open");
    fileMenu->Append(FILE_MENU_SAVE, "Save");
    fileMenu->Append(FILE_MENU_EXIT, "Exit");

    m_menuBar->Append(fileMenu, "File");
};

MainMenuFrame::~MainMenuFrame()
{};

void MainMenuFrame::OnOpen(wxCommandEvent& event)
{
    wxFileDialog* dialog = new wxFileDialog(this, "Open file");
    dialog->Show();
};

void MainMenuFrame::OnExit(wxCommandEvent& event)
{
    Close();
    event.Skip();
};