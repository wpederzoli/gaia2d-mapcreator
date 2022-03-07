#ifndef MAINMENUFRAME_H
#define MAINMENUFRAME_H

#include <wx/wx.h>
#include <stack>

#include "commands.h"
#include "ids.h"
#include "NewMapFrame.h"

class MainMenuFrame : public wxFrame
{
    private:
        int winId;

        wxPanel* mainPanel;
        wxButton* newButton;
        wxButton* loadButton;
        wxButton* exitButton;

        std::stack<NewMapFrame*>* newMapWindows;

        void OnNew(wxCommandEvent& event);
        void OnLoad(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);

    public:
        MainMenuFrame();
        ~MainMenuFrame();

        void RemoveWindow(NewMapFrame* f);
        wxDECLARE_EVENT_TABLE();
};

#endif