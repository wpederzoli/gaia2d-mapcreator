#ifndef SETUPMAPFRAME_H
#define SETUPMAPFRAME_H

#include <wx/wx.h>
#include <wx/spinctrl.h>

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

        wxTextCtrl* mapName;


    public:

        SetupMapFrame(wxFrame* parent);
        ~SetupMapFrame();

        wxDECLARE_EVENT_TABLE();
};

#endif