#include "SetupMapFrame.h"

wxBEGIN_EVENT_TABLE(SetupMapFrame, wxFrame)
    EVT_BUTTON(SETUP_CANCEL_BUTTON_ID, SetupMapFrame::OnCancel)
wxEND_EVENT_TABLE()

SetupMapFrame::SetupMapFrame(wxFrame* parent) : wxFrame(parent, wxID_ANY, "Setup map", wxDefaultPosition, wxSize(400, 300))
{
    mainPanel = new wxPanel(this, wxID_ANY);
    colsLabel = new wxStaticText(mainPanel, wxID_ANY, "Columns: ", wxPoint(wxDefaultPosition.x + 10, wxDefaultPosition.y + 15), wxSize(100, 50) );
    colsInput = new wxSpinCtrl(mainPanel, wxID_ANY, wxEmptyString, wxPoint(colsLabel->GetPosition().x + 100, colsLabel->GetPosition().y - 10 ), wxSize(150, 25 ) );
    rowsLabel = new wxStaticText(mainPanel, wxID_ANY, "Rows: ", wxPoint(colsLabel->GetPosition().x, colsLabel->GetPosition().y + 30), wxSize(colsLabel->GetSize() ) );
    rowsInput = new wxSpinCtrl(mainPanel, wxID_ANY, wxEmptyString, wxPoint(colsLabel->GetPosition().x + 100, rowsLabel->GetPosition().y - 10), wxSize(150, 25 ) );
    tileWidthLabel = new wxStaticText(mainPanel, wxID_ANY, "Tiles width: ", wxPoint(rowsLabel->GetPosition().x, rowsLabel->GetPosition().y + 30), wxSize(100, 25) );
    tileWidthInput = new wxSpinCtrl(mainPanel, wxID_ANY, wxEmptyString, wxPoint(colsLabel->GetPosition().x + 100, tileWidthLabel->GetPosition().y - 10), wxSize(150, 25) );
    tileHeightLabel = new wxStaticText(mainPanel, wxID_ANY, "Tiles height: ", wxPoint(tileWidthLabel->GetPosition().x, tileWidthLabel->GetPosition().y + 30), wxSize(100, 25) );
    tileWidthInput = new wxSpinCtrl(mainPanel, wxID_ANY, wxEmptyString, wxPoint(colsLabel->GetPosition().x + 100, tileHeightLabel->GetPosition().y - 10), wxSize(150, 25) );
    mapName = new wxTextCtrl(mainPanel, wxID_ANY, "Map name", wxPoint(colsLabel->GetPosition().x + 100, tileHeightLabel->GetPosition().y + 30), wxSize(150, 25) );

    acceptButton = new wxButton(mainPanel, wxID_ANY, "Accept", wxPoint(this->GetSize().GetWidth() - 90, this->GetSize().GetHeight() - 75), wxSize(80, 30) );
    cancelButton = new wxButton(mainPanel, SETUP_CANCEL_BUTTON_ID, "Cancel", wxPoint(50, this->GetSize().GetHeight() - 75), wxSize(80, 30) );

    mainPanel->Show(true);

    Show(true);
};

SetupMapFrame::~SetupMapFrame()
{
    GetParent()->Enable(true);
};

void SetupMapFrame::OnCancel(wxCommandEvent& evt)
{
    this->Destroy();
};

void SetupMapFrame::OnAccept(wxCommandEvent& evt)
{

};