#ifndef FENAJOUTATTRIBUT_H
#define FENAJOUTATTRIBUT_H

#include "fenprincipale.h"
#include <QtWidgets>

class FenAjoutAttribut : public QDialog
{
    Q_OBJECT

    public:
        FenAjoutAttribut(FenPrincipale *parent, Attribut att, int row);

    public slots:
        void envoyerAttribut();

    private:
        void reset();

        FenPrincipale *m_Parent;

        QLineEdit *m_Nom;

        QLineEdit *m_Type;

        QCheckBox *m_BAsc;
        QLineEdit *m_Asc;

        QCheckBox *m_BSetter;
        QLineEdit *m_Setter;
};

#endif // FENAJOUTATTRIBUT_H
