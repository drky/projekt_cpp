#include <QtWidgets>
#include "mainwindow.h"
#include "mainmenu.h"
#include <QApplication>
#include "mymodel.h"

int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
    mainmenu w;
    w.show();

    return a.exec();
}
