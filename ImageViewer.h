#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <wx/wx.h>

class ImageViewer : public wxFrame
{
    private:
        wxStaticBitmap* sbm = nullptr;

    public:
        ImageViewer(wxString filePath, wxWindow* parent);
        ~ImageViewer();
};

#endif