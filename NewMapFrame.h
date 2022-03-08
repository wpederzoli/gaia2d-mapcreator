#ifndef NEWMAPFRAME_H
#define NEWMAPFRAME_H

#include <wx/wx.h>
#include <wx/aui/framemanager.h>
#include <stack>

#include "MainMenuFrame.h"

class NewMapFrame : wxFrame
{
    private:

    public:
        NewMapFrame(wxFrame* parent, int cols, int rows, int tw, int th, wxString name);
        ~NewMapFrame();

        void OnClose(wxCloseEvent& evt);
        wxDECLARE_EVENT_TABLE();
};

#endif