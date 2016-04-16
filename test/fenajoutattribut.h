#ifndef FENAJOUTATTRIBUT_H
#define FENAJOUTATTRIBUT_H

#include <QtWidgets>

class FenAjoutAttribut : public QDialog
{
    public:
        FenAjoutAttribut(QWidget *parent);

    private:
        QLineEdit *m_Nom;

        QLineEdit *m_Type;

        QCheckBox *m_BAsc;
        QLineEdit *m_Asc;

        QCheckBox *m_BSetter;
        QLineEdit *m_Setter;
};

#endif // FENAJOUTATTRIBUT_H
