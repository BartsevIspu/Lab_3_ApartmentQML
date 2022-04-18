#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <apartmentlist.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    ApartmentList viewModel;                        // модель

    QQmlApplicationEngine engine;                   // движок для QML

    QQmlContext *context = engine.rootContext();    // получить корневой контекст модели
    context->setContextObject(&viewModel);          // установить в качестве корневой модели созданную модель для приложения
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
