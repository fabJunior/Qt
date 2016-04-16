#include "fenajoutattribut.h"
#include "attribut.h"
#include "fenprincipale.h"

FenAjoutAttribut::FenAjoutAttribut(QWidget *parent) : QDialog(parent)
{
    m_Nom = new QLineEdit;
    m_Type = new QLineEdit;

    m_BAsc = new QCheckBox;
    m_BAsc->setChecked(true);
    m_Asc = new QLineEdit;
    m_Asc->setPlaceholderText("Nom de l'ascenseur de l'attribut");
    connect(m_BAsc,SIGNAL(clicked(bool)),m_Asc,SLOT(setEnabled(bool)));

    m_BSetter = new QCheckBox;
    m_BSetter->setChecked(true);
    m_Setter = new QLineEdit;
    m_Setter->setPlaceholderText("Nom du setter de l'attribut");
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

    QPushButton *annuler = new QPushButton("Annuler");
    QPushButton *valider = new QPushButton("Valider");
    connect(valider,SIGNAL(clicked(bool)),this,SLOT(envoyerAttribut()));

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(annuler);
    buttonsLayout->addWidget(valider);
    buttonsLayout->setAlignment(Qt::AlignRight);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formAtt);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
}

void FenAjoutAttribut::envoyerAttribut(){
    if(m_Nom->text().isEmpty()){
        QMessageBox::critical(this, "Nom manquant", "Vous navez pas donné de nom à votre attribut !");
        m_Nom->setFocus();
        return;
    }

    if(m_Type->text().isEmpty()){
        QMessageBox::critical(this, "Type manquant", "Vous navez pas donné de type à votre attribut !");
        m_Type->setFocus();
        return;
    }

    Attribut *att = new Attribut;
    att->setNomAtt(m_Nom->text());
}
