#include <QCoreApplication>
#include <QSettings>
#include <QString>
#include <QDir>
#include <QFile>
#include <QDebug>

#include "httplistener.h"
#include "httprequesthandler.h"
#include "requestermapper.h"
#include "global.h"

using namespace stefanfrings;

/**
 * Выполните поиск в файле конфигурации.
 * Прерывает работу приложения, если оно не найдено.
 * @возвращает допустимое имя файла
 */
QString searchConfigFile()
{
    QString binDir = QCoreApplication::applicationDirPath();
    QString appName = QCoreApplication::applicationName();
    QString fileName("webapp1.ini");

    QStringList searchList;
    searchList.append(binDir);
    searchList.append(binDir + "/etc");
    searchList.append(binDir + "/../etc");
    searchList.append(binDir + "/../" + appName + "/etc");     // for development with shadow build (Linux)
    searchList.append(binDir + "/../../" + appName + "/etc");  // for development with shadow build (Windows)
    searchList.append(QDir::rootPath() + "etc/opt");
    searchList.append(QDir::rootPath() + "etc");

    foreach (QString dir, searchList)
    {
        QFile file(dir + "/" + fileName);
        if (file.exists())
        {
            fileName = QDir(file.fileName()).canonicalPath();
            qDebug("Using config file %s", qPrintable(fileName));
            return fileName;
        }
    }

    // not found
    foreach (QString dir, searchList)
    {
        qWarning("%s/%s not found", qPrintable(dir), qPrintable(fileName));
    }
    qFatal("Cannot find config file %s", qPrintable(fileName));
    return nullptr;
}

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    QString configFileName = searchConfigFile();

    // Настройка введения журнала
    QSettings* logSettings = new QSettings(configFileName, QSettings::IniFormat, &app);
    logSettings->beginGroup("logging");
    logger = new FileLogger(logSettings, 10000, &app);
    logger->installMsgHandler();

    // Регистрируем версию библиотеки
    qDebug("QtWebApp has version %s", getQtWebAppLibVersion());

    //Хранилище сеансов
    QSettings* sessionSettings = new QSettings(configFileName, QSettings::IniFormat, &app);
    sessionSettings->beginGroup("sessions");
    sessionStore = new HttpSessionStore(sessionSettings, &app);

    //Статический файловый контроллер
    QSettings* fileSettings = new QSettings(configFileName, QSettings::IniFormat, &app);
    fileSettings->beginGroup("files");
    staticFileController = new StaticFileController(fileSettings, &app);

    //Настройка кэша шаблонов
    QSettings* templateSettings = new QSettings(configFileName, QSettings::IniFormat, &app);
    templateSettings->beginGroup("templates");
    templateCache = new TemplateCache(templateSettings, &app);

    //Запускаем HTTP сервер
    QSettings* listenerSettings = new QSettings(configFileName, QSettings::IniFormat, &app);
    listenerSettings->beginGroup("listener");
    new HttpListener(listenerSettings, new RequesterMapper(&app), &app);

    return app.exec();
}
