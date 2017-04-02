#include "pchNexusGame.h"
#include "localplayer.h"


CLocalPlayer * CLocalPlayer::s_pLocalPlayer = NULL;

bool CLocalPlayer::Create(int iMovementSpeed)
{
	if(!s_pLocalPlayer)
	{
		s_pLocalPlayer = new CLocalPlayer(iMovementSpeed);
	}
	return !!s_pLocalPlayer;
}

void CLocalPlayer::Destroy()
{
	delete s_pLocalPlayer;
}

CLocalPlayer & CLocalPlayer::Get()
{
	return *s_pLocalPlayer;
}

CLocalPlayer::CLocalPlayer(int iMovementSpeed)
{
	m_iMovementSpeed = iMovementSpeed;
}

CLocalPlayer::~CLocalPlayer()
{

}

void CLocalPlayer::Update(double timeElapsed)
{
	m_timeTotalElapsed += timeElapsed;

	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	fillellipse(m_iPosX, m_iPosY, m_iRadius, m_iRadius);
}

void CLocalPlayer::Spawn(int xPos, int yPos, int iRadius)
{
	m_iPosX = xPos;
	m_iPosY = yPos;
	m_iRadius = iRadius;
}
