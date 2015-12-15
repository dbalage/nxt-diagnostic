#ifndef NXTMONITOR_H
#define NXTMONITOR_H

#include <QObject>
#include <QTimer>
#include "Nxt.h"
#include "NxtStatusHistory.h"

class NxtMonitor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(NxtStatusHistory* history READ history NOTIFY historyChanged)

public:
    NxtMonitor(Nxt& nxt);
    ~NxtMonitor() = default;

    NxtStatusHistory* history() { return &_history; }

signals:
    void historyChanged();

public slots:
    void tick();

private:
    Nxt& _nxt;

    /** A korábbi és aktuális állapotot tároló RobotStateHistory példány. */
    NxtStatusHistory _history;

    /** Időzítő a tick() metódus periodikus hívására. */
    QTimer _timer;

};

#endif // NXTMONITOR_H
