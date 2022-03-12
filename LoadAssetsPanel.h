#ifndef LOADASSETSPANEL_H
#define LOADASSETSPANEL_H

#include <stack>

#include <wx/wx.h>
#include <wx/vscroll.h>

#include "ids.h"
#include "ThumbImage.h"
#include "NewMapFrame.h"

class ThumbImage;

class LoadAssetsPanel : public wxPanel
{
    private:
        wxButton* loadAssetsBtn = nullptr;
        wxHVScrolledWindow* m_assetsWindow = nullptr;
        std::stack<ThumbImage*> thumbImages;

        int m_tileSize = 0;

        void OnLoadBtnClick(wxCommandEvent& evt);
        void OnImageClick(wxCommandEvent& evt);

        wxDECLARE_EVENT_TABLE();
    
    public:
        LoadAssetsPanel(wxWindow* parent, int ts);
        ~LoadAssetsPanel();

        int GetTileSize(){ return m_tileSize; };

};

#endif