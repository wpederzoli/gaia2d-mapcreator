#ifndef NEWMAPFRAME_H
#define NEWMAPFRAME_H

#include <wx/wx.h>
#include <stack>

class NewMapFrame : wxFrame
{
    private:

    public:
        NewMapFrame(wxFrame* parent);
        ~NewMapFrame();

        wxDECLARE_EVENT_TABLE();
};

#endif