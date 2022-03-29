#ifndef LAYERITEM_H
#define LAYERITEM_H

#include <wx/wx.h>

class LayerItem : public wxPanel
{
    private:
        wxString m_label = wxEmptyString;
        int m_id = 0;
        wxRadioButton* m_btn = nullptr;

    public:
        LayerItem(wxWindow* parent, int id);
        ~LayerItem();

        void SetId(int id);
        void Selected(bool active);
};

#endif