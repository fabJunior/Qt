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

    private:
    QLineEdit *m_NomClass;
    QLineEdit *m_ClassMere;

    QCheckBox *m_Protect;
    QCheckBox *m_GenererConstruct;
    QCheckBox *m_GenererDestruct;

    QGroupBox *m_groupCom;

    QLineEdit *m_Auteur;
    QDateEdit *m_DateCreation;
    QTextEdit *m_RoleClass;

    QPushButton *m_Generer;
    QPushButton *m_Quitter;

};

#endif // FENPRINCIPALE_H
