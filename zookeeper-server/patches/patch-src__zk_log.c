$NetBSD: patch-src__zk_log.c,v 1.1.1.1 2012/04/19 10:31:37 fhajny Exp $

Needs to be cast as int.
--- src/c/src/zk_log.c.orig	2012-02-06 10:48:40.000000000 +0000
+++ src/c/src/zk_log.c
@@ -133,7 +133,7 @@ void log_message(ZooLogLevel curLevel,in
 #endif
     if(pid==0)pid=getpid();
 #ifndef THREADED
-    fprintf(LOGSTREAM, "%s:%d:%s@%s@%d: %s\n", time_now(get_time_buffer()),pid,
+    fprintf(LOGSTREAM, "%s:%d:%s@%s@%d: %s\n", time_now(get_time_buffer()),(int)pid,
             dbgLevelStr[curLevel],funcName,line,message);
 #else
 #ifdef WIN32
