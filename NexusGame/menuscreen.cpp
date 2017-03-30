#include "pchNexusGame.h"
#include "menuscreen.h"
#include "game.h"

#include"def.h"

CMenuScreen::CMenuScreen()
{

}

CMenuScreen::~CMenuScreen()
{

}

bool CMenuScreen::Activate()
{
    m_bActive = true;
    m_timeTotalElapsed = 0.0;
    return true;
}

bool CMenuScreen::DeActivate()
{
    m_bActive = false;
    return false;
}

void CMenuScreen::Update(double timeElapsed)
{
    if(!IsActive())
        return;

    setcolor(WHITE);
    rectangle(1, 1, getmaxx()-1, getmaxy()-1);

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(getmaxx()/2, getmaxy()/4+40, 20, 20);

    setcolor(GREEN);
    settextjustify(CENTER_TEXT, VCENTER_TEXT);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 20);
    outtextxy(getmaxx()/2, getmaxy()/4, "Bull's EYE");

    int sizeX = 120, sizeY = 30;
    setcolor(GREEN);
    setfillstyle(SLASH_FILL, RED);
    int left = getmaxx()/2 - sizeX;
    int top = getmaxy()/2 + 100 - sizeY;
    int right = getmaxx()/2 + sizeX;
    int bottom = getmaxy()/2 + 100 + sizeY;
    bar(left, top, right, bottom);

    settextjustify(CENTER_TEXT, VCENTER_TEXT);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 6);

    if(ismouseclick(WM_LBUTTONDOWN))
    {
        int x,y;
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(x > left && x < right && y > top && y < bottom)
        {
            CGame::Get().SetActiveScreen(SCREEN_GAME);
        }
    }
    outtextxy(getmaxx()/2, getmaxy()/2 + 115, "START");
}
