#ifndef LEVELONE_H
#define LEVELONE_H

#include "levelbase.h"

//Forward Declarations
class CWall;

class CLevelOne : public CLevelBase
{
public:
					CLevelOne();
	virtual			~CLevelOne();

	virtual void	Update(double timeElapsed);

private:
	CWall *			m_pWall;
	CWall *			m_pWallTwo;
};

#endif // !LEVELBASE_H
