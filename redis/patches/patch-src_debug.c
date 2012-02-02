$NetBSD: patch-src_debug.c,v 1.1 2012/02/02 08:52:50 fhajny Exp $

Fix for systems without backtrace support.
https://github.com/antirez/redis/pull/240

--- src/debug.c.orig    2012-01-11 19:30:55.000000000 +0000
+++ src/debug.c
@@ -338,7 +338,9 @@ void debugCommand(redisClient *c) {
 }
 
 void _redisAssert(char *estr, char *file, int line) {
+#ifdef HAVE_BACKTRACE
     bugReportStart();
+#endif
     redisLog(REDIS_WARNING,"=== ASSERTION FAILED ===");
     redisLog(REDIS_WARNING,"==> %s:%d '%s' is not true",file,line,estr);
 #ifdef HAVE_BACKTRACE
@@ -351,7 +353,9 @@ void _redisAssert(char *estr, char *file
 }
 
 void _redisPanic(char *msg, char *file, int line) {
+#ifdef HAVE_BACKTRACE
     bugReportStart();
+#endif
     redisLog(REDIS_WARNING,"!!! Software Failure. Press left mouse button to continue");
     redisLog(REDIS_WARNING,"Guru Meditation: %s #%s:%d",msg,file,line);
 #ifdef HAVE_BACKTRACE
