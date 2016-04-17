#include "attribut.h"

Attribut::Attribut(QString nomAtt,
                   QString type,
                   bool bAsc,
                   QString asc,
                   bool bSetter,
                   QString setter) :
                        m_NomAtt(nomAtt),
                        m_Type(type),
                        m_BAsc(bAsc),
                        m_Asc(asc),
                        m_BSetter(bSetter),
                        m_Setter(setter)
{

}

Attribut::~Attribut()
{

}

void Attribut::setNomAtt(QString newNom){
    m_NomAtt = newNom;
}

QString Attribut::nomAtt(){
    return m_NomAtt;
}

void Attribut::setType(QString type){
    m_Type = type;
}

QString Attribut::type(){
    return m_Type;
}

void Attribut::setBAsc(bool bAsc){
    m_BAsc = bAsc;
}

bool Attribut::bAsc(){
    return m_BAsc;
}


void Attribut::setAsc(QString asc){
    m_Asc = asc;
}

QString Attribut::asc(){
    return m_Asc;
}


void Attribut::setBSetter(bool bSetter){
    m_BSetter = bSetter;
}

bool Attribut::bSetter(){
    return m_BSetter;
}


void Attribut::setSetter(QString setter){
    m_Setter = setter;
}

QString Attribut::setter(){
    return m_Setter;
}
