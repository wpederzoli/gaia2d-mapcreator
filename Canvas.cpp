#include "Canvas.h"

wxBEGIN_EVENT_TABLE(Canvas, wxHVScrolledWindow)
    EVT_PAINT(Canvas::OnPaint)
    EVT_MOTION(Canvas::OnMouseMove)
    EVT_LEFT_DOWN(Canvas::OnMouseDown)
    EVT_RIGHT_DOWN(Canvas::OnMouseRightDown)
    EVT_LEFT_UP(Canvas::OnMouseUp)
wxEND_EVENT_TABLE()

Canvas::Canvas(wxWindow* parent, int cols, int rows, int ts) : wxHVScrolledWindow(parent, wxID_ANY) 
{
    m_tileSize = ts;
    m_initialTileSize = ts;

    SetRowColumnCount(cols, rows);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
};

Canvas::~Canvas(){};

void Canvas::OnPaint(wxPaintEvent& evt) 
{
    wxBufferedPaintDC dc(this);
    PrepareDC(dc);
    OnDraw(dc);
};

void Canvas::OnDraw(wxDC& dc) 
{
    dc.Clear();

    wxBrush brush = dc.GetBrush();
    brush.SetColour(wxColor(0, 0, 0, 0) );
    dc.SetBrush(brush);
    
    wxPen pen = dc.GetPen();
    pen.SetStyle(wxPENSTYLE_LONG_DASH);
    pen.SetColour(wxColor(100, 100, 100) );
    dc.SetPen(pen);

    DrawBackground(dc);
    DrawGrid(dc);
    DrawActiveSprite(dc);
};

void Canvas::OnMouseMove(wxMouseEvent& evt) 
{
    wxPosition p = GetVisibleBegin();
    m_mousePosition = evt.GetPosition();
    m_mousePosition.x += (p.GetCol()*m_tileSize);
    m_mousePosition.y += (p.GetRow()*m_tileSize);
    evt.Skip();
};

void Canvas::OnMouseDown(wxMouseEvent& evt)
{
    wxImage i(m_activeBitmap.ConvertToImage() );
    i.Rescale( (i.GetWidth()/m_initialTileSize)*m_tileSize, (i.GetHeight()/m_initialTileSize)*m_tileSize );
    m_tmpBitmap = wxBitmap(i);
    evt.Skip();
};

void Canvas::OnMouseUp(wxMouseEvent& evt) 
{
    evt.Skip();
};

void Canvas::OnMouseRightDown(wxMouseEvent& evt)
{
    evt.Skip();  
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
    m_activeBitmap = bm; 
};

void Canvas::DrawBackground(wxDC& dc)
{
    if(m_mapBitmap.IsOk() )
    {
        // wxImage i = m_mapBitmap.ConvertToImage();
        // i.Rescale(GetRowCount()*m_tileSize, GetColumnCount()*m_tileSize);
        // wxBitmap bm(i);
        dc.DrawBitmap(m_mapBitmap, wxDefaultPosition);
    }
    
    if(m_tmpBitmap.IsOk() )
    {   
        wxPen p = dc.GetPen();
        p.SetColour(wxColor(255, 255, 255, 0) );
        dc.SetPen(p);

        //Scale bitmap
        dc.DrawBitmap(m_tmpBitmap, m_mousePosition);   
        m_mapBitmap = dc.GetAsBitmap();
        m_tmpBitmap = wxBitmap();
        
        Refresh();
    }
};

void Canvas::DrawGrid(wxDC& dc) 
{
    wxPosition s = GetVisibleBegin();
    wxPosition e = GetVisibleEnd();

    for(int y = s.GetRow(); y < e.GetRow(); y++)
        for(int x = s.GetCol(); x < e.GetCol(); x++)
            dc.DrawRectangle(x*m_tileSize, y*m_tileSize, m_tileSize, m_tileSize);
};

void Canvas::DrawActiveSprite(wxDC& dc) 
{
    if(m_activeBitmap.IsOk() )
    {
        wxImage i = m_activeBitmap.ConvertToImage();
        i.Rescale( (i.GetWidth()/m_initialTileSize)*m_tileSize, (i.GetHeight()/m_initialTileSize)*m_tileSize );
        wxBitmap bm(i);
        dc.DrawBitmap(bm, m_mousePosition);
        Refresh();
    }
};
