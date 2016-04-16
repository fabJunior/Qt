#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QtWidgets>

class FenPrincipale : public QWidget
{
    Q_OBJECT

    public:
        FenPrincipale();

    public slots:
        void genererCode();
        void actualiserHeader(QString);

    private:
        QLineEdit *nomClass;
        QLineEdit *classMere;

        QCheckBox *protect;
        QLineEdit *header;
        QCheckBox *genererConstruct;
        QCheckBox *genererDestruct;

        QGroupBox *groupCom;

        QLineEdit *auteur;
        QDateEdit *dateCreation;
        QTextEdit *roleClass;

        QTableWidget *attributs;

        QPushButton *generer;
        QPushButton *quitter;

};

#endif // FENPRINCIPALE_H
