#include "LoadAssetsPanel.h"

LoadAssetsPanel::LoadAssetsPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
    loadAssetsBtn = new wxButton(this, wxID_ANY, "Load", wxPoint(20, 20), wxDefaultSize);

    SetBackgroundColour(wxColor(200, 133, 233));
};

LoadAssetsPanel::~LoadAssetsPanel(){};