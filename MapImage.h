#ifndef MAPIMAGE_H
#define MAPIMAGE_H

#include <wx/wx.h>

class MapImage
{
    private:
        wxPoint m_position;
        wxImage m_image;

    public:
        MapImage(wxImage image, wxPoint pos);
        ~MapImage();

        wxImage* GetImage();

        void SetPosition(wxPoint pos);
        void SetPosition(int x, int y);
        wxPoint GetPosition();
};

#endif