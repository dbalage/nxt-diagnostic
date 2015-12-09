#ifndef NXT_H
#define NXT_H

#include <QObject>
#include <memory>
using namespace std;

class Nxt : public QObject
{
    Q_OBJECT

public:
    Nxt();
    Connect(const int port);
    Disconnect();

    bool isConnected() const { return m_isConnected; }

public slots:

signals:
    void isConnectedChanged(bool value);

private:
    bool m_isConnected;

    shared_ptr<Connection> connection;

    void setIsConnected(bool value);

};

#endif // NXT_H
