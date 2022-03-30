#include "LayersPanel.h"

wxBEGIN_EVENT_TABLE(LayersPanel, wxPanel)
    EVT_BUTTON(ADD_LAYER_BUTTON, LayersPanel::OnAddLayer)
    EVT_BUTTON(REMOVE_LAYER_BUTTON, LayersPanel::OnRemoveLayer)
    EVT_CHECKBOX(wxID_ANY, LayersPanel::OnSelectLayer)
wxEND_EVENT_TABLE()

LayersPanel::LayersPanel(wxWindow* parent) : wxPanel(parent)
{
    SetBackgroundColour("Lightgrey");
    m_mainContainer = new wxBoxSizer(wxVERTICAL);

    m_buttonsContainer =  new wxBoxSizer(wxHORIZONTAL);
    m_layersContainer = new wxBoxSizer(wxVERTICAL);

    wxButton* newLayerBtn = new wxButton(this, ADD_LAYER_BUTTON, "Add");
    wxButton* deleteLatyer = new wxButton(this, REMOVE_LAYER_BUTTON, "Remove");
    
    m_buttonsContainer->Add(newLayerBtn, 1, wxALIGN_CENTER, 0);
    m_buttonsContainer->Add(deleteLatyer, 1, wxALIGN_CENTER, 0);

    LayerItem* layer1 = new LayerItem(this, 1);
    layer1->Selected(true);
    m_selectedLayer = layer1;

    m_layersContainer->Add(layer1);
    layers.insert({1, layer1});

    m_mainContainer->Add(m_layersContainer, 3, wxALIGN_LEFT, 0);
    m_mainContainer->Add(m_buttonsContainer, 1, wxALIGN_CENTER, 0);

    SetSizer(m_mainContainer);
};

LayersPanel::~LayersPanel()
{
    while(!layers.empty() )
    {
        delete layers.begin()->second;
        layers.erase(layers.begin() );
    }
};

void LayersPanel::OnAddLayer(wxCommandEvent& evt) 
{   
    int id = 0;
    if(!layers.empty() )
        id = layers.rbegin()->second->GetId() + 1;

    LayerItem* newLayer = new LayerItem(this, id);
    
    m_layersContainer->AddSpacer(1);
    m_layersContainer->Add(newLayer);
    m_layersContainer->Layout();

    layers.insert({id, newLayer});

    evt.Skip();
};

void LayersPanel::OnRemoveLayer(wxCommandEvent& evt) 
{
    if(m_selectedLayer)
    {
        m_selectedLayer->Hide();
        m_layersContainer->Layout();

        layers.erase(m_selectedLayer->GetId() );
        delete m_selectedLayer;

        m_selectedLayer = nullptr;
    }

    evt.Skip();
};

void LayersPanel::OnSelectLayer(wxCommandEvent& evt) 
{
    if(!evt.IsChecked() )
    {
        m_selectedLayer->Selected(true);
        return;
    }

    if(m_selectedLayer)
        m_selectedLayer->Selected(false);
    
    m_selectedLayer = (LayerItem*)((wxCheckBox*)evt.GetEventObject())->GetParent();
    evt.Skip();    
}