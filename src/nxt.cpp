#include "Nxt.h"

#include <QDebug>
#include "nxt_lib/nxt.h"

Nxt::Nxt()
{
}

Nxt::~Nxt()
{
    Disconnect();
}

void Nxt::Connect(const int port)
{
    try
    {
        _connection =  std::make_shared<Bluetooth>();
        qDebug() << "Try to connect to the NXT on port" << port;
        _connection->connect(port);
        qDebug() << "Connected";
    }
    catch (Nxt_exception& e)
    {
        //some error occurred - print it out
        qWarning() << e.what();
        qWarning() << "error code: " << e.error_code();
        qWarning() << "error type: " << e.error_type();
        qWarning() << QString::fromStdString(e.who());
        _connection->disconnect();
    }
}

void Nxt::Disconnect()
{
    _connection->disconnect();
    _connection = nullptr;
    qDebug() << "Disconnected";
}
