#ifndef WALL_H
#define WALL_H

#include "gameobject.h"

// Forward Declarations
class CBrickBase;

class CWall : public CGameObject
{
public:
					CWall(int xPos, int yPos, int iRadius, int iRotationSpeed, int nBricks);
	virtual			~CWall();

	virtual void	Update(double timeElapsed);

private:
	CBrickBase **	m_pListBricks;
	int				m_nBricks;

};

#endif // !WALL_H
