#include "Canvas.h"

wxBEGIN_EVENT_TABLE(Canvas, wxHVScrolledWindow)
    EVT_PAINT(Canvas::OnPaint)
    EVT_MOTION(Canvas::OnMouseMove)
wxEND_EVENT_TABLE()

Canvas::Canvas(wxWindow* parent, int cols, int rows, int ts) : wxHVScrolledWindow(parent, wxID_ANY) 
{
    m_tileSize = ts;
    m_initialTileSize = ts;

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

    if(m_activeBitmapLoaded)
    {
        wxImage i = m_activeBitmap.ConvertToImage();
        i.Rescale( (i.GetWidth()/m_initialTileSize)*m_tileSize, (i.GetHeight()/m_initialTileSize)*m_tileSize);
        wxBitmap bm(i);
        dc.DrawBitmap(bm, m_mousePosition);
        Refresh();
    }
};

void Canvas::OnPaint(wxPaintEvent& evt) 
{
    wxBufferedPaintDC dc(this);
    PrepareDC(dc);
    OnDraw(dc);
};

void Canvas::OnMouseMove(wxMouseEvent& evt) 
{
    m_mousePosition = evt.GetPosition();
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
    if(n == 1)
    {
        wxVarHScrollHelper::ScrollToColumn(0);
        wxVarVScrollHelper::ScrollToRow(0);
    }
    
    wxVarHScrollHelper::RefreshAll();
    wxVarVScrollHelper::RefreshAll();
    Refresh();
};

void Canvas::SetActiveBitmap(wxBitmap& bm) 
{
    m_activeBitmapLoaded = true;
    m_activeBitmap = bm; 
};