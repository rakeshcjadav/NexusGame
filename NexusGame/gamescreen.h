#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screenbase.h"

// Forward Declarations
class CLevelBase;

class CGameScreen : public CScreenBase
{
public:
					CGameScreen();
					~CGameScreen();

	virtual bool	Activate();
	virtual bool	DeActivate();
	virtual void	Update(double timeElapsed);

private:
	CLevelBase *	m_pCurrentLevel;
};

#endif // !GAMESCREEN_H
