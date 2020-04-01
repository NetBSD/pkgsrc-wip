$NetBSD$

--- sim/common/callback.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ sim/common/callback.c
@@ -424,7 +424,11 @@ os_system (host_callback *p, const char 
 static long
 os_time (host_callback *p, long *t)
 {
-  return wrap (p, time (t));
+  long v = (long)time(NULL);
+
+  if (t != NULL)
+    *t = v;
+  return wrap (p, v);
 }
 
 
