#ifndef NXTSTATUS_H
#define NXTSTATUS_H

#include <QObject>
#include <QDataStream>

class NxtStatus : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int motorA READ motorA NOTIFY motorAChanged)
    Q_PROPERTY(int motorB READ motorB NOTIFY motorBChanged)
    Q_PROPERTY(int motorC READ motorC NOTIFY motorCChanged)

    Q_PROPERTY(bool touch READ touch NOTIFY touchChanged)
    Q_PROPERTY(int distance READ distance NOTIFY distanceChanged)
    Q_PROPERTY(int sound READ sound NOTIFY soundChanged)
    Q_PROPERTY(int light READ light NOTIFY lightChanged)

public:
    NxtStatus();
    //NxtStatus(NxtStatus &other);
    ~NxtStatus() = default;

    void WriteTo(QDataStream& stream) const;
    void ReadFrom(QDataStream& stream);
    void CopyFrom(const NxtStatus &other);

    int motorA() const { return _motorA; }
    int motorB() const { return _motorB; }
    int motorC() const { return _motorC; }

    bool touch() const { return _touch; }
    int distance() const { return _distance; }
    int sound() const { return _sound; }
    int light() const { return _light; }

    void setMotorA(int value) {
        _motorA = value;
        emit motorAChanged(value);
    }

    void setMotorB(int value) {
        _motorB = value;
        emit motorBChanged(value);
    }

    void setMotorC(int value) {
        _motorC = value;
        emit motorCChanged(value);
    }

    void setTouch(bool value) {
        _touch = value;
        emit touchChanged(value);
    }

    void setDistance(bool value) {
        _distance = value;
        emit distanceChanged(value);
    }

    void setSound(bool value) {
        _sound = value;
        emit soundChanged(value);
    }

    void setLight(bool value) {
        _light = value;
        emit lightChanged(value);
    }

signals:
    void motorAChanged(int value);
    void motorBChanged(int value);
    void motorCChanged(int value);

    void touchChanged(bool value);
    void distanceChanged(bool value);
    void soundChanged(bool value);
    void lightChanged(bool value);

private:
    int _motorA;
    int _motorB;
    int _motorC;

    bool _touch;
    int _distance;
    int _sound;
    int _light;
};


QDataStream &operator<<(QDataStream& stream, const NxtStatus& status);
QDataStream &operator>>(QDataStream& stream, NxtStatus& status);

#endif
