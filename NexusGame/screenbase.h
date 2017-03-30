#ifndef SCREENBASE_H
#define SCREENBASE_H

class CScreenBase
{
public:
                    CScreenBase();
                    ~CScreenBase();

    virtual bool    Activate() = 0;
    virtual bool    DeActivate() = 0;
    virtual void    Update(double timeElapsed) = 0;
    bool            IsActive() const;

protected:
    bool            m_bActive;
    double          m_timeTotalElapsed;
};

#endif // !SCREENBASE_H
