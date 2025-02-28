$NetBSD$

--- src/Base/TimeInfo.cpp.orig	2016-04-07 01:39:34.000000000 +0000
+++ src/Base/TimeInfo.cpp
@@ -59,8 +59,11 @@ void TimeInfo::setCurrent(void)
 {
 #if defined (_MSC_VER)
     _ftime( &timebuffer );
-#elif defined(__GNUC__)
-    ftime( &timebuffer );
+#else
+    struct timeval curTime;
+    gettimeofday(&curTime, NULL);
+    timebuffer.time = curTime.tv_sec;
+    timebuffer.millitm = curTime.tv_usec;
 #endif
 }
 
