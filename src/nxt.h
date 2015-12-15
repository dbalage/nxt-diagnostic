#ifndef NXT_H
#define NXT_H

#include <memory>
#include <QObject>
#include "nxt_lib/nxt.h"
#include "NxtStatus.h"


class Nxt : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isConnected READ isConnected NOTIFY isConnectedChanged)

public:
    Nxt();
    virtual ~Nxt();

    bool isConnected() const { return _isConnected; }
    std::unique_ptr<NxtStatus> getStatus();

public slots:
    void Connect(const int port);
    void Disconnect();

signals:
    void isConnectedChanged(bool value);

private:
    std::unique_ptr<Connection> _connection;
    std::unique_ptr<Brick> _brick;
    std::unique_ptr<Motor> _motorA;
    std::unique_ptr<Touch> _touch;

    bool _isConnected = false;

    void setIsConnected(bool value)  {
        if (value != _isConnected) {
            _isConnected = value;
            emit isConnectedChanged(_isConnected);
        }
    }
};

#endif // NXT_H
