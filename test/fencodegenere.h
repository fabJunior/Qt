#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QtWidgets>

class FenCodeGenere : public QDialog
{
    public:
        FenCodeGenere(QString &code, QWidget *parent);

    private:

        QTextEdit *m_codeGenere;
        QPushButton *m_fermer;

};

#endif // FENCODEGENERE_H
