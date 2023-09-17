#ifndef LISTDATACONTROLLER_H
#define LISTDATACONTROLLER_H

#include <QStringList>

#include "httprequesthandler.h"

using namespace stefanfrings;

class ListDataController : public HttpRequestHandler
{
public:
    ListDataController(QObject* parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;

private:
    QStringList list;
};

#endif  // LISTDATACONTROLLER_H
