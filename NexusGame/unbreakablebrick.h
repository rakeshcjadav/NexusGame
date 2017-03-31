#ifndef UNBREAKABLEBRICK_H
#define UNBREAKABLEBRICK_H

#include "brickbase.h"

class CUnbreakableBrick : public CBrickBase
{
public:
					CUnbreakableBrick(int xPos, int yPos, int iStartAngle, int iEndAngle, int iRadius, int iRotationSpeed);
	virtual			~CUnbreakableBrick();

	virtual void	Update(double timeElapsed);
};

#endif // !UNBREAKABLEBRICK_H
