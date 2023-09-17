#ifndef COOKIETESTCONTROLLER_H
#define COOKIETESTCONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class CookieTestController : public HttpRequestHandler
{
public:
    CookieTestController(QObject* parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;
};

#endif  // COOKIETESTCONTROLLER_H
