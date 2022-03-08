#ifndef SETUPMAPFRAME_H
#define SETUPMAPFRAME_H

#include <wx/wx.h>
#include <wx/spinctrl.h>

#include "ids.h"
// #include "NewMapFrame.h"

class SetupMapFrame : public wxFrame
{
    private:
        wxPanel* mainPanel;
        wxStaticText* colsLabel;
        wxSpinCtrl* colsInput;
        wxStaticText* rowsLabel;
        wxSpinCtrl* rowsInput;
        wxStaticText* tileWidthLabel;
        wxSpinCtrl* tileWidthInput;
        wxStaticText* tileHeightLabel;
        wxSpinCtrl* tileHeigthInput;
        wxButton* acceptButton;
        wxButton* cancelButton;

        wxTextCtrl* mapName;


    public:

        SetupMapFrame(wxFrame* parent);
        ~SetupMapFrame();

        void OnCancel(wxCommandEvent& evt);
        void OnAccept(wxCommandEvent& evt);

        wxDECLARE_EVENT_TABLE();
};

#endif