#ifndef SCREENBASE_H
#define SCREENBASE_H

class CScreenBase
{
public:
					CScreenBase();
	virtual			~CScreenBase();

	virtual bool	Activate();
	virtual bool	DeActivate();
	virtual void	Update(double timeElapsed) = 0;
	bool			IsActive() const;

protected:
	bool			m_bActive;
	double			m_timeTotalElapsed;
};

#endif // !SCREENBASE_H
