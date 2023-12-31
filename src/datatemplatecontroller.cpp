#include "datatemplatecontroller.h"

#include "template.h"
#include "global.h"

DataTemplateController::DataTemplateController(QObject* parent) : HttpRequestHandler(parent)
{
    list.append("Robert");
    list.append("Lisa");
    list.append("Hannah");
    list.append("Ludwig");
    list.append("Miranda");
    list.append("Fracesco");
    list.append("Kim");
    list.append("Jacko");
}

void DataTemplateController::service(HttpRequest& request, HttpResponse& response)
{
    HttpSession session = sessionStore->getSession(request, response, true);
    QString username = session.get("username").toString();

    QByteArray language = request.getHeader("Accept-Language");
    qDebug("language=%s", qPrintable(language));

    response.setHeader("Content-Type", "text/html; charset=UTF-8");

    Template t = templateCache->getTemplate("files/hello", language);
    t.enableWarnings(true);  //если нет заполнителя для таблицы
    t.setVariable("name", username);
    t.setCondition("logged-in", !username.isEmpty());
    t.loop("row", list.size());
    for (int i = 0; i < list.size(); ++i)
    {
        QString number = QString::number(i);
        QString name = list.at(i);
        t.setVariable("row" + number + ".number", number);
        t.setVariable("row" + number + ".name", name);
    }

    response.write(t.toUtf8(), true);
}
