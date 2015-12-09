#include "nxt.h"

#include <QDebug>
#include "nxt_lib/nxt.h"

Nxt::Nxt()
{
}

Nxt::Connect(const int port)
{
    try
    {
        connection =  std::make_shared<Bluetooth>();
        qDebug() << "Try to connect to the NXT";
        connection->connect(port);
        qDebug() << "Connected";
    }
    catch (Nxt_exception& e)
    {
        //some error occurred - print it out
        qWarning() << e.what();
        qWarning() << "error code: " << e.error_code();
        qWarning() << "error type: " << e.error_type();
        qWarning() << QString::fromStdString(e.who());
        connection->disconnect();
    }
}

Nxt::Disconnect()
{
    connection->disconnect();
}
