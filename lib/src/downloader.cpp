#include "downloader.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

tester_lib::Reply<QByteArray> *tester_lib::download(const QUrl &url)
{
    auto reply = new Reply<QByteArray>();

    auto manager = new QNetworkAccessManager();

    QNetworkRequest request;
    request.setUrl(url);

    auto networkReply = manager->get(request);
    QObject::connect(networkReply, &QNetworkReply::finished, [networkReply, reply]
    {
        auto data = networkReply->readAll();
        reply->setData(data);
        reply->finish();

        networkReply->deleteLater();
    });

    return reply;
}
