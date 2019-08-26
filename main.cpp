#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "declarativescene_p.h"
#include "chiphelper.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<DeclarativeScene>("Scene", 1, 0, "SceneView");

    ChipHelper chiphelper;

    engine.rootContext()->setContextProperty("chipHelper",&chiphelper);

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);
    return app.exec();
}
