$NetBSD$

--- components/plugins/renderer/plugin_placeholder.cc.orig	2020-07-08 21:40:40.000000000 +0000
+++ components/plugins/renderer/plugin_placeholder.cc
@@ -17,7 +17,7 @@
 #include "third_party/blink/public/web/web_plugin_container.h"
 #include "third_party/blink/public/web/web_script_source.h"
 #include "third_party/blink/public/web/web_serialized_script_value.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 namespace plugins {
 
