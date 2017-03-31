#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "screenbase.h"

class CMenuScreen : public CScreenBase
{
public:
					CMenuScreen();
	virtual			~CMenuScreen();

	virtual void	Update(double timeElapsed);
};

#endif // !MENUSCREEN_H
