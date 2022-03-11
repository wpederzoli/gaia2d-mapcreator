#include "LoadAssetsPanel.h"

wxBEGIN_EVENT_TABLE(LoadAssetsPanel, wxPanel)
    EVT_BUTTON(12, LoadAssetsPanel::OnLoadBtnClick)
    // EVT_BUTTON(wxID_ANY, LoadAssetsPanel::OnImageClick)
wxEND_EVENT_TABLE()

LoadAssetsPanel::LoadAssetsPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
    wxInitAllImageHandlers();
    loadAssetsBtn = new wxButton(this, 12, "Load", wxPoint(20, 20), wxDefaultSize);

    SetBackgroundColour(wxColor(200, 133, 233));
};

LoadAssetsPanel::~LoadAssetsPanel()
{
    delete loadAssetsBtn;
    while(!thumbImages.empty() )
    {
        delete thumbImages.top();
        thumbImages.pop();
    }
};

void LoadAssetsPanel::OnLoadBtnClick(wxCommandEvent& evt) 
{
    wxFileDialog openFile(this, "Select file", "", "", "PNG and JPG files  (*.png;*.jpg;*.jpeg)|*.png;*.jpg;*.jpeg", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    
    if(openFile.ShowModal() == wxID_OK)
    {

        wxPoint pos(200, 10);
        if(!thumbImages.empty() )
        {
            pos = thumbImages.top()->GetPosition();

            pos.x += 60;
            if(pos.x > 400)
            {
                pos.x = 200;
                pos.y += 60;  
            } 
        }

        ThumbImage* ti = new ThumbImage(openFile.GetPath(), this, THUMB_BUTTON_OFFSET_ID + thumbImages.size(), pos);
        thumbImages.emplace(ti);
    }

    evt.Skip();
};