#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include <QString>

class Attribut
{
    public:
    attribut(QString nomAtt,
             QString type,
             bool bAsc = false,
             QString asc = NULL,
             bool bSetter = false,
             QString setter = NULL);
    virtual ~attribut();

    void setNomAtt(QString newNom);
    QString nomAtt();

    void setType(QString type);
    QString type();

    void setBAsc(bool bAsc);
    bool bAsc();

    void setAsc(QString asc);
    QString asc();

    void setBSetter(bool bSetter);
    bool bSetter();

    void setSetter(QString setter);
    QString setter();

    private:
    QString m_NomAtt;
    QString m_Type;
    bool m_BAsc;
    QString m_Asc;
    bool m_BSetter;
    QString m_Setter;
};

#endif // ATTRIBUT_H
