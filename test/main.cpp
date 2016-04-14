#include <QApplication>
#include <QPushButton>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;

    QGridLayout *layout = new QGridLayout;

    QPushButton *bouton1 = new QPushButton("Bonjour");
    QPushButton *bouton2 = new QPushButton("les");
    QPushButton *bouton3 = new QPushButton("Zéros");

    layout->addWidget(bouton1,0,0);
    layout->addWidget(bouton2,0,1);
    layout->addWidget(bouton3,1,0,1,2);

    fenetre.setLayout(layout);

    fenetre.show();

    return app.exec();
}
