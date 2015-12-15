#ifndef NXTAPPLICATION_H
#define NXTAPPLICATION_H

#include <QApplication>
#include <QQmlApplicationEngine>
#include "Nxt.h"
#include "NxtMonitor.h"
#include "NxtStatusHistory.h"

class NxtApplication : public QApplication
{
public:
    /** Konstruktor. Alapvető példányosítások és signal bekötések. */
    NxtApplication(int argc, char *argv[]);
    ~NxtApplication() = default;

private:
    QQmlApplicationEngine _engine;
    Nxt _nxt;
    NxtMonitor _nxtMonitor;
    NxtStatusHistory _histrory;
};

#endif // NXTAPPLICATION_H
