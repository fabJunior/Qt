#include "fenprincipale.h"
#include "fencodegenere.h"

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

    m_Auteur = new QLineEdit;
    m_DateCreation = new QDateEdit;
    m_DateCreation->setDate(QDate::currentDate());
    m_RoleClass = new QTextEdit;

    QFormLayout *comLayout = new QFormLayout;
    comLayout->addRow("&Auteur :", m_Auteur);
    comLayout->addRow("Da&te de création :", m_DateCreation);
    comLayout->addRow("&Rôle de la classe :", m_RoleClass);

    m_groupCom = new QGroupBox("Ajouter des commentaires");
    m_groupCom->setCheckable(true);
    m_groupCom->setChecked(false);
    m_groupCom->setLayout(comLayout);

    m_Generer = new QPushButton("Générer !");
    m_Quitter = new QPushButton("Quitter");

    QHBoxLayout *boutons = new QHBoxLayout;
    boutons->setAlignment(Qt::AlignRight);
    boutons->addWidget(m_Generer);
    boutons->addWidget(m_Quitter);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(groupDef);
    layoutPrincipal->addWidget(groupOpt);
    layoutPrincipal->addWidget(m_groupCom);
    layoutPrincipal->addLayout(boutons);

    setLayout(layoutPrincipal);

    setWindowTitle("Zero Class Generator");
    setWindowIcon(QIcon("..\\test\\icone.png"));
    resize(390,480);

    connect(m_Quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(m_Generer, SIGNAL(clicked(bool)), this, SLOT(genererCode()));
}

void FenPrincipale::genererCode(){
    if(m_NomClass->text().isEmpty()){
        qWarning("Aucun nom donné à la classe");
        QMessageBox::critical(this, "Erreur", "Veuillez entrer au moins un nom de classe");
        return;
    }

    QString code = "";

    if(m_groupCom->isChecked()){
        code += "/*\nAuteur : " + m_Auteur->text() +
                "\nDate de création : " +  m_DateCreation->date().toString() +
                "\n\nRôle :\n" + m_RoleClass->toPlainText() + "\n*/\n\n\n";
    }

    if(m_Protect->isChecked()){
        code += "#ifndef HEADER_" + m_NomClass->text().toUpper();
        code += "\n#define HEADER_" + m_NomClass->text().toUpper();
        code += "\n\n\n";
    }

    code += "class " + m_NomClass->text();
    if(!m_ClassMere->text().isEmpty()){
        code += " : public " + m_ClassMere->text();
    }

    code += "\n{\n";
    code += "    public:\n    ";

    if(m_GenererConstruct->isChecked()){
        code += "    " + m_NomClass->text() + "();\n    ";
    }

    if(m_GenererDestruct->isChecked()){
        code += "    virtual ~" + m_NomClass->text() + "();\n    ";
    }

    code += "\n    \n    protected :\n    \n    \n    private:\n    \n};";

    if(m_Protect->isChecked()){
        code += "\n\n#endif";
    }

    FenCodeGenere *monCode = new FenCodeGenere(code,this);
    monCode->exec();
}
