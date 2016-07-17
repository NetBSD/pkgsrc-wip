$NetBSD$

--- components/url_matcher/url_matcher_factory.cc.orig	2016-06-24 01:02:19.000000000 +0000
+++ components/url_matcher/url_matcher_factory.cc
@@ -15,7 +15,11 @@
 #include "base/values.h"
 #include "components/url_matcher/url_matcher_constants.h"
 #include "components/url_matcher/url_matcher_helpers.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace url_matcher {
 
