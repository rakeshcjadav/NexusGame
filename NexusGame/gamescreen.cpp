#include "pchNexusGame.h"
#include "gamescreen.h"
#include "levelone.h"

CGameScreen::CGameScreen()
{
	m_pCurrentLevel = NULL;
}

CGameScreen::~CGameScreen()
{
	DeActivate();
}

bool CGameScreen::Activate()
{
	m_pCurrentLevel = new CLevelOne();
	return CScreenBase::Activate();
}

bool CGameScreen::DeActivate()
{
    delete m_pCurrentLevel;
    return CGameScreen::DeActivate();
}

void CGameScreen::Update(double timeElapsed)
{
    if(!IsActive())
        return;

    m_timeTotalElapsed += timeElapsed;

    setcolor(WHITE);
    rectangle(1, 1, getmaxx()-1, getmaxy()-1);

    static char pattern[8] = {0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF};
    setfillpattern(pattern, WHITE);
    //setfillstyle(SOLID_FILL, WHITE);
    bar(2, 2, getmaxx()-2, getmaxy()-2);

    char buffer[100];
    sprintf(buffer, "Time Elapsed : %0.2f (Secs)", m_timeTotalElapsed);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(10, 10, buffer);

    m_pCurrentLevel->Update(timeElapsed);
}
