#include "NxtApplication.h"
#include <QDebug>
#include <QQmlContext>

NxtApplication::NxtApplication(int argc, char *argv[])
    : QApplication(argc, argv), engine(), nxt()
{
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // A QML gyökérelemre szükségünk van ahhoz, hogy tudjunk hivatkozni a QML-es elemekre.
    auto rootObjects = engine.rootObjects();
    if (rootObjects.size() == 0)
    {
        qDebug() << "HIBA: Nem sikerült létrehozni a QML környezetet.";
        return;
    }
    // A QML környezet is felállt, bekötjük a signalokat a QML és C++ oldal között.
    QObject *rootObject = rootObjects[0];

    engine.rootContext()->setContextProperty("nxt", &nxt);
}

