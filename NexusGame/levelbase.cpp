#include "pchNexusGame.h"
#include "levelbase.h"
#include "nexus.h"

CLevelBase::CLevelBase()
{
	m_iPosX = getmaxx()/2.0;
	m_iPosY = getmaxy()/2.0;
	m_iRadius = 340;
	m_timeTotalElapsed = 0.0;

	m_pNexus = new CNexus(m_iPosX, m_iPosY);
}

CLevelBase::~CLevelBase()
{
	delete m_pNexus;
}

void CLevelBase::Update(double timeElapsed)
{
	CGameObject::Update(timeElapsed);

	setcolor(BLUE);
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	fillellipse(m_iPosX, m_iPosY, m_iRadius, m_iRadius);
}
