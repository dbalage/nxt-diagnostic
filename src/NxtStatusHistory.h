#ifndef NXTSTATUSHISTORY_H
#define NXTSTATUSHISTORY_H

#include <QObject>
#include <memory>
#include "NxtStatus.h"

class NxtStatusHistory : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> statusList READ statusList NOTIFY statusListChanged)
    Q_PROPERTY(NxtStatus* currentStatus READ currentStatus NOTIFY currentStatusChanged)

public:
    NxtStatusHistory();


//    QList<int> graphTimestamps;
//    QList<int> graphVelocities;
//    QList<int> graphAcceleration;

    QList<QObject*> statusList(){ return _statusList; }
    NxtStatus* currentStatus(){ return _currentStatus.get(); }

    void Add(const NxtStatus& status);

    const int shownStatusNumber = 20;

signals:
    void statusListChanged();
    void currentStatusChanged();

public slots:

private:
    std::shared_ptr<NxtStatus> _currentStatus;
    QList<QObject*> _statusList;
    std::vector<std::shared_ptr<NxtStatus>> _container;
};

#endif // NXTSTATUSHISTORY_H
