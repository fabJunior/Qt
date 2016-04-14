#include <QApplication>
#include <QtWidgets>
#include "fenprincipale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenPrincipale Mafenetre;

    Mafenetre.show();

    return app.exec();
}
