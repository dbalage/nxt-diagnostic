#include "nxt.h"
#include "nxt_lib/nxt.h"

Nxt::Nxt()
{
}

Nxt::Connect(const int port)
{
    try
    {
        connection = new Bluetooth();
        qDebug() << "Try to connect to the NXT" << endl;
        connection->connect(port);
        qDebug() << "Connected" << endl;
    }
    catch (Nxt_exception& e)
    {
        //some error occurred - print it out
        qWarning() << e.what() << endl;
        qWarning() << "error code: " << e.error_code() << endl;
        qWarning() << "error type: " << e.error_type() << endl;
        qWarning() << e.who() << endl;
        connection->disconnect();
    }
}

Nxt::Disconnect()
{
    connection->disconnect();
}
