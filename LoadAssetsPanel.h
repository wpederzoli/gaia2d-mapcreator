#ifndef LOADASSETSPANEL_H
#define LOADASSETSPANEL_H

#include <wx/wx.h>

class LoadAssetsPanel : public wxPanel
{
    private:
        wxButton* loadAssetsBtn = nullptr;
    
    public:
        LoadAssetsPanel(wxWindow* parent);
        ~LoadAssetsPanel();

};

#endif