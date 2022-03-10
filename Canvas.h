#ifndef CANVAS_H
#define CANVAS_H

#include <wx/wx.h>
#include <wx/vscroll.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcbuffer.h>

class Canvas : public  wxHVScrolledWindow
{
    private:
        virtual wxCoord OnGetRowHeight(size_t row) const;
        virtual wxCoord OnGetColumnWidth(size_t col) const;

        void OnDraw(wxDC& dc);
        void OnPaint(wxPaintEvent& evt);

        int m_cols = 0;
        int m_rows = 0;
        int m_tileSize = 0;

        wxDECLARE_EVENT_TABLE();
    
    public:
        Canvas(wxWindow* parent, int cols, int rows, int ts);
        ~Canvas();

        void setPixelSize(int n);

};

#endif