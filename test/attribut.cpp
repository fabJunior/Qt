#include "attribut.h"

attribut::attribut(QString nomAtt,
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

attribut::~attribut()
{

}

void attribut::setNomAtt(QString newNom){
    m_NomAtt = newNom;
}

QString attribut::nomAtt(){
    return m_NomAtt;
}

void attribut::setType(QString type){
    m_Type = type;
}

QString attribut::type(){
    return m_Type;
}

void attribut::setBAsc(bool bAsc){
    m_BAsc = bAsc;
}

bool attribut::bAsc(){
    return m_BAsc;
}


void attribut::setAsc(QString asc){
    m_Asc = asc;
}

QString attribut::asc(){
    return m_Asc;
}


void attribut::setBSetter(bool bSetter){
    m_BSetter = bSetter;
}

bool attribut::bSetter(){
    return m_BSetter;
}


void attribut::setSetter(QString setter){
    m_Setter = setter;
}

QString attribut::setter(){
    return m_Setter;
}
