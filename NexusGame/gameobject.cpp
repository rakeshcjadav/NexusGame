#include "pchNexusGame.h"
#include "gameobject.h"


CGameObject::CGameObject()
{
    m_iPosX = 0;
    m_iPosY = 0;
    m_iRadius = 1;
    m_timeTotalElapsed = 0.0;
}

CGameObject::~CGameObject()
{

}

void CGameObject::Update(double timeElapsed)
{
    m_timeTotalElapsed += timeElapsed;
}
