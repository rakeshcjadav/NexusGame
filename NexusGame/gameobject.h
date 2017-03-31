#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class CGameObject
{
public:
					CGameObject();
	virtual			~CGameObject();

	virtual void	Update(double timeElapsed);

protected:
	int				m_iPosX;
	int				m_iPosY;
	int				m_iRadius;

	double			m_timeTotalElapsed;
};

#endif // !GAMEOBJECT_H
