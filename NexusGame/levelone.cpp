#include "pchNexusGame.h"
#include "levelone.h"
#include "wall.h"
#include "nexus.h"
#include "game.h"

CLevelOne::CLevelOne()
{
	m_pWall = new CWall(m_iPosX, m_iPosY, 40, 100, 4);
	//m_pWallTwo = new CWall(m_iPosX, m_iPosY, 60, 120, 6);

	CLocalPlayer::Get().Spawn(m_iPosX, m_iPosY + m_iRadius * 0.9, 10);
}

CLevelOne::~CLevelOne()
{
	delete m_pWall;
}

void CLevelOne::Update(double timeElapsed)
{
	CLevelBase::Update(timeElapsed);

	//m_pWallTwo->Update(timeElapsed);
	m_pWall->Update(timeElapsed);

	m_pNexus->Update(timeElapsed);

	CLocalPlayer::Get().Update(timeElapsed);
}

bool CLevelOne::OnLeftMouseDown(int x, int y)
{
	int distance = sqrt((m_iPosX - x)*(m_iPosX - x) + (m_iPosY - y)*(m_iPosY - y));
	if(distance < m_iRadius)
	{
		CLocalPlayer::Get().ShootAt(m_iPosX, m_iPosY);
		return true;
	}
	return false;
}

bool CLevelOne::OnRightMouseDown(int x, int y)
{
	int distance = sqrt((m_iPosX - x)*(m_iPosX - x) + (m_iPosY - y)*(m_iPosY - y));
	if(distance < m_iRadius)
	{
		CLocalPlayer::Get().Spawn(x, y, 10);
		return true;
	}

	return false;
}

bool CLevelOne::IsColliding(CLocalPlayer & localplayer, bool & bRespawnPlayer)
{
	if(CGameObject::IsCollidingObj(localplayer) == false)
		return false;

	if(m_pWall->IsColliding(localplayer, bRespawnPlayer) == false)
		return false;

	if(bRespawnPlayer == true)
		return true;

	if(m_pNexus->IsCollidingObj(localplayer) == false)
		return false;

	CGame::Get().OnLevelComplete();

	return true;
}
