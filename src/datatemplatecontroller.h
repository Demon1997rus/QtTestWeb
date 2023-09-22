#ifndef DATATEMPLATECONTROLLER_H
#define DATATEMPLATECONTROLLER_H

#include <QStringList>

#include "httprequesthandler.h"

using namespace stefanfrings;

class DataTemplateController : public HttpRequestHandler
{
public:
    DataTemplateController(QObject* parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;

private:
    QStringList list;
};

#endif  // DATATEMPLATECONTROLLER_H
