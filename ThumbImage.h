#ifndef THUMBIMAGE_H
#define THUMBIMAGE_H

#include <wx/wx.h>

class ThumbImage : public wxBitmapButton
{
    private:
        wxString m_filePath;
        bool m_open = false;
    
    public:
        ThumbImage(wxString filePath, wxWindow* parent, wxWindowID id, wxPoint position);
        ~ThumbImage();

        void LoadImageFrame();
};

#endif