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

bool CScreenBase::Activate()
{
    m_bActive = true;
    m_timeTotalElapsed = 0.0;
    return true;
}

bool CScreenBase::DeActivate()
{
    m_bActive = false;
    return false;
}

bool CScreenBase::IsActive() const
{
    return m_bActive;
}

