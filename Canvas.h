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

        int m_nPixelSize = 8;

        wxDECLARE_EVENT_TABLE();
    
    public:
        Canvas(wxWindow* parent);
        ~Canvas();

        void setPixelSize(int n);

};

#endif