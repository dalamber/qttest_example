#include "test_main.h"

#include "lib/src/random.h"
#include "lib/src/downloader.h"

#include <QEventLoop>

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

void tests::Main::testDownloader()
{
    QEventLoop loop;

    auto doJob = [&]
    {
        auto reply = tester_lib::download(QUrl("https://as2.ftcdn.net/jpg/00/47/23/69/500_F_47236973_G2aFtkW7m0ZBH1ClnCbiNqiF16G3qcEx.jpg"));
        QObject::connect(reply, &tester_lib::Reply<QByteArray>::ready, [reply, &loop]
        {
            auto isValid = reply->isValid();
            reply->deleteLater();
            loop.quit();

            QVERIFY(reply->isValid());
        });
        loop.exec();
    };

    doJob();
}

void tests::Main::cleanupTestCase() {}

