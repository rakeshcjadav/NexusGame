#include "pchNexusGame.h"
#include "gamescreen.h"

#include"def.h"

CGameScreen::CGameScreen()
{

}

CGameScreen::~CGameScreen()
{

}

bool CGameScreen::Activate()
{
    m_bActive = true;
     m_timeTotalElapsed = 0.0;
    return true;
}

bool CGameScreen::DeActivate()
{
    m_bActive = false;
    return false;
}

void CGameScreen::Update(double timeElapsed)
{
    if(!IsActive())
        return;

    m_timeTotalElapsed += timeElapsed;

    setcolor(WHITE);
    rectangle(1, 1, getmaxx()-1, getmaxy()-1);

    static char pattern[8] = {0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF};
    setfillpattern(pattern, DARKGRAY);
    bar(2, 2, getmaxx()-2, getmaxy()-2);

    char buffer[100];
    sprintf(buffer, "Time Elapsed : %0.f (Secs)", m_timeTotalElapsed);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(10, 10, buffer);
}
