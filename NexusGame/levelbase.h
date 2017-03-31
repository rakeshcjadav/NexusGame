#ifndef LEVELBASE_H
#define LEVELBASE_H

#include "gameobject.h"

// Forward Declarations
class CNexus;

class CLevelBase : public CGameObject
{
public:
					CLevelBase();
	virtual			~CLevelBase();

	virtual void	Update(double timeElapsed);

protected:
	CNexus *		m_pNexus;

};

#endif // !LEVELBASE_H
