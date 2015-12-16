#include "NxtStatusHistory.h"

NxtStatusHistory::NxtStatusHistory()
    : QObject(nullptr)
{

}

void NxtStatusHistory::Add(const NxtStatus& status)
{
    std::shared_ptr<NxtStatus> newStatus = std::make_shared<NxtStatus>();
    newStatus->CopyFrom(status);
    _statusList.insert(0, newStatus.get());
    _currentStatus = newStatus;
    _container.push_back(newStatus);

    // Összeállítjuk a grafikon számára az adatszerkezetet.
    // Ezek a listák QList<int> típusú listák, amiket direkt arra hozunk létre, hogy a QML elemek
    //  ezekből olvassák ki az adatokat, mivel erre a fenti container nem alkalmas. (Az std::vector
    //  nem támogatja a Qt metaobject rendszerét.)

    /*
    graphTimestamps.clear();
    graphVelocities.clear();
    graphAcceleration.clear();
    int graphStateNumber = stateList.size() < shownStateNumber ? stateList.size() : shownStateNumber;
    auto it = container.end()-graphStateNumber;
    for(;it!=container.end();++it)
    {
        RobotState *currentState = it->get();
        graphTimestamps.append(currentState->timestamp());
        graphVelocities.append(currentState->v());
        graphAcceleration.append(currentState->a());
    }
    */

    // Jelezzük a history változását.
    emit currentStatusChanged();
    emit statusListChanged();
}

