$NetBSD$

--- chrome/browser/extensions/activity_log/activity_log.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/extensions/activity_log/activity_log.cc
@@ -47,7 +47,7 @@
 #include "extensions/browser/extensions_browser_client.h"
 #include "extensions/common/extension.h"
 #include "extensions/common/extension_messages.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 #include "url/gurl.h"
 
 namespace constants = activity_log_constants;
