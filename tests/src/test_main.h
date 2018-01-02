#ifndef TESTER_TEST_MAIN_H
#define TESTER_TEST_MAIN_H

#include <QObject>
#include <QtTest/QTest>

namespace tests
{
    class Main : public QObject
    {
        Q_OBJECT

    private slots:
        void initTestCase();
        void testRandomNumber();
        void testRandomUuid();
        void cleanupTestCase();
    };

}


#endif //TESTER_TEST_MAIN_H
