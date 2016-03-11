$NetBSD$

Add sys/wait.h unconditionally, same as other source files.

--- src/watchdog/wd_escalation.c.orig	2016-02-10 08:53:31.000000000 +0000
+++ src/watchdog/wd_escalation.c
@@ -27,9 +27,7 @@
 #include <unistd.h>
 #include <errno.h>
 
-#ifdef __FreeBSD__
 #include <sys/wait.h>
-#endif
 
 #include "pool.h"
 #include "utils/elog.h"
