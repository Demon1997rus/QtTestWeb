#ifndef UNICODECONTROLLER_H
#define UNICODECONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class UnicodeController : public HttpRequestHandler
{
public:
    UnicodeController(QObject* parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response);
};

#endif  // UNICODECONTROLLER_H
