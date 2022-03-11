#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <wx/wx.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcbuffer.h>

class ImageViewer : public wxFrame
{
    private:
        wxBitmap* bitMap = nullptr;
        wxPoint mousePos;
        void OnPaint(wxPaintEvent& evt);
        void OnMouseMove(wxMouseEvent& evt);
        void DrawMouse(wxDC& dc, int x, int y);

        wxDECLARE_EVENT_TABLE();
    public:
        ImageViewer(wxString filePath, wxWindow* parent);
        ~ImageViewer();
};

#endif