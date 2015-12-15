#include "NxtMonitor.h"
#include "Nxt.h"
#include "NxtStatus.h"
#include "NxtStatusHistory.h"
#include <QTimer>

NxtMonitor::NxtMonitor(Nxt& nxt)
    : _nxt(nxt), _history()
{
    connect(&_nxt, &Nxt::isConnectedChanged, [this](bool isConnected){
        if(isConnected)
            _timer.start(500);
        else
            _timer.stop();
    });

    //connect(&_timer, &QTimer::timeout, tick);
    connect(&_timer, SIGNAL(timeout()), this, SLOT(tick()));
}

void NxtMonitor::tick()
{
    auto status = _nxt.getStatus();
    _history.Add(*status.get());
}
