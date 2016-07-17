$NetBSD$

--- components/dom_distiller/core/page_features.cc.orig	2016-06-24 01:02:17.000000000 +0000
+++ components/dom_distiller/core/page_features.cc
@@ -10,7 +10,11 @@
 
 #include "base/json/json_reader.h"
 #include "base/memory/scoped_ptr.h"
-#include "third_party/re2/src/re2/re2.h"
+#if defined(OS_BSD)
+#  include <re2/re2.h>
+#else
+#  include "third_party/re2/src/re2/re2.h"
+#endif // defined(OS_BSD)
 #include "url/gurl.h"
 
 namespace dom_distiller {
