#include "requestermapper.h"

#include "global.h"

RequesterMapper::RequesterMapper(QObject* parent) : HttpRequestHandler(parent) {}

void RequesterMapper::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray path = request.getPath();
    qDebug("RequestMapper: path=%s", path.data());

    QByteArray sessionId = sessionStore->getSessionId(request, response);
    if (sessionId.isEmpty() && path == "/login")
    {
        qDebug("RequestMapper: redirect to login page");
        response.redirect("/login");
        return;
    }

    if (path == "/hello")
    {
        helloWorldController.service(request, response);
    }
    else if (path == "/list")
    {
        listDataController.service(request, response);
    }
    else if (path == "/login")
    {
        loginController.service(request, response);
    }
    else if (path == "/cookie")
    {
        cookieTestController.service(request, response);
    }
    else if (path == "/unicode")
    {
        unicodeController.service(request, response);
    }
    else if (path.startsWith("/files"))
    {
        staticFileController->service(request, response);
    }
    else if (path == "/list2")
    {
        dataTemplateController.service(request, response);
    }
    else
    {
        response.setStatus(404, "Not found");
        response.write("The URL is wrong, no such document.", true);
    }
    qDebug("RequestMapper: finished request");
}
