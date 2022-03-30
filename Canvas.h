#ifndef CANVAS_H
#define CANVAS_H

#include <map>

#include <wx/wx.h>
#include <wx/vscroll.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcbuffer.h>

#include "Layer.h"

class Canvas : public  wxHVScrolledWindow
{
    private:
        virtual wxCoord OnGetRowHeight(size_t row) const;
        virtual wxCoord OnGetColumnWidth(size_t col) const;

        std::map<int, Layer*>layers;
        Layer* m_activeLayer = nullptr;
        
        int m_cols = 0;
        int m_rows = 0;
        int m_tileSize = 0;
        int m_initialTileSize = 0;

        void OnDraw(wxDC& dc);
        void OnPaint(wxPaintEvent& evt);
        void OnMouseMove(wxMouseEvent& evt);
        void OnMouseDown(wxMouseEvent& evt);
        void OnMouseRightDown(wxMouseEvent& evt);
        void OnMouseUp(wxMouseEvent& evt);

        wxBitmap m_mapBitmap;
        wxBitmap m_activeBitmap;
        wxBitmap m_tmpBitmap;
        wxBitmap m_backgroundBm;

        wxPoint m_mousePosition;

        void DrawLayers(wxDC& dc);
        void DrawBackground(wxDC& dc);
        void DrawGrid(wxDC& dc);
        void DrawActiveSprite(wxDC& dc);

        wxDECLARE_EVENT_TABLE();
    
    public:
        Canvas(wxWindow* parent, int cols, int rows, int ts);
        ~Canvas();

        void setPixelSize(int n);
        void SetActiveBitmap(wxBitmap& bm);

        void AddLayer(int id, Layer* l);
        void RemoveLayer(int id);
        void SetActiveLayer(int id);
};

#endif