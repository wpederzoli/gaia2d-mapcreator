#ifndef NEWMAPFRAME_H
#define NEWMAPFRAME_H

#include <wx/wx.h>
#include <wx/glcanvas.h>

#include "MainMenuFrame.h"
#include "Canvas.h"
#include "LoadAssetsPanel.h"

class NewMapFrame : wxFrame
{
    private:
        Canvas* m_canvas = nullptr;
        LoadAssetsPanel* assetsPanel = nullptr;
        wxStatusBar* m_statusBar = nullptr;
        wxSlider* m_zoomSlider = nullptr;

        void OnZoomChange(wxCommandEvent& evt);

    public:
        NewMapFrame(wxFrame* parent, int cols, int rows, int tw, int th, wxString name);
        ~NewMapFrame();

        void OnClose(wxCloseEvent& evt);
        wxDECLARE_EVENT_TABLE();
};

#endif