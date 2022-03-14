#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <wx/wx.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcbuffer.h>

#include "LoadAssetsPanel.h"

class ImageViewer : public wxFrame
{
    private:
        wxBitmap* bitMap = nullptr;
        wxPoint m_mousePos;
        wxPoint m_mouseDownPos;
        wxPoint m_mouseUpPos;
        wxPoint m_selectedTiles;
        bool m_mouseDown = false;
        
        int m_tileSize;
        
        void OnPaint(wxPaintEvent& evt);
        void OnMouseMove(wxMouseEvent& evt);
        void OnMouseClick(wxMouseEvent& evt);
        void OnMouseRelease(wxMouseEvent& evt);

        void DrawMouse(wxDC& dc, int x, int y);

        wxDECLARE_EVENT_TABLE();
    public:
        ImageViewer(wxString filePath, wxWindow* parent );
        ~ImageViewer();
};

#endif