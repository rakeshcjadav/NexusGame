#include "pchNexusGame.h"
#include "wall.h"
#include "breakablebrick.h"
#include "unbreakablebrick.h"

CWall::CWall(int xPos, int yPos, int iRadius, int iRotationSpeed, int nBricks)
{
	m_iPosX = xPos;
	m_iPosY = yPos;
	m_iRadius = iRadius;
	m_nBricks = nBricks;

	if(m_nBricks%2 == 1)
		m_nBricks -= 1;

	if(m_nBricks == 0)
		m_nBricks = 2;

	m_pListBricks = new CBrickBase*[m_nBricks];

	int iBrickAngle = 360/m_nBricks;

	int nEndAngle = 0;
	for(int i = 0; i < m_nBricks; i++)
	{
		if(i%2 == 0)
			m_pListBricks[i] = new CBreakableBrick(m_iPosX, m_iPosY, nEndAngle, (i+1)*iBrickAngle, m_iRadius, iRotationSpeed);
		else
			m_pListBricks[i] = new CUnbreakableBrick(m_iPosX, m_iPosY, nEndAngle, (i+1)*iBrickAngle, m_iRadius, iRotationSpeed);
		nEndAngle = (i+1)*iBrickAngle;
	}
}

CWall::~CWall()
{
	for(int i = 0; i < m_nBricks; i ++)
	{
		delete m_pListBricks[i];
	}

	delete[] m_pListBricks;
}

void CWall::Update(double timeElapsed)
{
	CGameObject::Update(timeElapsed);

	for(int i = 0; i < m_nBricks; i ++)
	{
		m_pListBricks[i]->Update(timeElapsed);
	}
}
