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
        Layer(int id);
        ~Layer();

        wxBitmap* GetBitmap();
        void SetBitmap(wxBitmap& bm);

        int GetId();
};

#endif