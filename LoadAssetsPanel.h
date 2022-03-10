#ifndef LOADASSETSPANEL_H
#define LOADASSETSPANEL_H

#include <string>
#include <wx/wx.h>

class LoadAssetsPanel : public wxPanel
{
    private:
        wxButton* loadAssetsBtn = nullptr;
        void OnLoadBtnClick(wxCommandEvent& evt);

        wxDECLARE_EVENT_TABLE();
    
    public:
        LoadAssetsPanel(wxWindow* parent);
        ~LoadAssetsPanel();

};

#endif