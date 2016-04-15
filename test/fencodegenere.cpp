#include "fencodegenere.h"

FenCodeGenere::FenCodeGenere(QString &code, QWidget *parent =0) : QDialog(parent)
{
    m_codeGenere = new QTextEdit();
    m_codeGenere->setPlainText(code);
    m_codeGenere->setReadOnly(true);
    m_codeGenere->setFont(QFont("Courier"));
    m_codeGenere->setLineWrapMode(QTextEdit::NoWrap);

    m_fermer = new QPushButton("Fermer");

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(m_codeGenere);
    layoutPrincipal->addWidget(m_fermer);

    resize(350, 450);
    setLayout(layoutPrincipal);

    connect(m_fermer, SIGNAL(clicked()), this, SLOT(accept()));
}
