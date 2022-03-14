#include "ImageViewer.h"

wxBEGIN_EVENT_TABLE(ImageViewer, wxFrame)
    EVT_PAINT(ImageViewer::OnPaint)
    EVT_MOTION(ImageViewer::OnMouseMove)
    EVT_LEFT_DOWN(ImageViewer::OnMouseClick)
    EVT_LEFT_UP(ImageViewer::OnMouseRelease)
wxEND_EVENT_TABLE()

ImageViewer::ImageViewer(wxString filePath, wxWindow* parent ) : wxFrame(parent, wxID_ANY, "Image Viewer")
{   
    m_tileSize = ((LoadAssetsPanel*)GetParent())->GetTileSize();
    bitMap = new wxBitmap(filePath, wxBITMAP_TYPE_PNG);
    SetSize(wxSize(bitMap->GetWidth(), bitMap->GetHeight() ) );
};

ImageViewer::~ImageViewer()
{
    delete bitMap;
};

void ImageViewer::OnPaint(wxPaintEvent& evt) 
{
    wxBufferedPaintDC dc(this);
    dc.Clear();
    dc.DrawBitmap((*bitMap), wxDefaultPosition);


    for(int x = 0; x < bitMap->GetWidth(); x += m_tileSize)
        for(int y = 0; y < bitMap->GetHeight(); y+= m_tileSize)
        {
            DrawLines(dc, x, y);
            DrawMousePosition(dc, x, y);
            
            if(m_mouseDown && m_selected)
                DrawSelection(dc, x, y);
            if(m_selected)
                DrawSelected(dc, x, y);
        }
    
    Refresh();
};


void ImageViewer::DrawLines(wxDC& dc, int x, int y) 
{
    wxBrush b = dc.GetBrush();
    wxPen p = dc.GetPen();

    b.SetColour(wxColor(0, 0, 0, 0) );
    p.SetStyle(wxPENSTYLE_LONG_DASH);
    p.SetColour(wxColor(255, 0, 0, 50) );

    dc.SetBrush(b);
    dc.SetPen(p);

    dc.SetBackground(b);
    dc.DrawRectangle(wxPoint(x, y), wxSize(m_tileSize, m_tileSize) );
};

void ImageViewer::DrawMousePosition(wxDC& dc, int x, int y)
{
    if(m_mousePos.x > x && m_mousePos.x < x + m_tileSize && m_mousePos.y > y && m_mousePos.y < y + m_tileSize)
    {
        wxBrush b = dc.GetBrush();
        wxPen p = dc.GetPen();

        b.SetColour(wxColor(0, 0, 0, 0) );
        p.SetStyle(wxPENSTYLE_SOLID);
        p.SetColour(wxColor(0, 0, 255) );

        dc.SetBrush(b);
        dc.SetPen(p);

        dc.SetBackground(b);
        dc.DrawRectangle(wxPoint(x, y), wxSize(m_tileSize, m_tileSize) );
    }    
};

void ImageViewer::DrawSelection(wxDC& dc, int x, int y)
{
    wxBrush b = dc.GetBrush();
    wxPen p = dc.GetPen();

    b.SetColour(wxColor(100, 180, 110, 3) );
    p.SetStyle(wxPENSTYLE_SOLID);
    p.SetColour(wxColor(0, 255, 0) );

    dc.SetBrush(b);
    dc.SetPen(p);

    dc.SetBackground(b);
    
    wxRect rect(m_mouseDownPos, m_mousePos);
    dc.DrawRectangle(rect);
};

void ImageViewer::DrawSelected(wxDC& dc, int x, int y)
{
    if(m_mouseDownPos.x > x && m_mouseDownPos.x < x + m_tileSize && m_mouseDownPos.y > y && m_mouseDownPos.y < y + m_tileSize)
        m_selectedTiles.SetTopLeft(wxPoint(x, y) );
    if(m_mouseUpPos.x > x && m_mouseUpPos.x < x + m_tileSize && m_mouseUpPos.y > y && m_mouseUpPos.y < y + m_tileSize)
        m_selectedTiles.SetBottomRight(wxPoint(x+m_tileSize, y+m_tileSize) );
    
    wxBrush b = dc.GetBrush();
    wxPen p = dc.GetPen();

    b.SetColour(wxColor(80, 200, 30, 3) );
    p.SetStyle(wxPENSTYLE_SOLID);
    p.SetColour(wxColor(10, 200, 20) );

    dc.SetBrush(b);
    dc.SetPen(p);

    dc.SetBackground(b);
    dc.DrawRectangle(m_selectedTiles);
};

void ImageViewer::OnMouseMove(wxMouseEvent& evt) 
{
    m_mousePos = evt.GetPosition();
    evt.Skip();    
};

void ImageViewer::OnMouseClick(wxMouseEvent& evt) 
{
    m_selected = !m_selected;
    m_mouseDown = true;
    
    if(!m_selected)
    {
        m_selectedTiles.SetTopLeft(wxPoint(0, 0) );
        m_selectedTiles.SetBottomRight(wxPoint(0, 0) );
        m_mouseDownPos = wxPoint(0, 0);
    }
    else
        m_mouseDownPos = evt.GetPosition();
    
    evt.Skip();  
};

void ImageViewer::OnMouseRelease(wxMouseEvent& evt)
{
    m_mouseDown = false;

    if(!m_selected)
        m_mouseUpPos = wxPoint(0, 0);
    else
        m_mouseUpPos = evt.GetPosition();
    
    evt.Skip();
};
