#ifndef NEWMAPFRAME_H
#define NEWMAPFRAME_H

#include <wx/wx.h>
#include <wx/glcanvas.h>

#include "MainMenuFrame.h"
#include "TileField.h"

class NewMapFrame : wxMDIParentFrame
{
    private:

    public:
        NewMapFrame(wxFrame* parent, int cols, int rows, int tw, int th, wxString name);
        ~NewMapFrame();

        void OnClose(wxCloseEvent& evt);
        wxDECLARE_EVENT_TABLE();
};

#endif