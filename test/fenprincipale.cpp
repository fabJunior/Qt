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

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(groupDef);

    setLayout(layoutPrincipal);
}
