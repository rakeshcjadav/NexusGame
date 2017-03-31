#ifndef BREAKABLEBRICK_H
#define BREAKABLEBRICK_H

#include "brickbase.h"

class CBreakableBrick : public CBrickBase
{
public:
					CBreakableBrick(int xPos, int yPos, int iStartAngle, int iEndAngle, int iRadius, int iRotationSpeed);
	virtual			~CBreakableBrick();

	virtual void	Update(double timeElapsed);
};

#endif // !UNBREAKABLEBRICK_H
