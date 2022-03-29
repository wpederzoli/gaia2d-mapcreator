#include "LayerItem.h"

LayerItem::LayerItem(wxWindow* parent, int id) : wxPanel(parent) 
{
    m_id = id;
    m_label = "Label : " + std::to_string(m_id);
    m_btn = new wxRadioButton(this, wxID_ANY, m_label);
};

LayerItem::~LayerItem() {};

void LayerItem::SetId(int id) 
{
    m_id = id;
    m_label = "Label: " + std::to_string(m_id);
    m_btn->SetLabel(m_label);
};

void LayerItem::Selected(bool active) 
{
    m_btn->SetValue(active);  
};