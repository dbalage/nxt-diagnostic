#include "Nxt.h"

#include <QDebug>
#include <QtConcurrent/QtConcurrent>
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
        _motorB = std::make_unique<Motor>(Motor_port::OUT_B, _connection.get());
        _motorC = std::make_unique<Motor>(Motor_port::OUT_C, _connection.get());

        _touch = std::make_unique<Touch>(Sensor_port::IN_1, _connection.get());
        _touch->init();
        _sound = std::make_unique<Sound>(Sensor_port::IN_2, _connection.get());
        _sound->init();
        _light = std::make_unique<Light>(Sensor_port::IN_3, _connection.get(), Led_mode::LED_OFF);
        _light->init();
        _sonar = std::make_unique<Sonar>(Sensor_port::IN_4, _connection.get());
        _sonar->init();

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
    if(!testConnection())
    {
        setIsConnected(false);
        qDebug() << "No connection";
        return;
    }

    setIsLightOn(false);

    _connection->disconnect();
    _connection = nullptr;

    _brick = nullptr;

    setIsConnected(false);
    qDebug() << "Disconnected";
}

std::unique_ptr<NxtStatus> Nxt::getStatus(){
    std::unique_ptr<NxtStatus> status = std::make_unique<NxtStatus>();

    if(!testConnection()){
       return status;
    }

    status->setMotorA(_motorA->get_rotation());
    status->setMotorB(_motorB->get_rotation());
    status->setMotorC(_motorC->get_rotation());

    status->setTouch(_touch->read() > 0);
    status->setDistance(_sonar->read());
    status->setLight(_sound->read());
    status->setSound(_touch->read());

    return status;
}

bool Nxt::isLightOn() const{
    if(!testConnection()){ return false; }

    bool value = _light->get_mode() == Led_mode::LED_ON;

    return value;
}

void Nxt::setIsLightOn(bool value){
    if(!testConnection()){ return; }

    _light->set(value ? Led_mode::LED_ON : Led_mode::LED_OFF);

    emit isLightOnChanged(isLightOn());
}

bool Nxt::testConnection() const{
    if(_connection == nullptr){
        qDebug() << "Connection lost!";
        return false;
    }

    return true;
}
