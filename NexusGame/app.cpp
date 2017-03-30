#include "pchNexusGame.h"
#include "app.h"
#include "game.h"

void CApp::Run()
{
    if(CGame::Start())
    {
       CGame::Get().Run();
    }

    CGame::Stop();
}

CApp::CApp()
{
    initwindow(1280, 720);
}

CApp::~CApp()
{

}
