#include "LoadAssetsPanel.h"

wxBEGIN_EVENT_TABLE(LoadAssetsPanel, wxPanel)
    EVT_BUTTON(12, LoadAssetsPanel::OnLoadBtnClick)
wxEND_EVENT_TABLE()

LoadAssetsPanel::LoadAssetsPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
    loadAssetsBtn = new wxButton(this, 12, "Load", wxPoint(20, 20), wxDefaultSize);

    SetBackgroundColour(wxColor(200, 133, 233));
};

LoadAssetsPanel::~LoadAssetsPanel(){};

void LoadAssetsPanel::OnLoadBtnClick(wxCommandEvent& evt) 
{
    wxFileDialog openFile(this, "Select file", "", "", "PNG and JPG files  (*.png;*.jpg;*.jpeg)|*.png;*.jpg;*.jpeg", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    openFile.ShowModal();
    evt.Skip();
};