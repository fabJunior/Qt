#ifndef FENAJOUTATTRIBUT_H
#define FENAJOUTATTRIBUT_H

#include <QtWidgets>

class FenAjoutAttribut : public QDialog
{
    Q_OBJECT

    public:
        FenAjoutAttribut(QWidget *parent);

    public slots:
        void envoyerAttribut();

    private:
        QLineEdit *m_Nom;

        QLineEdit *m_Type;

        QCheckBox *m_BAsc;
        QLineEdit *m_Asc;

        QCheckBox *m_BSetter;
        QLineEdit *m_Setter;
};

#endif // FENAJOUTATTRIBUT_H