#ifndef LAYER_H
#define LAYER_H

#include <wx/wx.h>

class Layer
{
    private:
        wxBitmap* m_bitMap = nullptr;
        int m_id;
        bool m_active;

    public:
        Layer();
        ~Layer();

        wxBitmap* GetBitmap();
        wxBitmap* GetSubBitmap(int x, int y, int w, int h);
};

#endif