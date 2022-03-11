#include "ThumbImage.h"

ThumbImage::ThumbImage(wxString filePath, wxWindow* parent, wxWindowID id, wxPoint position) : 
    wxBitmapButton(parent, id, wxImage(filePath, wxBITMAP_TYPE_PNG), position, wxSize(50, 50) )
{
    m_filePath = filePath;
    wxImage image(filePath);

    image.Rescale(50, 50);
    
    SetBitmap(image);
};

ThumbImage::~ThumbImage() {};

void ThumbImage::LoadImageFrame() 
{
    if(!m_open)
    {
        m_open = true;
        wxFrame* f = new wxFrame(GetParent(), wxID_ANY, "Image x");
        wxStaticBitmap* sb = new wxStaticBitmap(f, wxID_ANY, wxBitmap(m_filePath, wxBITMAP_TYPE_PNG) );
        f->SetSize(wxSize(sb->GetSize().x + 100, sb->GetSize().y + 100) );
        f->Show(true);
    }  
}