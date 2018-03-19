$NetBSD$

--- src/StatCache.cc.orig	2018-03-13 12:12:43.000000000 +0000
+++ src/StatCache.cc
@@ -27,7 +27,8 @@
 #include "StatCache.h"
 #include "printutils.h"
 
-#include <sys/timeb.h>
+#include <sys/types.h>
+#include <sys/time.h>
 #include <string>
 #include <unordered_map>
 
@@ -37,9 +38,9 @@ const float stale = 0.190;  // Maximum l
 
 double millis_clock(void)
 {
-	struct timeb tb;
-	ftime(&tb);
-	return tb.time + double(tb.millitm) / 1000;
+	 struct timeval tv;
+	 gettimeofday(&tv, NULL);
+	 return (unsigned long)tv.tv_sec*1000UL+(unsigned long)tv.tv_usec/1000;
 }
 
 struct CacheEntry
