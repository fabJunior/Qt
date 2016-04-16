#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include <QString>

class attribut
{
    public:
    attribut();
    virtual ~attribut();

    void setNomAtt(QString newNom);
    QString nomAtt();

    void setBAsc(bool bAsc);
    bool bAsc();

    void setAsc(QString asc);
    QString asc();

    void setBSetter(bool bSetter);
    bool bSetter();

    void setSetter(QString setter);
    QString setter();

    void setType(QString type);
    QString type();

    private:
    QString m_NomAtt;
    bool m_BAsc;
    QString m_Asc;
    bool m_BSetter;
    QString m_Setter;
    QString m_Type;
};

#endif // ATTRIBUT_H
