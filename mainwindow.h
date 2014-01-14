#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;
class QGridLayout;
class QFrame;
QT_END_NAMESPACE

//! [class definition]
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void szukaj();
    void cancel();

private:
    QPushButton *szukajButton;
    QPushButton *cancelButton;
    QLineEdit *toLine;
    QLineEdit *fromLine;
    QLabel *czas;
    QLabel *koszt;
    QFrame *trasa;
    QLabel *przewoznicy;
    QGridLayout *mainLayout;
};
//! [class definition]

#endif
