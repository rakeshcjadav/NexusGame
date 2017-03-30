#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screenbase.h"

class CGameScreen : public CScreenBase
{
public:
                    CGameScreen();
                    ~CGameScreen();

    virtual bool    Activate();
    virtual bool    DeActivate();
    virtual void    Update(double timeElapsed);
};

#endif // !GAMESCREEN_H
