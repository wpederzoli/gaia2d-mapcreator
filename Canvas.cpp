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

    SetRowColumnCount(rows, cols);
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

    DrawLayers(dc);
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
    int colIndex = m_mousePosition.x/m_tileSize;
    int rowIndex = m_mousePosition.y/m_tileSize;
    
    wxMemoryDC mdc( (*m_activeLayer->GetBitmap()) );
    mdc.SetBrush(MASK_RGB);
    mdc.SetPen(MASK_RGB);

    mdc.DrawRectangle(wxRect(colIndex*m_initialTileSize, rowIndex*m_initialTileSize, m_initialTileSize+1, m_initialTileSize+1) );
    
    wxBitmap bm = mdc.GetAsBitmap();
    wxImage i = bm.ConvertToImage();
    i.SetMaskColour(MASK_RGB.Red(), MASK_RGB.Green(), MASK_RGB.Blue() );

    mdc.DrawBitmap(bm, 0, 0, true);

    bm = mdc.GetAsBitmap();

    m_activeLayer->SetBitmap(bm);
    mdc.SelectObject(wxNullBitmap);

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

void Canvas::DrawLayers(wxDC& dc) 
{
    std::map<int, Layer*>::iterator it;
    for(it = layers.begin(); it != layers.end(); it++)
    {
        if(it->second->GetBitmap()->IsOk() )
        {
            wxBitmap* bm = new wxBitmap(it->second->GetBitmap()->GetSubBitmap(
                                wxRect(GetVisibleBegin().GetCol()*m_initialTileSize,
                                            GetVisibleBegin().GetRow()*m_initialTileSize,
                                            GetVisibleEnd().GetCol()*m_initialTileSize - GetVisibleBegin().GetCol()*m_initialTileSize,
                                            GetVisibleEnd().GetRow()*m_initialTileSize - GetVisibleBegin().GetRow()*m_initialTileSize 
                                    ) 
                                )   
                            );
            
            wxImage* i = new wxImage(bm->ConvertToImage() );
            i->Rescale( (GetVisibleEnd().GetCol() - GetVisibleBegin().GetCol() )*m_tileSize,
                        (GetVisibleEnd().GetRow() - GetVisibleBegin().GetRow() )*m_tileSize );
            i->SetMaskColour(MASK_RGB.Red(), MASK_RGB.Green(), MASK_RGB.Blue() );
            i->SetMask(true);

            dc.DrawBitmap( (*i), GetVisibleBegin().GetCol()*m_tileSize, GetVisibleBegin().GetRow()*m_tileSize, true);
            
            Refresh();
            delete bm;
            delete i;
        }
    }  
};

void Canvas::DrawBackground(wxDC& dc)
{
    if(m_tmpBitmap.IsOk() )
    {
        int colIndex = m_mousePosition.x/m_tileSize;
        int rowIndex = m_mousePosition.y/m_tileSize;

        wxBitmap bg = wxBitmap( GetColumnCount()*m_initialTileSize, GetRowCount()*m_initialTileSize);
        wxMemoryDC memdc(bg);
        
        //adding the mask color so we can render each layer's background transparent
        memdc.SetBackground(wxBrush(MASK_RGB) );
        memdc.Clear();

        if(m_activeLayer->GetBitmap()->IsOk() )
        {
            memdc.DrawBitmap((*m_activeLayer->GetBitmap() ), 0, 0);
        }

        wxImage i = m_activeBitmap.ConvertToImage();
        i.Rescale( (i.GetWidth()/m_initialTileSize)*m_initialTileSize, (i.GetHeight()/m_initialTileSize)*m_initialTileSize);
        memdc.DrawBitmap(i, colIndex*m_initialTileSize, rowIndex*m_initialTileSize);
        wxBitmap bm = memdc.GetAsBitmap();
        m_activeLayer->SetBitmap(bm); 
        memdc.SelectObject(wxNullBitmap);
        m_tmpBitmap = wxNullBitmap;

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
        int colIndex = m_mousePosition.x/m_tileSize;
        int rowIndex = m_mousePosition.y/m_tileSize;
        
        wxImage i = m_activeBitmap.ConvertToImage();
        i.Rescale( (i.GetWidth()/m_initialTileSize)*m_tileSize, (i.GetHeight()/m_initialTileSize)*m_tileSize );
        wxBitmap bm(i);
        
        dc.DrawBitmap(bm, wxPoint(colIndex*m_tileSize, rowIndex*m_tileSize) );
        Refresh();
    }
};

void Canvas::AddLayer(int id, Layer* l) 
{
    layers.insert({id, l});  
};

void Canvas::RemoveLayer(int id)
{
    layers.erase(id);
};

void Canvas::SetActiveLayer(int id) 
{
    std::map<int, Layer*>::iterator it;
    it = layers.find(id);
    if(it != layers.end() )
        m_activeLayer = it->second;  
};
