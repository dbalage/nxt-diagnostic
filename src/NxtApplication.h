#ifndef NXTAPPLICATION_H
#define NXTAPPLICATION_H

#include <QApplication>
#include <QQmlApplicationEngine>
#include "Nxt.h"

class NxtApplication : public QApplication
{
public:
    /** Konstruktor. Alapvető példányosítások és signal bekötések. */
    NxtApplication(int argc, char *argv[]);
    ~NxtApplication() = default;

private:
    QQmlApplicationEngine engine;
    Nxt nxt;
};

#endif // NXTAPPLICATION_H
