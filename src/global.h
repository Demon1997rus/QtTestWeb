#pragma once

#include "httpsessionstore.h"
#include "staticfilecontroller.h"
#include "templatecache.h"

using namespace stefanfrings;

extern HttpSessionStore* sessionStore;
extern StaticFileController* staticFileController;
extern TemplateCache* templateCache;
