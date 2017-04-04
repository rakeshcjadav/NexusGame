#include "pchNexusGame.h"
#include "localplayer.h"
#include "levelbase.h"


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
	m_bMoving = false;
	m_iTargetX = 0;
	m_iTargetY = 0;
	m_timeTravel = 0.0;
	m_xShootDir = 1.0;
	m_yShootDir = 1.0;
	m_pRefCurrentLevel = NULL;
}

CLocalPlayer::~CLocalPlayer()
{

}

void CLocalPlayer::Update(double timeElapsed)
{
	m_timeTotalElapsed += timeElapsed;

	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);

	m_iPosX = m_iStartPosX;
	m_iPosY = m_iStartPosY;
	if(m_bMoving)
	{
		m_timeTravel += timeElapsed;

		m_iPosX += m_xShootDir * m_iMovementSpeed * m_timeTravel;
		m_iPosY += m_yShootDir * m_iMovementSpeed * m_timeTravel;

		bool bRespawnPlayer = false;
		if(m_pRefCurrentLevel->IsColliding(*this, bRespawnPlayer) && bRespawnPlayer)
			Spawn(m_iStartPosX, m_iStartPosY, 10);
	}
	fillellipse(m_iPosX, m_iPosY, m_iRadius, m_iRadius);
}

void CLocalPlayer::SetCurrentLevel(CLevelBase * pLevel)
{
	m_pRefCurrentLevel = pLevel;
}

void CLocalPlayer::Spawn(int xPos, int yPos, int iRadius)
{
	m_iStartPosX = m_iPosX = xPos;
	m_iStartPosY = m_iPosY = yPos;
	m_iRadius = iRadius;
	m_bMoving = false;
	m_timeTravel = 0.0;
}

void CLocalPlayer::ShootAt(int xTarget, int yTarget)
{
	if(m_bMoving == true)
		return;

	m_iTargetX = xTarget;
	m_iTargetY = yTarget;

	double dLength = sqrt((m_iTargetX - m_iStartPosX)*(m_iTargetX - m_iStartPosX) + (m_iTargetY - m_iStartPosY)*(m_iTargetY - m_iStartPosY));
	m_xShootDir = (m_iTargetX - m_iStartPosX)/dLength;
	m_yShootDir = (m_iTargetY - m_iStartPosY)/dLength;

	m_bMoving = true;
	m_timeTravel = 0.0;
}

int CLocalPlayer::GetPosX() const
{
	return m_iPosX;
}

int CLocalPlayer::GetPosY() const
{
	return m_iPosY;
}
