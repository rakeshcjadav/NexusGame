#include "pchNexusGame.h"
#include "game.h"
#include "fpscontroller.h"
#include "menuscreen.h"
#include "gamescreen.h"

CGame * CGame::s_pGame = NULL;

CGame::CGame()
{
    m_timeTotalElapsed = 0.0;
    m_pMenuScreen = new CMenuScreen();
    m_pGameScreen = new CGameScreen();
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
		if (s_pGame->InitPrivate() == FALSE)
		{
			return FALSE;
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
    m_pRefActiveScreen->Activate();
}

bool CGame::InitPrivate()
{
    cout << "Starting Game" << endl;
    m_pFPSController = new CFPSController(60);
    SetActiveScreen(SCREEN_MENU);
	return true;
}

bool CGame::Update(double timeElapsed)
{
    m_timeTotalElapsed += timeElapsed;

    static bool bPage = false;
    setactivepage((bPage == false) ? 0 : 1);
    setvisualpage((bPage == true) ? 0 : 1);

    cleardevice();

    m_pRefActiveScreen->Update(timeElapsed);

    setvisualpage((bPage == true) ? 0 : 1);
    bPage = !bPage;
    return true;
}
