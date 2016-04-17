#include "fenprincipale.h"
#include "fencodegenere.h"
#include "fenajoutattribut.h"
#include "attribut.h"

FenPrincipale::FenPrincipale()
{
    QTabWidget *tab = new QTabWidget;
    QWidget *pageDefOptCom = new QWidget;
    tab->addTab(pageDefOptCom,"Général");

    //PAGE 1
        //Box DEF
        nomClass = new QLineEdit;
        classMere = new QLineEdit;

        QFormLayout *definitionLayout = new QFormLayout;
        definitionLayout->addRow("&Nom :", nomClass);
        definitionLayout->addRow("Classe &mère :", classMere);

        QGroupBox *groupDef = new QGroupBox("Définition de la classe");
        groupDef->setLayout(definitionLayout);

        //Box OPTIONS
        protect = new QCheckBox("Protéger le &header contre les inclusions multiples");
        protect->setChecked(true);

        QLabel *fleche = new QLabel;
        fleche->setPixmap(QPixmap("..\\test\\arrow.png").scaled(30,30));
        header = new QLineEdit();

        QHBoxLayout *headerLayout = new QHBoxLayout;
        headerLayout->addWidget(fleche);
        headerLayout->addWidget(header);

        connect(protect,SIGNAL(clicked(bool)),header,SLOT(setVisible(bool)));
        connect(protect,SIGNAL(clicked(bool)),fleche,SLOT(setVisible(bool)));

        genererConstruct = new QCheckBox("Générer un &constructeur par défaut");
        genererDestruct = new QCheckBox("Générer un &destructeur");

        QVBoxLayout *optionsLayout = new QVBoxLayout;
        optionsLayout->addWidget(protect);
        optionsLayout->addLayout(headerLayout);
        optionsLayout->addWidget(genererConstruct);
        optionsLayout->addWidget(genererDestruct);

        QGroupBox *groupOpt = new QGroupBox("Options");
        groupOpt->setLayout(optionsLayout);

        //Box Com
        auteur = new QLineEdit;
        dateCreation = new QDateEdit;
        dateCreation->setDate(QDate::currentDate());
        roleClass = new QTextEdit;

        QFormLayout *comLayout = new QFormLayout;
        comLayout->addRow("&Auteur :", auteur);
        comLayout->addRow("Da&te de création :", dateCreation);
        comLayout->addRow("&Rôle de la classe :", roleClass);

        groupCom = new QGroupBox("Ajouter des commentaires");
        groupCom->setCheckable(true);
        groupCom->setChecked(false);
        groupCom->setLayout(comLayout);

        //Boutons
        generer = new QPushButton("Générer !");
        quitter = new QPushButton("Quitter");

        QHBoxLayout *boutons = new QHBoxLayout;
        boutons->setAlignment(Qt::AlignRight);
        boutons->addWidget(generer);
        boutons->addWidget(quitter);

        //Layout principal
        QVBoxLayout *layoutPrincipal = new QVBoxLayout;
        layoutPrincipal->addWidget(groupDef);
        layoutPrincipal->addWidget(groupOpt);
        layoutPrincipal->addWidget(groupCom);

        //setLayout(layoutPrincipal);
        pageDefOptCom->setLayout(layoutPrincipal);


    QWidget *pageAttributs = new QWidget;
    tab->addTab(pageAttributs,"Attributs");

    //PAGE 2

        QStringList headers;
        headers <<"Attribut" << "Modifier" << "Supprimer" << "Adresse";
        attributs = new QTableWidget(0,4);
        attributs->setHorizontalHeaderLabels(headers);
        attributs->setColumnHidden(3,true);

        QPushButton *ajouterAtt = new QPushButton("Ajouter un attribut");
        FenAjoutAttribut *fenAtt = new FenAjoutAttribut(this);
        connect(ajouterAtt,SIGNAL(clicked(bool)),fenAtt,SLOT(exec()));

        QHBoxLayout *boutonsAtt = new QHBoxLayout;
        boutonsAtt->setAlignment(Qt::AlignRight);
        boutonsAtt->addWidget(ajouterAtt);

        QVBoxLayout *attLayout = new QVBoxLayout;
        attLayout->addWidget(attributs);
        attLayout->addLayout(boutonsAtt);
        pageAttributs->setLayout(attLayout);





    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tab);
    mainLayout->addLayout(boutons);

    setLayout(mainLayout);

    //paramètres de la fenêtre
    setWindowTitle("Zero Class Generator");
    setWindowIcon(QIcon("..\\test\\icone.png"));
    resize(390,480);

    connect(nomClass,SIGNAL(textChanged(QString)),this,SLOT(actualiserHeader(QString)));

    connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(generer, SIGNAL(clicked()), this, SLOT(genererCode()));
}

void FenPrincipale::actualiserHeader(QString newNomClass){
    static QString oldNomClass;

    oldNomClass.isEmpty() ? header->setText("HEADER_" + newNomClass) :
                               header->setText(header->text().replace(oldNomClass,newNomClass));

    oldNomClass = newNomClass;
}

void FenPrincipale::recupererAttribut(Attribut *att){
    int pos = attributs->rowCount();

    QPixmap editPixmap("..\\test\\edit.png");
    editPixmap.scaled(40,40);
    QPushButton *editBtn = new QPushButton;
    editBtn->setIcon(QIcon(editPixmap));

    QPixmap deletePixmap("..\\test\\delete.png");
    deletePixmap.scaled(40,40);
    QPushButton *deleteBtn = new QPushButton;
    deleteBtn->setIcon(QIcon(deletePixmap));

    attributs->setRowCount(pos+1);
    attributs->setItem(pos,0,new QTableWidgetItem(att->nomAtt()));
    attributs->itemAt(pos,0)->setTextAlignment(Qt::AlignCenter);
    //attributs->setItem(pos,1,new QTableWidgetItem(editIcon, ""));
    //attributs->setItem(pos,2,new QTableWidgetItem(deleteIcon, ""));
    attributs->setCellWidget(pos,1,(QWidget *)editBtn);
    attributs->setCellWidget(pos,2,deleteBtn);

    uintptr_t attAdress = (uintptr_t)att;
    attributs->setItem(pos,3,new QTableWidgetItem(attAdress));
}

void FenPrincipale::genererCode(){
    if(nomClass->text().isEmpty()){
        qWarning("Aucun nom donné à la classe");
        QMessageBox::critical(this, "Erreur", "Veuillez entrer au moins un nom de classe");
        return;
    }

    QString code = "";

    if(groupCom->isChecked()){
        code += "/*\nAuteur : " + auteur->text() +
                "\nDate de création : " +  dateCreation->date().toString() +
                "\n\nRôle :\n" + roleClass->toPlainText() + "\n*/\n\n\n";
    }

    if(protect->isChecked()){
        code += "#ifndef HEADER_" + nomClass->text().toUpper();
        code += "\n#define HEADER_" + nomClass->text().toUpper();
        code += "\n\n\n";
    }

    code += "class " + nomClass->text();
    if(!classMere->text().isEmpty()){
        code += " : public " + classMere->text();
    }

    code += "\n{\n";
    code += "    public:\n    ";

    if(genererConstruct->isChecked()){
        code += "    " + nomClass->text() + "();\n    ";
    }

    if(genererDestruct->isChecked()){
        code += "    ~" + nomClass->text() + "();\n    ";
    }

    code += "\n    \n    protected :\n    \n    \n    private:\n    \n};";

    if(protect->isChecked()){
        code += "\n\n#endif";
    }

    FenCodeGenere *monCode = new FenCodeGenere(code,this);
    monCode->exec();
}
