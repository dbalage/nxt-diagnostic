#ifndef NXT_H
#define NXT_H

#include <memory>
#include <QObject>
#include "nxt_lib/nxt.h"


class Nxt : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isConnected READ isConnected WRITE setIsConnected MEMBER _isConnected NOTIFY isConnectedChanged)

public:
    Nxt();
    Nxt(const Nxt &other):
        _connection(other._connection),
        _isConnected(other._isConnected)
    {}
    virtual ~Nxt();

    bool isConnected() const { return _isConnected; }
    void setIsConnected(bool value) { _isConnected = value; }

public slots:
    void Connect(const int port);
    void Disconnect();

signals:
    void isConnectedChanged(bool value);

private:
    bool _isConnected;
    std::shared_ptr<Connection> _connection;
};

#endif // NXT_H
