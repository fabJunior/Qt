#include "fenprincipale.h"

FenPrincipale::FenPrincipale()
{
    m_NomClass = new QLineEdit;
    m_ClassMere = new QLineEdit;

    QFormLayout *definitionLayout = new QFormLayout;
    definitionLayout->addRow("&Nom :", m_NomClass);
    definitionLayout->addRow("Classe &mère :", m_ClassMere);

    QGroupBox *groupDef = new QGroupBox("Définition de la classe");
    groupDef->setLayout(definitionLayout);

    m_Protect = new QCheckBox("Protéger le &header contre les inclusions multiples");
    m_GenererConstruct = new QCheckBox("Générer un &constructeur par défaut");
    m_GenererDestruct = new QCheckBox("Générer un &destructeur");

    QVBoxLayout *optionsLayout = new QVBoxLayout;
    optionsLayout->addWidget(m_Protect);
    optionsLayout->addWidget(m_GenererConstruct);
    optionsLayout->addWidget(m_GenererDestruct);

    QGroupBox *groupOpt = new QGroupBox("Options");
    groupOpt->setLayout(optionsLayout);

    m_AjoutComm = new QCheckBox("Ajouter des commentaires");
    m_Auteur = new QLineEdit;
    m_DateCreation = new QDateEdit;
    m_RoleClass = new QTextEdit;

    QFormLayout *comLayout = new QFormLayout;
    comLayout->addRow(m_AjoutComm);
    comLayout->addRow("&Auteur :", m_Auteur);
    comLayout->addRow("Da&te de création :", m_DateCreation);
    comLayout->addRow("&Rôle de la classe :", m_RoleClass);

    QGroupBox *groupCom = new QGroupBox;
    groupCom->setLayout(comLayout);

    m_Generer = new QPushButton("Générer !");
    m_Quitter = new QPushButton("Quitter");

    QHBoxLayout *boutons = new QHBoxLayout;
    boutons->setAlignment(Qt::AlignRight);
    boutons->addWidget(m_Generer);
    boutons->addWidget(m_Quitter);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(groupDef);
    layoutPrincipal->addWidget(groupOpt);
    layoutPrincipal->addWidget(groupCom);
    layoutPrincipal->addLayout(boutons);

    setLayout(layoutPrincipal);

    //setFixedSize(370,480);
}
