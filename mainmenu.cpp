#include <QtWidgets>
#include "mainmenu.h"
//#include "mainwindow.h"

mainmenu::mainmenu(QWidget *parent) :
    QWidget(parent)
{
    userButton = new QPushButton(tr("&Panel użytkownika"));
    userButton->show();

    adminButton = new QPushButton(tr("&Panel administracyjny"));
    adminButton->show();

    connect(userButton, SIGNAL(clicked()), this, SLOT(user()));
    connect(adminButton, SIGNAL(clicked()), this, SLOT(admin_panel()));

    QHBoxLayout *but = new QHBoxLayout;
    but->addWidget(userButton);
    but->addWidget(adminButton);

    setLayout(but);
    setWindowTitle(tr("Dojade!"));
}
void mainmenu::user()
{
    MainWindow *m = new MainWindow;
    m->show();
    this->close();
}
void mainmenu::admin_panel()
{
    admin *m = new admin;
    m->show();
    this->close();
}
