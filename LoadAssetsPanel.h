#ifndef LOADASSETSPANEL_H
#define LOADASSETSPANEL_H

#include <stack>

#include <wx/wx.h>
#include <wx/vscroll.h>

class LoadAssetsPanel : public wxPanel
{
    private:
        wxButton* loadAssetsBtn = nullptr;
        wxHVScrolledWindow* m_assetsWindow = nullptr;
        // std::stack<wxStaticBitmap*> bm;
        std::stack<wxBitmapButton*> bm;
        void OnLoadBtnClick(wxCommandEvent& evt);
        void OnImageClick(wxCommandEvent& evt);

        wxDECLARE_EVENT_TABLE();
    
    public:
        LoadAssetsPanel(wxWindow* parent);
        ~LoadAssetsPanel();

};

#endif