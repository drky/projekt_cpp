#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;
class QGridLayout;
class QFrame;
class QRadioButton;
QT_END_NAMESPACE

class addDialog : public QDialog
{
    Q_OBJECT
public:
    addDialog(QWidget *parent =0);

public slots:
    void  add();
    void cancel();


private:
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QLineEdit *toLine;
    QLineEdit *fromLine;
    QLineEdit *atimeLine;
    QLineEdit *btimeLine;
    QLineEdit *costLine;
    QLineEdit *opLine;
    QGridLayout *mainLayout;
    QRadioButton *samochod;
    QRadioButton *pociag;
    QRadioButton *samolot;
    QRadioButton *autobus;



};

#endif // ADDDIALOG_H
