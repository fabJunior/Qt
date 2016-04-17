#include "fenajoutattribut.h"
#include "attribut.h"
#include "fenprincipale.h"

static int attRow;

FenAjoutAttribut::FenAjoutAttribut(FenPrincipale *parent, Attribut att, int row) : QDialog(parent), m_Parent(parent)
{
    attRow = row;

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

    if(row != -1){
        m_Nom->text() = att.nomAtt();
        m_Type->text() = att.type();
        m_BAsc->setChecked(att.bAsc());
        m_Asc->text() = att.asc();
        m_BSetter->setChecked(att.bSetter());
        m_Setter->text() = att.setter();
    }

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

    Attribut att(m_Nom->text(),m_Type->text());
    if(row =! -1){
        m_Parent->updateAttribut(row,att);
    }else{
        m_Parent->recupererAttribut(att);
    }


    reset();

    close();
}

void FenAjoutAttribut::reset(){
    m_Nom->setText("");
    m_Type->setText("");

    m_BAsc->setChecked(true);
    m_Asc->setText("");
    m_Asc->setEnabled(true);

    m_BSetter->setChecked(true);
    m_Setter->setText("");
    m_Setter->setEnabled(true);
}
