$NetBSD$

--- src/pal/src/thread/thread.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/thread/thread.cpp
@@ -53,8 +53,12 @@ Abstract:
 #include <limits.h>
 #if HAVE_SYS_LWP_H
 #include <sys/lwp.h>
-// If we don't have sys/lwp.h but do expect to use _lwp_self, declare it to silence compiler warnings
-#elif HAVE__LWP_SELF
+#endif
+#if HAVE_LWP_H
+#include <lwp.h>
+#endif
+// If we don't have lwp.h, sys/lwp.h but do expect to use _lwp_self, declare it to silence compiler warnings
+#if !HAVE_SYS_LWP_H && !HAVE_LWP_H && HAVE__LWP_SELF
 extern "C" int _lwp_self ();
 #endif // HAVE_LWP_H
 
