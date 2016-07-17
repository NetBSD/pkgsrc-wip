$NetBSD$

--- chrome/browser/extensions/activity_log/activity_log.cc.orig	2016-06-24 01:02:12.000000000 +0000
+++ chrome/browser/extensions/activity_log/activity_log.cc
@@ -39,7 +39,11 @@
 #include "extensions/browser/extensions_browser_client.h"
 #include "extensions/common/extension.h"
 #include "extensions/common/one_shot_event.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 namespace constants = activity_log_constants;
