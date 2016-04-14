#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QtWidgets>

class FenPrincipale : public QWidget
{
    Q_OBJECT

    public:
    FenPrincipale();

    private:
    QLineEdit *m_NomClass;
    QLineEdit *m_ClassMere;

    QCheckBox *m_Protect;
    QCheckBox *m_GenererConstruct;
    QCheckBox *m_GenererDestruct;

    QCheckBox *m_AjoutComm;
    QLineEdit *m_Auteur;
    QDateEdit *m_DateCreation;
    QTextEdit *m_RoleClass;

    QPushButton *m_Generer;
    QPushButton *m_Quitter;

};

#endif // FENPRINCIPALE_H
