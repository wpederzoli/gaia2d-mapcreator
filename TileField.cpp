#include "TileField.h"

TileField::TileField(wxWindow* parent) : wxScrolledWindow(parent)
{
    wxSizer* container = new wxBoxSizer(wxVERTICAL);
    wxSizer* sizer = new wxGridSizer(60, 60, 1, 1);

    for(int i = 0; i < 3600; i++)
    {
        int scale =  (GetParent()->GetSize().x/10)/32;
        wxStaticText* p = new wxStaticText(this, wxID_ANY, std::to_string(i), wxDefaultPosition, wxSize(32*scale, 32*scale) );
        // wxPanel* p = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(32*scale, 32*scale) );
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