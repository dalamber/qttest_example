#ifndef TESTER_ASYNC_REPLY_H
#define TESTER_ASYNC_REPLY_H

#include <QObject>
#include <QTimer>

namespace tester_lib
{
    class BaseReply : public QObject
    {
        Q_OBJECT
    public:
        BaseReply()
        {
            QTimer::singleShot(0, this, &BaseReply::run);
        };

        virtual ~BaseReply()
        { };

        void finish()
        {
            emit ready();
        }

        bool isValid() const
        {
            return _isValid;
        }

    signals:
        void ready();
        void run();

    protected:
        bool _isValid = false;
    };

    template<typename T>
    class Reply : public BaseReply
    {
    public:
        Reply()
        { }

        T data()
        {
            return _data;
        }

        void setData(T t)
        {
            _data = t;
            _isValid = true;
        }

    private:
        T _data;
    };
}

#endif // TESTER_ASYNC_REPLY_H