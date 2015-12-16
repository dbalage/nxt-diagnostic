#include "NxtStatus.h"
#include <utility>

NxtStatus::NxtStatus()
{

}

void NxtStatus::WriteTo(QDataStream& stream) const
{
    //stream << _isConnected;
}

void NxtStatus::ReadFrom(QDataStream& stream)
{
    //stream >> _isConnected;
}

void NxtStatus::CopyFrom(const NxtStatus &other)
{
    _motorA = other.motorA();
    _motorB = other.motorB();
    _motorC = other.motorC();

    _touch = other.touch();
    _distance = other.distance();
    _sound = other.sound();
    _light = other.light();
}

QDataStream &operator<<(QDataStream& stream, const NxtStatus& status)
{
    status.WriteTo(stream);
    return stream;
}

QDataStream &operator>>(QDataStream& stream, NxtStatus& status)
{
    status.ReadFrom(stream);
    return stream;
}


