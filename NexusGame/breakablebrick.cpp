#include "pchNexusGame.h"
#include "breakablebrick.h"

CBreakableBrick::CBreakableBrick(int xPos, int yPos, int iStartAngle, int iEndAngle, int iRadius, int iRotationSpeed):
	CBrickBase(xPos, yPos, iStartAngle, iEndAngle, iRadius, iRotationSpeed)
{

}

CBreakableBrick::~CBreakableBrick()
{

}

void CBreakableBrick::Update(double timeElapsed)
{
	CBrickBase::Update(timeElapsed);

	m_iCurStartAngle = m_iStartAngle + m_iRotationSpeed * m_timeTotalElapsed;
	m_iCurEndAngle = m_iEndAngle + m_iRotationSpeed * m_timeTotalElapsed;

	m_iCurStartAngle = m_iCurStartAngle % 360;
	m_iCurEndAngle = m_iCurEndAngle % 360;

	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, WHITE);
	pieslice(m_iPosX, m_iPosY, m_iCurStartAngle, m_iCurEndAngle, m_iRadius);
}

bool CBreakableBrick::IsColliding(CLocalPlayer & localplayer)
{
	return CBrickBase::IsColliding(localplayer);
}

bool CBreakableBrick::IsBreakable() const
{
	return true;
}
