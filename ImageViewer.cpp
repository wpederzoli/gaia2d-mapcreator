#include "ImageViewer.h"

ImageViewer::ImageViewer(wxString filePath, wxWindow* parent) : wxFrame(parent, wxID_ANY, "Image Viewer")
{
    sbm = new wxStaticBitmap(this, wxID_ANY, wxBitmap(filePath) );
    SetSize(sbm->GetSize() );
};

ImageViewer::~ImageViewer()
{
    delete sbm;
};