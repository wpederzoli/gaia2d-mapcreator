#ifndef MAINMENUFRAME_H
#define MAINMENUFRAME_H

#include <wx/wx.h>
#include <stack>

#include "commands.h"
#include "ids.h"
#include "SetupMapFrame.h"

class NewMapFrame;

class MainMenuFrame : public wxFrame
{
    private:
        wxPanel* mainPanel;
        wxButton* newButton;
        wxButton* loadButton;
        wxButton* exitButton;
        
        SetupMapFrame* setup;

        void OnNew(wxCommandEvent& event);
        void OnLoad(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);

    public:
        MainMenuFrame();
        ~MainMenuFrame();

        void RemoveElementFromStack(NewMapFrame* f);
        wxDECLARE_EVENT_TABLE();
};

#endif