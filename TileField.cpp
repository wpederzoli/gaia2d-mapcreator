#include "TileField.h"

TileField::TileField(wxWindow* parent, int col, int row, int tw, int th) : wxScrolledWindow(parent)
{
    wxSizer* container = new wxBoxSizer(wxVERTICAL);
    wxSizer* sizer = new wxGridSizer(row, col, 1, 1);

    for(int i = 0; i < col*row; i++)
    {
        int scale;
        if(col > row)
            scale = (GetParent()->GetSize().y/col)/tw;
        else
            scale = (GetParent()->GetSize().x/row)/th;

        wxStaticText* p = new wxStaticText(this, wxID_ANY, std::to_string(i), wxDefaultPosition, wxSize(tw*scale, th*scale) );
        p->SetBackgroundColour("White");
        p->SetForegroundColour("LightGrey");
        sizer->Add(p, 1, wxSHAPED, 0);
    }

    container->Add(sizer, 0, wxSHAPED|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 0);

    SetSizer(container);
    SetScrollRate(10, 10);
};

TileField::~TileField()
{

};