#include "plotter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Plotter w(argv[1]);
    w.show();
    return a.exec();
}
