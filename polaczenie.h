#ifndef POLACZENIE_H
#define POLACZENIE_H

#include <QWidget>
class QString;

class polaczenie
{

public:
    // Konstruktory
    polaczenie();
    polaczenie(int start, int stop, int cost, int a_time, int b_time, QString op, int type);
    // Gettery
    int get_start() const {return start;}
    int get_stop() const {return stop;}
    int get_cost() const {return cost;}
    int get_a_time() const {return a_time;}
    int get_b_time() const {return b_time;}
    QString get_op() const {return op;}
    QString get_type() const {

        QString output;
        switch(type)
        {
        case 0:
            output = "samochod";
            break;
        case 1:
            output = "pociag";
            break;
        case 2:
            output = "samolot";
            break;
        case 3:
            output = "autobus";
            break;
       }
        return output;
    }
    // Settery
    void set_start(int input);
    void set_stop(int input);
    void set_cost(int input);
    void set_a_time(int input);
    void set_b_time(int input);
    void set_op(QString input);
    void set_type(int input);

private:
    int start;
    int stop;
    int cost;
    int a_time;
    int b_time;
    QString op;
    int type;

};
QDataStream &operator>>(QDataStream &in, polaczenie &item);
QDataStream &operator<<(QDataStream &out, const polaczenie &item);

#endif // POLACZENIE_H
