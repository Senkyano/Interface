#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDirIterator>
#include <QDebug>

using namespace Qt::Literals::StringLiterals;

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;

	engine.addImportPath("/usr/lib/x86_64-linux-gnu/qt6/qml");
	engine.addImportPath("/usr/lib/qt6/qml");

	const QUrl url(QStringLiteral("qrc:/drone_proto/ui/main.qml"));
		
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
		&app, [url](QObject *obj, const QUrl &objUrl) {
			if (!obj && url == objUrl)
				QCoreApplication::exit(-1);
		}, Qt::QueuedConnection);

	engine.load(url);

	return app.exec();
}