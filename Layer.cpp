#include "Layer.h"

Layer::Layer(int id)
{
    m_bitMap = new wxBitmap();

};

Layer::~Layer() {};

wxBitmap* Layer::GetBitmap() 
{
    return m_bitMap;  
};

void Layer::SetBitmap(wxBitmap& bm) 
{
    wxBitmap* tmp = m_bitMap;
    m_bitMap = new wxBitmap(bm);
    delete tmp;    
};

int Layer::GetId() 
{
    return m_id;    
};