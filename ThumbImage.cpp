#include "ThumbImage.h"

wxBEGIN_EVENT_TABLE(ThumbImage, wxBitmapButton)
    EVT_BUTTON(wxID_ANY, ThumbImage::LoadImageFrame)
wxEND_EVENT_TABLE()

ThumbImage::ThumbImage(wxString filePath, wxWindow* parent, wxWindowID id, wxPoint position) : 
    wxBitmapButton(parent, id, wxImage(filePath, wxBITMAP_TYPE_PNG), position, wxSize(50, 50) )
{
    m_filePath = filePath;
    wxImage image(filePath);
        
    image.Rescale(50, 50);
    
    SetBitmap(image);
};

ThumbImage::~ThumbImage() 
{
    // delete viewer;
};

void ThumbImage::LoadImageFrame(wxCommandEvent& evt) 
{
    viewer = new ImageViewer(m_filePath, GetParent() );
    viewer->Show(true);
    evt.Skip();
};