#ifndef BRICKBASE_H
#define BRICKBASE_H

#include "gameobject.h"

class CBrickBase : public CGameObject
{
public:
					CBrickBase(int xPos, int yPos, int iStartAngle, int iEndAngle, int iRadius, int iRotationSpeed);
	virtual			~CBrickBase();

	virtual void	Update(double timeElapsed);

protected:
	int				m_iStartAngle;
	int				m_iEndAngle;
	int				m_iRotationSpeed;
};

#endif // !BRICKBASE_H
