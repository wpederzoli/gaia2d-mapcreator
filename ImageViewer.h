#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <wx/wx.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcbuffer.h>

#include "LoadAssetsPanel.h"
#include "Canvas.h"

class ImageViewer : public wxFrame
{
    private:
        wxBitmap* bitMap = nullptr;
        wxPoint m_mousePos;
        wxPoint m_mouseDownPos;
        wxPoint m_mouseUpPos;
        wxRect m_selectedTiles;

        bool m_mouseDown = false;
        bool m_selected = false;
        bool m_activate = false;

        int m_tileSize = 0;
        
        void OnPaint(wxPaintEvent& evt);

        void OnMouseMove(wxMouseEvent& evt);
        void OnMouseClick(wxMouseEvent& evt);
        void OnMouseRelease(wxMouseEvent& evt);

        void OnActiveWindow(wxActivateEvent& evt);

        void DrawMouse(wxDC& dc, int x, int y);
        void DrawLines(wxDC& dc, int x, int y);
        void DrawMousePosition(wxDC& dc, int x, int y);
        void DrawSelection(wxDC& dc, int x, int y);
        void DrawSelected(wxDC& dc, int x, int y);

        void SetCanvasBitmap();

        wxDECLARE_EVENT_TABLE();
    
    public:
        ImageViewer(wxString filePath, wxWindow* parent );
        ~ImageViewer();
};

#endif