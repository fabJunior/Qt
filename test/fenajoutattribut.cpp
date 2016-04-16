#include "fenajoutattribut.h"

FenAjoutAttribut::FenAjoutAttribut(QWidget *parent) : QDialog(parent)
{
    m_Nom = new QLineEdit;
    m_Type = new QLineEdit;

    m_BAsc = new QCheckBox;
    m_BAsc->setChecked(true);
    m_Asc = new QLineEdit;
    connect(m_BAsc,SIGNAL(clicked(bool)),m_Asc,SLOT(setEnabled(bool)));

    m_BSetter = new QCheckBox;
    m_BSetter->setChecked(true);
    m_Setter = new QLineEdit;
    connect(m_BSetter,SIGNAL(clicked(bool)),m_Setter,SLOT(setEnabled(bool)));



    QFormLayout *formAtt = new QFormLayout;
    formAtt->addRow("Nom de l'attribut :",m_Nom);
    formAtt->addRow("Type de l'attribut :", m_Type);

    QHBoxLayout *ascenseur = new QHBoxLayout;
    ascenseur->addWidget(m_BAsc);
    ascenseur->addWidget(m_Asc);
    QHBoxLayout *setter = new QHBoxLayout;
    setter->addWidget(m_BSetter);
    setter->addWidget(m_Setter);
    formAtt->addRow(ascenseur);
    formAtt->addRow(setter);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formAtt);

    resize(200,130);
    setLayout(mainLayout);
}
