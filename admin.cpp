#include <QtWidgets>
#include <QAbstractTableModel>
#include <QTableView>
#include "admin.h"
#include "mainmenu.h"
#include "polaczenie.h"

admin::admin(QWidget *parent) :
    QWidget(parent)
{
    QLabel *fromLabel = new QLabel(tr("Z:"));
    fromLine = new QLineEdit;

    QLabel *toLabel = new QLabel(tr("Do:"));
    toLine = new QLineEdit;

    szukajButton = new QPushButton(tr("&szukaj"));
    szukajButton->show();

    addButton = new QPushButton(tr("&dodaj nowy"));
    addButton->show();

    editButton = new QPushButton(tr("&edytuj"));
    editButton->hide();

    deleteButton = new QPushButton(tr("&usun"));
    deleteButton->hide();

    exitButton = new QPushButton(tr("&wyjscie"));
    exitButton->show();

    backButton = new QPushButton(tr("&powrót fo menu głównego"));
    backButton->show();
    QListWidget *spis = new QListWidget;


    QFile city("pol.txt");
    if(!city.open(QIODevice::ReadOnly))
    {
          QMessageBox::critical(this, tr("Error"), tr("Problem z otwarciem pliku polaczen"));
    }
    QDataStream in(&city);
    in.setVersion(QDataStream::Qt_4_1);
    QVector<polaczenie> POL;
    in >> POL;
    QString string;
     in >> string;
     int ilosc = POL.count();
    polaczenie *data = POL.data();
    QStringList List;
    QMessageBox::critical(this, tr("Error"), QString::number(ilosc));
  for(int i=0; i<ilosc; i++)
    {
      QString input;
       input = "z: " + QString::number(data[i].get_start()) + " do: " + QString::number(data[i].get_stop()) + " " +QString::number(data[i].get_a_time())
               + " " + QString::number(data[i].get_a_time())+ " cena: " + QString::number(data[i].get_cost()) + " przewożnik: " + data[i].get_op();
       List.append(input);
  }

   spis->addItems(List);


    QGridLayout *mainLayout = new QGridLayout;
    QHBoxLayout *toLayout = new QHBoxLayout;
    toLayout->addWidget(toLabel);
    toLayout->addWidget(toLine);
    toLayout->addWidget(fromLabel);
    toLayout->addWidget(fromLine);
    mainLayout->addLayout(toLayout, 0, 0);
    mainLayout->addWidget(spis, 1, 0);
    mainLayout->addWidget(szukajButton, 0, 2);
    mainLayout->addWidget(addButton, 1, 2);
    mainLayout->addWidget(editButton, 2, 2);
    mainLayout->addWidget(deleteButton, 3, 2);
    mainLayout->addWidget(backButton, 4, 2);
    mainLayout->addWidget(exitButton, 5, 2);
    setLayout(mainLayout);

    connect(addButton, SIGNAL(clicked()), this, SLOT(szukaj()));
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));

}
void admin::szukaj()
{
    adddialog = new addDialog;
    adddialog->show();

}
void admin::back()
{
    mainmenu *m = new mainmenu;
    m->show();
    this->close();
}
