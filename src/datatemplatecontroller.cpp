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
    QByteArray language = request.getHeader("Accept-Language");
    response.setHeader("Content-Type", "text/html; charset=UTF-8");

    Template t = templateCache->getTemplate("files/hello", language);
    response.write(t.toUtf8(), true);
}
