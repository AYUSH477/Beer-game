#include "beergamewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BeerGameWindow w;
    w.show();

    return a.exec();
}
