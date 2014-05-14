$NetBSD: patch-src__zk_log.c,v 1.2 2014/05/14 09:51:07 fhajny Exp $

Needs to be cast as int.
--- src/c/src/zk_log.c.orig	2014-02-20 10:14:09.000000000 +0000
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
