#ifndef TESTER_DOWNLOADER_H
#define TESTER_DOWNLOADER_H

#include "async_reply.h"

namespace tester_lib
{
    Reply<QByteArray> *download(const QUrl &url);
};


#endif //TESTER_DOWNLOADER_H
