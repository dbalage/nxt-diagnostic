#ifndef NXTSTATUS_H
#define NXTSTATUS_H

#include <QObject>
#include <QDataStream>

class NxtStatus : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int motorA READ motorA NOTIFY motorAChanged)
    Q_PROPERTY(bool touch READ touch NOTIFY touchChanged)

public:
    NxtStatus();

    void WriteTo(QDataStream& stream) const;
    void ReadFrom(QDataStream& stream);
    void CopyFrom(const NxtStatus &other);

    int motorA() const { return _motorA; }
    bool touch() const { return _touch; }

    void setMotorA(int value) {
        _motorA = value;
        emit motorAChanged(value);
    }

    void setTouch(bool value) {
        _touch = value;
        emit touchChanged(value);
    }

signals:
    void motorAChanged(int value);
    void touchChanged(bool value);

private:
    int _motorA;
    bool _touch;
};


QDataStream &operator<<(QDataStream& stream, const NxtStatus& status);
QDataStream &operator>>(QDataStream& stream, NxtStatus& status);

#endif
