#include "MapCreator.h"

wxIMPLEMENT_APP(MapCreator);

MapCreator::MapCreator(){};

MapCreator::~MapCreator(){};

bool MapCreator::OnInit()
{
    MainMenuFrame* frame = new MainMenuFrame();
    frame->Show(true);
    return true;
}
 