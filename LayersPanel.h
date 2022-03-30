#ifndef LAYERSPANEL_H
#define LAYERSPANEL_H

#include <wx/wx.h>
#include <map>

#include "ids.h"
#include "Layer.h"
#include "LayerItem.h"
#include "Canvas.h"

class LayersPanel : public  wxPanel
{
    private:
        std::map<int, LayerItem*> layers;
        LayerItem* m_selectedLayer = nullptr;

        wxSizer* m_mainContainer = nullptr;
        wxSizer* m_layersContainer = nullptr;
        wxSizer* m_buttonsContainer = nullptr;

        wxButton* m_addLayerBtn = nullptr;
        wxButton* m_removeLayerBtn = nullptr;

        Canvas* m_canvas = nullptr;

        void OnAddLayer(wxCommandEvent& evt);
        void OnRemoveLayer(wxCommandEvent& evt);
        void OnSelectLayer(wxCommandEvent& evt);

        wxDECLARE_EVENT_TABLE();

    public:
        LayersPanel(wxWindow* parent, Canvas* c);
        ~LayersPanel();
};

#endif