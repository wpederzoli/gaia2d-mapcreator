#ifndef MAPCREATOR_H
#define MAPCREATOR_H

#include <wx/wx.h>
#include "MainMenuFrame.h"

class MapCreator : public wxApp
{
    public:
        MapCreator();
        ~MapCreator();
        virtual bool OnInit();
};

#endif