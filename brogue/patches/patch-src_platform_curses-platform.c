$NetBSD: patch-src_platform_curses-platform.c,v 1.1 2015/08/18 20:24:52 yhardy Exp $

Use gettimeofday instead of ftime which is obsolete

--- ./src/platform/curses-platform.c.orig	2014-07-03 19:19:10.000000000 +0000
+++ ./src/platform/curses-platform.c
@@ -3,7 +3,7 @@
 #include <string.h>
 #include <time.h>
 #include "term.h"
-#include <sys/timeb.h>
+#include <sys/time.h>
 #include <stdint.h>
 #include <signal.h>
 #include "platform.h"
@@ -109,9 +109,9 @@ static int rewriteKey(int key, boolean t
 #define PAUSE_BETWEEN_EVENT_POLLING		34//17
 
 static uint32_t getTime() {
-	struct timeb time;
-	ftime(&time);
-	return 1000 * time.time + time.millitm;
+	struct timeval time;
+	gettimeofday(&time, NULL);
+	return 1000 * time.tv_sec + time.tv_usec;
 }
 
 static boolean curses_pauseForMilliseconds(short milliseconds) {
