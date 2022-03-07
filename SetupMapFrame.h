#ifndef SETUPMAPFRAME_H
#define SETUPMAPFRAME_H

#include <wx/wx.h>

class SetupMapFrame : public wxFrame
{
    private:
        wxPanel* mainPanel;
        wxTextCtrl* input;

    public:

        SetupMapFrame(wxFrame* parent);
        ~SetupMapFrame();

        wxDECLARE_EVENT_TABLE();
};

#endif