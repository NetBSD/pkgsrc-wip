$NetBSD$

--- components/plugins/renderer/plugin_placeholder.cc.orig	2016-06-24 01:02:18.000000000 +0000
+++ components/plugins/renderer/plugin_placeholder.cc
@@ -11,7 +11,11 @@
 #include "gin/object_template_builder.h"
 #include "third_party/WebKit/public/web/WebElement.h"
 #include "third_party/WebKit/public/web/WebPluginContainer.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace plugins {
 
