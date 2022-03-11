#include "LoadAssetsPanel.h"

wxBEGIN_EVENT_TABLE(LoadAssetsPanel, wxPanel)
    EVT_BUTTON(12, LoadAssetsPanel::OnLoadBtnClick)
    EVT_BUTTON(wxID_ANY, LoadAssetsPanel::OnImageClick)
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
    while(!bm.empty() )
    {
        delete bm.top();
        bm.pop();
    }
};

void LoadAssetsPanel::OnLoadBtnClick(wxCommandEvent& evt) 
{
    wxFileDialog openFile(this, "Select file", "", "", "PNG and JPG files  (*.png;*.jpg;*.jpeg)|*.png;*.jpg;*.jpeg", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    
    if(openFile.ShowModal() == wxID_OK)
    {
        wxString path = openFile.GetPath();
        wxImage image;
        image.LoadFile(path, wxBITMAP_TYPE_PNG);
        image.Rescale(50, 50);

        wxPoint pos(200, 10);

        if(!bm.empty() )
        {
            pos = bm.top()->GetPosition();
            pos.x += 60;
            if(pos.x > 400)
            {
                pos.x = 200;
                pos.y += 60;  
            } 
        }
        wxStaticBitmap sbm(this, wxID_ANY, wxBitmap(image, wxBITMAP_TYPE_PNG), pos);
        wxBitmapButton* bmb = new wxBitmapButton(this, wxID_ANY, sbm.GetBitmap(), pos);
        bm.emplace(bmb);
        // bm.emplace( new wxStaticBitmap(this, wxID_ANY, wxBitmap(image, wxBITMAP_TYPE_PNG), pos) );
    }

    evt.Skip();
};

void LoadAssetsPanel::OnImageClick(wxCommandEvent& evt) 
{
    int x = wxGetMousePosition().x;
    printf("mouse x: %i\n", x);   
};