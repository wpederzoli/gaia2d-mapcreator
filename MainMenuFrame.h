#ifndef MAINMENUFRAME_H
#define MAINMENUFRAME_H

#include <wx/wx.h>
#include "commands.h"
#include "ids.h"

class MainMenuFrame : public wxMDIParentFrame
{
    private:
        wxMenuBar* m_menuBar;
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnOpen(wxCommandEvent& event);

    public:
        MainMenuFrame();
        ~MainMenuFrame();

        wxDECLARE_EVENT_TABLE();
};

#endif