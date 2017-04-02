#include "pchNexusGame.h"
#include "game.h"
#include "fpscontroller.h"
#include "menuscreen.h"
#include "gamescreen.h"

CGame * CGame::s_pGame = NULL;

void LeftMouseDownListener(int x, int y)
{
	CGame::Get().OnLeftMouseDown(x, y);
}

void RightMouseDownListener(int x, int y)
{
	CGame::Get().OnRightMouseDown(x, y);
}

CGame::CGame()
{
	m_timeTotalElapsed = 0.0;
	m_pMenuScreen = new CMenuScreen();
	m_pGameScreen = new CGameScreen();
	m_pRefActiveScreen = NULL;
}

CGame::~CGame()
{
	delete m_pMenuScreen;
	delete m_pGameScreen;
}

bool CGame::Start()
{
	if (s_pGame == NULL)
	{
		s_pGame = new CGame();
		if (s_pGame->InitPrivate() == false)
		{
			return false;
		}
	}
	return true;
}

void CGame::Stop()
{
	cout << "Stopping Game" << endl;
	delete s_pGame;
}

CGame & CGame::Get()
{
	return *s_pGame;
}

bool CGame::Run()
{
	while(!kbhit())
	{
		double timeElapsed = m_pFPSController->Update();
		this->Update(timeElapsed);
	}
	return true;
}

void CGame::SetActiveScreen(ESCREEN_TYPE type)
{
	if(type == SCREEN_NONE)
		return;

	if(m_pRefActiveScreen)
		m_pRefActiveScreen->DeActivate();

	if(type == SCREEN_GAME)
	{
		m_pRefActiveScreen = m_pGameScreen;
	}
	else if(type == SCREEN_MENU)
	{
		m_pRefActiveScreen = m_pMenuScreen;
	}
	else
	{
		m_pRefActiveScreen = NULL;
	}

	if(m_pRefActiveScreen)
		m_pRefActiveScreen->Activate();
}

bool CGame::InitPrivate()
{
	cout << "Starting Game" << endl;
	m_pFPSController = new CFPSController(100);
	SetActiveScreen(SCREEN_MENU);

	registermousehandler(WM_LBUTTONDOWN, LeftMouseDownListener);
	registermousehandler(WM_RBUTTONDOWN, RightMouseDownListener);
	return true;
}

bool CGame::Update(double timeElapsed)
{
	m_timeTotalElapsed += timeElapsed;

	static int nPage = 0;
	setactivepage(nPage);
	setvisualpage(1-nPage);

	cleardevice();

	m_pRefActiveScreen->Update(timeElapsed);

	nPage = 1 - nPage;
	return true;
}

void CGame::OnLeftMouseDown(int x, int y)
{
	cout << "Left x : " << x  << " " << "y : " << y << endl;
}

void CGame::OnRightMouseDown(int x, int y)
{
	cout << "Right x : " << x  << " " << "y : " << y << endl;
	//Jay swaminarayan : CMouse class to as listener to all mouse events and forward them to game.
}
