$NetBSD$

--- readline/util.c.orig	2017-09-11 11:24:05.000000000 +0000
+++ readline/util.c
@@ -517,7 +517,7 @@ _rl_tropen ()
 	    : "."),
 	   getpid());
 #else
-  sprintf (fnbuf, "/var/tmp/rltrace.%ld", getpid());
+  sprintf (fnbuf, "/var/tmp/rltrace.%ld", (long)getpid());
 #endif
   unlink(fnbuf);
   _rl_tracefp = fopen (fnbuf, "w+");
