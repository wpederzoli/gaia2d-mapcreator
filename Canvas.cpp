#include "Canvas.h"

wxBEGIN_EVENT_TABLE(Canvas, wxHVScrolledWindow)
    EVT_PAINT(Canvas::OnPaint)
wxEND_EVENT_TABLE()

Canvas::Canvas(wxWindow* parent, int cols, int rows, int ts) : wxHVScrolledWindow(parent, wxID_ANY) 
{
    m_tileSize = ts;

    SetRowColumnCount(cols, rows);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
};

Canvas::~Canvas(){};

void Canvas::OnDraw(wxDC& dc) 
{
    dc.Clear();

    wxBrush brush = dc.GetBrush();
    wxPen pen = dc.GetPen();

    wxPosition s = GetVisibleBegin();
    wxPosition e = GetVisibleEnd();

    pen.SetStyle(wxPENSTYLE_LONG_DASH);
    pen.SetColour(wxColor(200, 200, 200));
    dc.SetPen(pen);

    for(int y = s.GetRow(); y < e.GetRow(); y++)
        for(int x = s.GetCol(); x < e.GetCol(); x++)
        {
            dc.SetBrush(brush);
            dc.DrawRectangle(x*m_tileSize, y*m_tileSize, m_tileSize, m_tileSize);
        }
};

void Canvas::OnPaint(wxPaintEvent& evt) 
{
    wxBufferedPaintDC dc(this);
    PrepareDC(dc);
    OnDraw(dc);
};

wxCoord Canvas::OnGetColumnWidth(size_t col) const 
{
    return wxCoord(m_tileSize);    
};

wxCoord Canvas::OnGetRowHeight(size_t row) const 
{
    return wxCoord(m_tileSize);
};

void Canvas::setPixelSize(int n) 
{
    m_tileSize = n;
    wxVarHScrollHelper::RefreshAll();
    wxVarVScrollHelper::RefreshAll();
    Refresh();
};