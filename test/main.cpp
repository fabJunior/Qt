#include <QApplication>
#include <QtWidgets>
#include "fenprincipale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);

    QTranslator translator;
    translator.load("..\\test\\test_" + locale);

    app.installTranslator(&translator);

    FenPrincipale Mafenetre;
    Mafenetre.show();

    return app.exec();
}
