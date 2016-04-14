#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;
        QPushButton *bouton = new QPushButton("Ouvrir la fenêtre", &fenetre);


    QDialog secondeFenetre (&fenetre);
        QVBoxLayout *layout = new QVBoxLayout;
        QLabel *image = new QLabel(&secondeFenetre);
        image->setPixmap(QPixmap("..\\test\\icone.png"));
        layout->addWidget(image);
        secondeFenetre.setLayout(layout);


    QWidget::connect(bouton, SIGNAL(clicked()), &secondeFenetre, SLOT(exec()));
    fenetre.show();

    return app.exec();
}
