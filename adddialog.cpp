#include <QtWidgets>
#include "adddialog.h"
#include "polaczenie.h"

addDialog::addDialog(QWidget *parent)
    : QDialog(parent)
{
    QLabel *fromLabel = new QLabel(tr("Z:"));
    fromLine = new QLineEdit;
    QLabel *toLabel = new QLabel(tr("Do:"));
    toLine = new QLineEdit;
    QLabel *atimeLabel = new QLabel(tr("Poczatek podróży:"));
    atimeLine = new QLineEdit;
    QLabel *btimeLabel = new QLabel(tr("Koniec podróży:"));
    btimeLine = new QLineEdit;
    QLabel *costLabel = new QLabel(tr("Cena:"));
    costLine = new QLineEdit;
    QLabel *opLabel = new QLabel(tr("Przewoźnik:"));
    opLine = new QLineEdit;

    saveButton = new QPushButton(tr("&zapisz"));
    saveButton->show();

    cancelButton = new QPushButton(tr("&anuluj"));
    cancelButton->show();


    QGroupBox *rodzaj = new QGroupBox(tr("Rodzaj przejazdu"));
    samochod = new QRadioButton(tr("Samochód"));
    pociag = new QRadioButton(tr("Pociąg"));
    samolot = new QRadioButton(tr("Samolot"));
    autobus = new QRadioButton(tr("Autobus"));
    samochod->setChecked(true);
    QHBoxLayout *vbox = new QHBoxLayout;
    vbox->addWidget(samochod);
    vbox->addWidget(pociag);
    vbox->addWidget(samolot);
    vbox->addWidget(autobus);
    rodzaj->setLayout(vbox);

    QGridLayout *mainLayout = new QGridLayout;
    QGridLayout *addLayout = new QGridLayout;
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    addLayout->addWidget(fromLabel, 0, 0);
    addLayout->addWidget(fromLine, 0, 1);
    addLayout->addWidget(toLabel, 1, 0);
    addLayout->addWidget(toLine, 1, 1);
    addLayout->addWidget(atimeLabel, 2, 0);
    addLayout->addWidget(atimeLine, 2, 1);
    addLayout->addWidget(btimeLabel, 3, 0);
    addLayout->addWidget(btimeLine, 3, 1);
    addLayout->addWidget(costLabel, 4, 0);
    addLayout->addWidget(costLine, 4, 1);
    addLayout->addWidget(opLabel, 5, 0);
    addLayout->addWidget(opLine, 5, 1);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);
    mainLayout->addWidget(rodzaj, 1, 0);
    mainLayout->addLayout(addLayout, 0, 0);
    mainLayout->addLayout(buttonLayout, 0, 1);
    setLayout(mainLayout);

    connect(saveButton, SIGNAL(clicked()), this, SLOT(add()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
}

void addDialog::add()
{
    polaczenie p;
    QString s_start = fromLine->text();
    QString s_stop = toLine->text();
    QFile city("city.txt");
    if(!city.open(QIODevice::ReadOnly))
    {
          QMessageBox::critical(this, tr("Error"), tr("Problem z otwarciem pliku miast"));
    }
    QDataStream in(&city);
    in.setVersion(QDataStream::Qt_4_1);
    QMap<QString, int> city_map;
    in >> city_map;
    city.close();
    QFile pol("pol.txt");
    if(!pol.open(QIODevice::ReadOnly))
    {
          QMessageBox::critical(this, tr("Error"), tr("Problem z otwarciem pliku miast"));
    }
    in.setDevice(&pol);
    in.setVersion(QDataStream::Qt_4_1);
    QVector<polaczenie> pol_vector;
    in >> pol_vector;
   // QMessageBox::critical(this, tr("Error"), QString::number(city_map.count()));
    pol.close();
    int c =city_map.count();
    int from =0;
    int to=0;
    if(c!=0)
    {
         if(city_map.contains(s_start))
             from = city_map[s_start];
         if(city_map.contains(s_stop))
             to = city_map[s_stop];
         if(from==0)
         {
            city_map.insert(s_start, city_map.count()+1);
            from = city_map.count()+1;
         }
         if(to==0)
         {
            city_map.insert(s_stop, city_map.count()+1);
            to = city_map.count()+1;
         }
    }
    else
    {
        city_map.insert(s_start, c+1);
        city_map.insert(s_stop, c+2);
    }
    if(!city.open(QIODevice::WriteOnly))
    {
          QMessageBox::critical(this, tr("Error"), tr("Problem z otwarciem pliku miast"));
    }

    QDataStream out(&city);
    out.setVersion(QDataStream::Qt_4_1);
    out << city_map;
    out << "sdfgsdfgsd";
    QMessageBox::critical(this, tr("Error"), QString::number(city_map.count()));
    city.close();
    p.set_a_time(atimeLine->text().toInt());
    p.set_b_time(btimeLine->text().toInt());
    p.set_cost(costLine->text().toInt());
    p.set_op(opLine->text());
    p.set_start(from);
    p.set_stop(to);
    if(samochod->isChecked())
        p.set_type(0);
    if(pociag->isChecked())
        p.set_type(1);
    if(samolot->isChecked())
        p.set_type(2);
    if(autobus->isChecked())
        p.set_type(3);
    if(!pol.open(QIODevice::WriteOnly))
    {
          QMessageBox::critical(this, tr("Error"), tr("Problem z otwrciem pliku połączeń"));
    }
    out.setDevice(&pol);
    out.setVersion(QDataStream::Qt_4_1);
    pol_vector.append(p);
    out << pol_vector;
    this->close();
}

void addDialog::cancel()
{
    this->close();
}
