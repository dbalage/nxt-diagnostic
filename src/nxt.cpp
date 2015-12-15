#include "Nxt.h"

#include <QDebug>
#include "nxt_lib/nxt.h"
#include "NxtStatus.h"

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
        _connection =  std::make_unique<Bluetooth>();
        qDebug() << "Try to connect to the NXT on port" << port;
        _connection->connect(port);

        _brick = std::make_unique<Brick>(_connection.get());
        _motorA = std::make_unique<Motor>(Motor_port::OUT_A, _connection.get());
        _touch = std::make_unique<Touch>(Sensor_port::IN_1, _connection.get());

        setIsConnected(true);
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
    if(_connection == nullptr)
    {
        setIsConnected(false);
        qDebug() << "No connection";
        return;
    }

    _connection->disconnect();
    _connection = nullptr;

    _brick = nullptr;

    setIsConnected(false);
    qDebug() << "Disconnected";
}

std::unique_ptr<NxtStatus> Nxt::getStatus(){
    std::unique_ptr<NxtStatus> status = std::make_unique<NxtStatus>();

    if(_connection == nullptr){
            return status;
    }

    status->setMotorA(_motorA->get_rotation());
    status->setTouch(_touch->read() > 0);

    return status;
}
