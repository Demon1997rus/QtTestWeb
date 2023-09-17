#include "requestermapper.h"

RequesterMapper::RequesterMapper(QObject* parent) : HttpRequestHandler(parent) {}

void RequesterMapper::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray path = request.getPath();
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
    else
    {
        response.setStatus(404, "Not found");
        response.write("The URL is wrong, no such document.", true);
    }
    qDebug("RequestMapper: finished request");
}
