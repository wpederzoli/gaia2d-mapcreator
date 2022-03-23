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
    if(m_backgroundBm.IsOk() && !m_tmpBitmap.IsOk() )
    {
        wxImage i = m_backgroundBm.ConvertToImage();
        i.Rescale(GetColumnCount()*m_tileSize, GetRowCount()*m_tileSize);
        dc.DrawBitmap(i, 0, 0);
    }
    if(m_tmpBitmap.IsOk() )
    {
        int colIndex = m_mousePosition.x/m_tileSize;
        int rowIndex = m_mousePosition.y/m_tileSize;

        wxBitmap bg = wxBitmap(GetColumnCount()*100, GetRowCount()*100);
        wxMemoryDC memdc(bg);
        memdc.Clear();
        wxImage i = m_tmpBitmap.ConvertToImage();
        i.Rescale( (m_tmpBitmap.GetWidth()/m_tileSize)*100, (m_tmpBitmap.GetHeight()/m_tileSize)*100);
        
        if(m_backgroundBm.IsOk() )
        {
            memdc.DrawBitmap(m_backgroundBm, 0, 0);
        }

        memdc.DrawBitmap(i, colIndex*100, rowIndex*100);
        m_backgroundBm = wxBitmap(memdc.GetAsBitmap() );
        memdc.SelectObject(wxNullBitmap);
        m_backgroundBm.SaveFile("tmp.png", wxBITMAP_TYPE_PNG);
        m_tmpBitmap = wxNullBitmap;
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
        dc.DrawBitmap(bm, wxPoint(m_mousePosition.x-bm.GetWidth()/2, m_mousePosition.y-bm.GetHeight()/2) );
        Refresh();
    }
};
