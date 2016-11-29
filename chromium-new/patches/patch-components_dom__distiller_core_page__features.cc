$NetBSD$

--- components/dom_distiller/core/page_features.cc.orig	2016-11-10 20:02:13.000000000 +0000
+++ components/dom_distiller/core/page_features.cc
@@ -10,7 +10,11 @@
 #include <string>
 
 #include "base/json/json_reader.h"
+#if !defined(OS_BSD)
 #include "third_party/re2/src/re2/re2.h"
+#else
+#include <re2/re2.h>
+#endif
 #include "url/gurl.h"
 
 namespace dom_distiller {
