#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include "attribut.h"
#include <QtWidgets>

class FenPrincipale : public QWidget
{
    Q_OBJECT

    public:
        FenPrincipale();
        void recupererAttribut(Attribut att);
        void updateAttribut(int row, Attribut att);

    public slots:
        void genererCode();
        void actualiserHeader(QString);
        void modifSuppAttribut(int row, int col);
        void ouvrirFenAjout();
        void ouvrirFenAjout(Attribut att, int row);

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
