#ifndef LOCALPLAYER_H
#define LOCALPLAYER_H

#include "gameobject.h"

class CLocalPlayer : public CGameObject
{
public:

	static bool				Create(int iMovementSpeed);
	static void 			Destroy();
	static CLocalPlayer &	Get();

	virtual void			Update(double timeElapsed);

	void					Spawn(int xPos, int yPos, int iRadius);

private:
							CLocalPlayer(int iMovementSpeed);
	virtual					~CLocalPlayer();

private:
	static CLocalPlayer *	s_pLocalPlayer;
	int						m_iMovementSpeed;
};

#endif // !LOCALPLAYER_H
