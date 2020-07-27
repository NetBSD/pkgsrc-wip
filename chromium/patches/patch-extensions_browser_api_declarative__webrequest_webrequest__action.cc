$NetBSD$

--- extensions/browser/api/declarative_webrequest/webrequest_action.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ extensions/browser/api/declarative_webrequest/webrequest_action.cc
@@ -28,7 +28,7 @@
 #include "extensions/common/extension.h"
 #include "net/base/registry_controlled_domains/registry_controlled_domain.h"
 #include "net/http/http_util.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 using extension_web_request_api_helpers::EventResponseDelta;
 
