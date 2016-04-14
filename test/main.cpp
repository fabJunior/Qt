#include <QApplication>
#include <QLineEdit>
#include <QFormLayout>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;

    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;

    QFormLayout *layout = new QFormLayout;
    layout->addRow("Votre nom", nom);
    layout->addRow("Votre prénom", prenom);
    layout->addRow("Votre âge", age);

    fenetre.setLayout(layout);

    fenetre.show();

    return app.exec();
}
