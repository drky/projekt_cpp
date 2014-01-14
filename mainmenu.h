#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "mainwindow.h"
#include "admin.h"

QT_BEGIN_NAMESPACE
class QPushButton;
class QGridLayout;
class QListWidget;
QT_END_NAMESPACE

class mainmenu : public QWidget
{
    Q_OBJECT
public:
    explicit mainmenu(QWidget *parent = 0);

public slots:
    void user();
    void admin_panel();

signals:

private:
    QPushButton *userButton;
    QPushButton *adminButton;

};

#endif // MAINMENU_H
