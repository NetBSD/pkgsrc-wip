$NetBSD$

--- readline/util.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ readline/util.c
@@ -517,7 +517,7 @@ _rl_tropen ()
 	    : "."),
 	   getpid ());
 #else
-  sprintf (fnbuf, "/var/tmp/rltrace.%ld", (long) getpid ());
+  snprintf (fnbuf, sizeof(fnbuf), "/var/tmp/rltrace.%ld", (long)getpid());
 #endif
   unlink (fnbuf);
   _rl_tracefp = fopen (fnbuf, "w+");
