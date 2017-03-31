#include "pchNexusGame.h"
#include "unbreakablebrick.h"

CUnbreakableBrick::CUnbreakableBrick(int xPos, int yPos, int iStartAngle, int iEndAngle, int iRadius, int iRotationSpeed):
	CBrickBase(xPos, yPos, iStartAngle, iEndAngle, iRadius, iRotationSpeed)
{

}

CUnbreakableBrick::~CUnbreakableBrick()
{

}

void CUnbreakableBrick::Update(double timeElapsed)
{
	CBrickBase::Update(timeElapsed);

	int iS = m_iStartAngle + m_iRotationSpeed * m_timeTotalElapsed;
	int iE = m_iEndAngle + m_iRotationSpeed * m_timeTotalElapsed;

	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, BLACK);
	pieslice(m_iPosX, m_iPosY, iS, iE, m_iRadius);
}
