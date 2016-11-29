$NetBSD$

--- components/arc/metrics/oom_kills_monitor.cc.orig	2016-11-10 20:02:13.000000000 +0000
+++ components/arc/metrics/oom_kills_monitor.cc
@@ -25,8 +25,13 @@
 #include "base/strings/string_split.h"
 #include "base/time/time.h"
 #include "components/arc/metrics/oom_kills_histogram.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#include <re2/stringpiece.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
 #include "third_party/re2/src/re2/stringpiece.h"
+#endif
 
 namespace arc {
 
