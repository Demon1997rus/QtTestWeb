#ifndef REQUESTERMAPPERT_H
#define REQUESTERMAPPERT_H

#include "httprequesthandler.h"
#include "helloworldcontroller.h"
#include "listdatacontroller.h"
#include "logincontroller.h"
#include "cookietestcontroller.h"
#include "unicodecontroller.h"
#include "datatemplatecontroller.h"

using namespace stefanfrings;

class RequesterMapper : public HttpRequestHandler
{
    Q_OBJECT
public:
    RequesterMapper(QObject* parent);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;

private:
    HelloWorldController helloWorldController;
    ListDataController listDataController;
    LoginController loginController;
    CookieTestController cookieTestController;
    UnicodeController unicodeController;
    DataTemplateController dataTemplateController;
};

#endif  // REQUESTERMAPPERT_H
