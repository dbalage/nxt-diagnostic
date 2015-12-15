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
    //_isConnected=other.isConnected();
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


