#ifndef TILEFIELD_H
#define TILEFIELD_H

#include <wx/wx.h>

class TileField : public wxScrolledWindow
{
    private:
    
    public:
        TileField(wxWindow* parent, int col, int row, int tw, int th);
        ~TileField();
};

#endif