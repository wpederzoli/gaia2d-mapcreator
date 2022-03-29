#include "Layer.h"

Layer::Layer(wxBitmap* bm, int id)
{
    m_bitMap = bm;
    m_id = id;
};

Layer::~Layer() {};