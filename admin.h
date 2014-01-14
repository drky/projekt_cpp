#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "adddialog.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;
class QGridLayout;
class QFrame;
class QListWidget;
QT_END_NAMESPACE

class admin : public QWidget
{
    Q_OBJECT
public:
    explicit admin(QWidget *parent = 0);
    addDialog *adddialog;

signals:

public slots:
void  szukaj();
void  back();

private:

    QListWidget *spis;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *szukajButton;
    QPushButton *deleteButton;
    QPushButton *exitButton;
    QPushButton *backButton;
    QLineEdit *toLine;
    QLineEdit *fromLine;
    QGridLayout *mainLayout;


};

#endif // ADMIN_H
