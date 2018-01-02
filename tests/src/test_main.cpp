#include "test_main.h"

#include "lib/src/random.h"

void tests::Main::initTestCase() {}

void tests::Main::testRandomNumber()
{
    auto res1 = tester_lib::randomNumber();
    auto res2 = tester_lib::randomNumber();

    QVERIFY(res1 != res2);

    QBENCHMARK
    {
        tester_lib::randomNumber();
    };
}

void tests::Main::testRandomUuid()
{
    auto res = tester_lib::randomUuid();
    QVERIFY(!res.isEmpty());
    QVERIFY(!QUuid(res).isNull());

    QBENCHMARK
    {
        tester_lib::randomUuid();
    };
}

void tests::Main::cleanupTestCase() {}
