#ifndef LAYERSPANEL_H
#define LAYERSPANEL_H

#include <wx/wx.h>
#include <map>

#include "LayerItem.h"

class LayersPanel : public  wxPanel
{
    private:
        std::map<int, LayerItem*> layers;

        wxSizer* m_mainContainer = nullptr;
        wxSizer* m_layersContainer = nullptr;
        wxSizer* m_buttonsContainer = nullptr;

        wxButton* m_addLayerBtn = nullptr;
        wxButton* m_removeLayerBtn = nullptr;

        void OnAddLayer(wxCommandEvent& evt);
        void OnRemoveLayer(wxCommandEvent& evt);

        wxDECLARE_EVENT_TABLE();

    public:
        LayersPanel(wxWindow* parent);
        ~LayersPanel();
};

#endif