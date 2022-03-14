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
            DrawMouse(dc, x, y);
        }
    
    Refresh();
};

void ImageViewer::OnMouseMove(wxMouseEvent& evt) 
{
    m_mousePos = evt.GetPosition();
    evt.Skip();    
};

void ImageViewer::DrawMouse(wxDC& dc, int x, int y)
{
    wxBrush b = dc.GetBrush();
    b.SetColour(wxColor(0, 0, 0, 0) );
    dc.SetBrush(b);
    
    wxPen p = dc.GetPen();
    p.SetStyle(wxPENSTYLE_LONG_DASH);
    p.SetColour(wxColor(255, 0, 0, 50) );
    
    if(m_mouseDownPos.x > x && m_mouseDownPos.x < x + m_tileSize && m_mouseDownPos.y > y && m_mouseDownPos.y < y + m_tileSize)
    {
        p.SetStyle(wxPENSTYLE_SOLID);
        p.SetColour(wxColor(0, 0, 255) );
    }

    if(m_mousePos.x > x && m_mousePos.x < x + m_tileSize && m_mousePos.y > y && m_mousePos.y < y + m_tileSize)
    {
        p.SetStyle(wxPENSTYLE_SOLID);
        p.SetColour(wxColor(0, 0, 255) );
    }

    dc.SetBackground(b);
    dc.SetPen(p);
    dc.DrawRectangle(wxPoint(x, y), wxSize(m_tileSize, m_tileSize) );

    if(m_mouseDown)
    {
        p.SetColour(wxColor(80, 150, 80) );
        b.SetColour(wxColor(100, 130, 20, 1) );
        dc.SetBrush(b);
        dc.SetBackground(b);
        dc.SetPen(p);
        dc.DrawRectangle(m_mouseDownPos, wxSize(m_mousePos.x - m_mouseDownPos.x, m_mousePos.y - m_mouseDownPos.y) );
    }

    //update selection to match tile size
    if(m_mouseDownPos.x > x && m_mouseDownPos.x < x + m_tileSize && m_mouseDownPos.y > y && m_mouseDownPos.y < y + m_tileSize)
    {
        m_mouseDownPos.x = x;
        m_mouseDownPos.y = y;
    }

    if(m_mouseUpPos.x > x && m_mouseUpPos.x < x + m_tileSize && m_mouseUpPos.y > y && m_mouseUpPos.y < y + m_tileSize)
    {
        m_mouseUpPos.x = x;
        m_mouseUpPos.y = y;
    }

    b.SetColour(wxColor(100, 200, 100, 1) );
    dc.SetBrush(b);
    dc.DrawRectangle(m_mouseDownPos, wxSize(m_mouseUpPos.x - m_mouseDownPos.x, m_mouseUpPos.y - m_mouseDownPos.y) );
    
};

void ImageViewer::OnMouseClick(wxMouseEvent& evt) 
{
    m_mouseDownPos = evt.GetPosition();
    m_mouseDown = true;
    evt.Skip();  
};

void ImageViewer::OnMouseRelease(wxMouseEvent& evt)
{
    m_mouseUpPos = evt.GetPosition();
    m_mouseDown = false;
    evt.Skip();
};
