#include <QtWidgets>
#include "mainwindow.h"

//! [constructor and input fields]
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QLabel *fromLabel = new QLabel(tr("Z:"));
    fromLine = new QLineEdit;

    QLabel *toLabel = new QLabel(tr("Do:"));
    toLine = new QLineEdit;

    szukajButton = new QPushButton(tr("&szukaj"));
    szukajButton->show();

    cancelButton = new QPushButton(tr("&cancel"));
    cancelButton->show();

    czas = new QLabel();
    QLabel *czasLabel = new QLabel(tr("Czas podrozy:"));

    koszt = new QLabel();
    QLabel *kosztLabel = new QLabel(tr("Koszt podrozy:"));

    trasa = new QFrame();
    QLabel *trasaLabel = new QLabel(tr("Trasa:"));

    przewoznicy = new QLabel();
    QLabel *pLabel = new QLabel(tr("Przewoznicy:"));

    connect(szukajButton, SIGNAL(clicked()), this, SLOT(szukaj()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

//! [constructor and input fields]

//! [layout]
    QGridLayout *mainLayout = new QGridLayout;
    QHBoxLayout *gora = new QHBoxLayout;
    gora->addWidget(fromLabel);
    gora->addWidget(fromLine);
    gora->addWidget(toLabel);
    gora->addWidget(toLine);
    QVBoxLayout *but = new QVBoxLayout;
    but->addWidget(szukajButton);
    but->addWidget(cancelButton);
    QGridLayout *info = new QGridLayout;
    info->addWidget(czasLabel, 0,0);
    info->addWidget(czas, 0,1);
    info->addWidget(kosztLabel, 1,0);
    info->addWidget(koszt, 1,1);
    info->addWidget(trasaLabel, 2,0);
    info->addWidget(trasa, 2,1);
    info->addWidget(pLabel, 3,0);
    info->addWidget(przewoznicy, 3,1);

    mainLayout->addLayout(gora, 0, 0);
    mainLayout->addLayout(but, 1,1);
    mainLayout->addLayout(info, 1, 0);

//! [layout]

//![setting the layout]
    setLayout(mainLayout);
    setWindowTitle(tr("Dojade!"));
}
//! [setting the layout]
void MainWindow::szukaj()
{
    QString to = toLine->text();
    QString from = fromLine->text();
    QString wyswietl = "z " + from + " do " + to;
    //wyswietlacz->setText(wyswietl);
}
void MainWindow::cancel()
{

}
