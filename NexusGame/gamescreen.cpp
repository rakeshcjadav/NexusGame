#include "pchNexusGame.h"
#include "gamescreen.h"
#include "levelone.h"

CGameScreen::CGameScreen()
{
	m_pCurrentLevel = NULL;
	CLocalPlayer::Create(1000);
}

CGameScreen::~CGameScreen()
{
	CLocalPlayer::Destroy();
	DeActivate();
}

bool CGameScreen::Activate()
{
	LevelSelect(LEVEL_ONE);
	return CScreenBase::Activate();
}

bool CGameScreen::DeActivate()
{
	//CLocalPlayer::Destroy();
	delete m_pCurrentLevel;
	return CScreenBase::DeActivate();
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

bool CGameScreen::OnLeftMouseDown(int x, int y)
{
	m_pCurrentLevel->OnLeftMouseDown(x, y);
	return true;
}

bool CGameScreen::OnRightMouseDown(int x, int y)
{
	m_pCurrentLevel->OnRightMouseDown(x, y);
	return true;
}

bool CGameScreen::OnLevelComplete()
{
	if(m_eCurrentLevel >= LEVEL_TOTAL)
		return false;

	LevelSelect(ELEVEL_TYPE(m_eCurrentLevel+1));
}

bool CGameScreen::LevelSelect(ELEVEL_TYPE levelIndex)
{
	switch(levelIndex)
	{
		case LEVEL_ONE:
			m_pCurrentLevel = new CLevelOne();
			break;
		case LEVEL_TWO:
			m_pCurrentLevel = new CLevelOne();
			break;
		case LEVEL_THREE:
			m_pCurrentLevel = new CLevelOne();
			break;
		case LEVEL_FOUR:
			m_pCurrentLevel = new CLevelOne();
			break;
		case LEVEL_FIVE:
			m_pCurrentLevel = new CLevelOne();
			break;
		default:
			return false;
	}
	m_eCurrentLevel = levelIndex;
	CLocalPlayer::Get().SetCurrentLevel(m_pCurrentLevel);
	return true;
}
