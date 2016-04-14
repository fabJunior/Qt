#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QVBoxLayout>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;

    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;
    QPushButton *valider = new QPushButton("Valider");

    QVBoxLayout *cadre = new QVBoxLayout;
    QFormLayout *formulaire = new QFormLayout;
    formulaire->addRow("Votre &nom", nom);
    formulaire->addRow("Votre &prénom", prenom);
    formulaire->addRow("Votre â&ge", age);

    cadre->addLayout(formulaire);

    QWidget::connect(valider,SIGNAL(clicked()), &app,SLOT(quit()));
    cadre->addWidget(valider);

    fenetre.setLayout(cadre);

    fenetre.show();

    return app.exec();
}
