#include "MapImage.h"

MapImage::MapImage(wxImage image, wxPoint pos) 
{
    m_position = pos;
    m_image = image;
};

MapImage::~MapImage(){};

wxImage* MapImage::GetImage() 
{
    return &m_image;    
};

wxPoint MapImage::GetPosition() 
{
    return m_position;    
};

void MapImage::SetPosition(wxPoint pos) 
{
    m_position = pos;    
};

void MapImage::SetPosition(int x, int y) 
{
    m_position.x = x;
    m_position.y = y;    
};