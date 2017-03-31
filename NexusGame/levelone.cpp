#include "pchNexusGame.h"
#include "levelone.h"
#include "wall.h"
#include "nexus.h"

CLevelOne::CLevelOne()
{
	m_pWall = new CWall(m_iPosX, m_iPosY, 40, 90, 4);
	//m_pWallTwo = new CWall(m_iPosX, m_iPosY, 60, 120, 6);
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
}
