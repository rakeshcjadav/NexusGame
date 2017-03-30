#include "pchNexusGame.h"
#include "screenbase.h"

CScreenBase::CScreenBase()
{
    m_bActive = false;
    m_timeTotalElapsed = 0.0;
}

CScreenBase::~CScreenBase()
{

}

bool CScreenBase::IsActive() const
{
    return m_bActive;
}
