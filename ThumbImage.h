#ifndef THUMBIMAGE_H
#define THUMBIMAGE_H

#include <wx/wx.h>

#include "ImageViewer.h"

class ImageViewer;

class ThumbImage : public wxBitmapButton
{
    private:
        wxString m_filePath;
        ImageViewer* viewer = nullptr;

        wxDECLARE_EVENT_TABLE();

    public:
        ThumbImage(wxString filePath, wxWindow* parent, wxWindowID id, wxPoint position);
        ~ThumbImage();

        void LoadImageFrame(wxCommandEvent& evt);
};

#endif