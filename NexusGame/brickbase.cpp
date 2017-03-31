#include "pchNexusGame.h"
#include "brickbase.h"

CBrickBase::CBrickBase(int xPos, int yPos, int iStartAngle, int iEndAngle, int iRadius, int iRotationSpeed)
{
	m_iPosX = xPos;
	m_iPosY = yPos;
	m_iStartAngle = iStartAngle;
	m_iEndAngle = iEndAngle;
	m_iRadius = iRadius;
	m_iRotationSpeed = iRotationSpeed;
	m_timeTotalElapsed = 0.0;
}

CBrickBase::~CBrickBase()
{

}

void CBrickBase::Update(double timeElapsed)
{
	CGameObject::Update(timeElapsed);
}
