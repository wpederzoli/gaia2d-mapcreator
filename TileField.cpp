#include "TileField.h"

TileField::TileField(wxWindow* parent) : wxScrolledWindow(parent)
{
    wxSizer* sizer = new wxGridSizer(10, 10, 32, 32);

    for(int i = 0; i < 100; i++)
    {
        wxPanel* p = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(100, 200));
        p->SetBackgroundColour("Blue");
        sizer->Add(p, 1, wxSHAPED, 0);
    }

    SetSizer(sizer);

    SetScrollRate(10, 10);
};

TileField::~TileField()
{

};