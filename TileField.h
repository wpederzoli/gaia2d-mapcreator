#ifndef TILEFIELD_H
#define TILEFIELD_H

#include <wx/wx.h>

class TileField : public wxScrolledWindow
{
    private:
    
    public:
        TileField(wxWindow* parent);
        ~TileField();
};

#endif