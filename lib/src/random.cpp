#include "random.h"

#include <random>
#include <QDateTime>
#include <QUuid>


QString tester_lib::randomUuid()
{
    return QUuid::createUuid().toString();
}

quint32 tester_lib::randomNumber()
{
    using namespace std;

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<quint32> dist(
            numeric_limits<quint32>::min(),
            numeric_limits<quint32>::max());

    return dist(mt);
}
