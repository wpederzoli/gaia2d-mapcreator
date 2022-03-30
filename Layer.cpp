#include "Layer.h"

Layer::Layer()
{
    m_bitMap = new wxBitmap();
};

Layer::~Layer() {};

wxBitmap* Layer::GetBitmap() 
{
    return m_bitMap;  
};

wxBitmap* Layer::GetSubBitmap(int x, int y, int w, int h) 
{
    return new wxBitmap(m_bitMap->GetSubBitmap(wxRect(x, y, w, h) ) );
};