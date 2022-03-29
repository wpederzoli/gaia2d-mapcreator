#ifndef LAYER_H
#define LAYER_H

#include <wx/wx.h>

class Layer
{
    private:
        wxBitmap* m_bitMap;
        int m_id;
        bool m_active;

    public:
        Layer(wxBitmap* bm, int id);
        ~Layer();
};

#endif