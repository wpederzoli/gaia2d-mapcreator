#include "ImageViewer.h"

wxBEGIN_EVENT_TABLE(ImageViewer, wxFrame)
    EVT_PAINT(ImageViewer::OnPaint)
    EVT_MOTION(ImageViewer::OnMouseMove)
wxEND_EVENT_TABLE()

ImageViewer::ImageViewer(wxString filePath, wxWindow* parent) : wxFrame(parent, wxID_ANY, "Image Viewer")
{     
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
    wxBrush b = dc.GetBrush();
    b.SetColour(wxColor(0, 0, 0, 0) );
    dc.SetBrush(b);

    for(int x = 0; x < bitMap->GetWidth(); x += 30)
        for(int y = 0; y < bitMap->GetHeight(); y+=30)
        {
            dc.SetBackground(b);
            DrawMouse(dc, x, y);
            // dc.DrawRectangle(wxPoint(x, y), wxSize(30, 30) );
        }
    
    Refresh();
};

void ImageViewer::OnMouseMove(wxMouseEvent& evt) 
{
    mousePos = evt.GetPosition();
    evt.Skip();    
};

void ImageViewer::DrawMouse(wxDC& dc, int x, int y)
{
    wxPen p = dc.GetPen();
    p.SetStyle(wxPENSTYLE_LONG_DASH);
    p.SetColour(wxColor(255, 0, 0, 50) );
    
    if(mousePos.x > x && mousePos.x < x + 30 && mousePos.y > y && mousePos.y < y + 30)
    {
        p.SetStyle(wxPENSTYLE_SOLID);
        p.SetColour(wxColor(0, 0, 255) );
    }

    dc.SetPen(p);
    dc.DrawRectangle(wxPoint(x, y), wxSize(30, 30));
};
