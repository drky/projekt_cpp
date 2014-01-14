#include "polaczenie.h"

polaczenie::polaczenie()
{

}
polaczenie::polaczenie(int start, int stop, int cost, int a_time, int b_time, QString op, int type)
{
    this->start=start;
    this->stop=stop;
    this->cost=cost;
    this->a_time=a_time;
    this->b_time=b_time;
    this->type=type;
    this->op=op;
}


void polaczenie::set_a_time(int input){this->a_time = input;}
void polaczenie::set_b_time(int input){this->b_time = input;}
void polaczenie::set_cost(int input){this->cost = input;}
void polaczenie::set_start(int input){this->start = input;}
void polaczenie::set_stop(int input){this->stop = input;}
void polaczenie::set_type(int input){this->type = input;}
void polaczenie::set_op(QString input){this->op = input;}

QDataStream &operator>>(QDataStream &in, polaczenie &item)
{
    QString op;
    quint32 start, stop, cost, a_time, b_time, type;
    in >> start >> stop >> cost >> a_time >> b_time >> op >> type;
    item = polaczenie(start, stop, cost, a_time, b_time, op, type);
    return in;
}
QDataStream &operator<<(QDataStream &out, const polaczenie &item)
{
    out << quint32(item.get_start()) << quint32(item.get_stop()) << quint32(item.get_cost())
        << quint32(item.get_a_time()) << quint32(item.get_b_time())
        << item.get_op()<< item.get_type();
    return out;
}
