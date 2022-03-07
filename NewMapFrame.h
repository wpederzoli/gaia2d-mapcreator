#ifndef NEWMAPFRAME_H
#define NEWMAPFRAME_H

#include <wx/wx.h>
#include <stack>

#include "MainMenuFrame.h"

class NewMapFrame : wxFrame
{
    private:

    public:
        NewMapFrame(wxFrame* parent);
        ~NewMapFrame();

        void OnClose(wxCloseEvent& evt);
        wxDECLARE_EVENT_TABLE();
};

#endif