$NetBSD$

--- sendmail/sendmail.h.orig	2023-12-05 09:53:22.000000000 +0000
+++ sendmail/sendmail.h
@@ -73,6 +73,10 @@ SM_UNUSED(static char SmailId[]) = "@(#)
 #endif
 
 #include "bf.h"
+#ifdef USE_BLACKLIST
+#include <blacklist.h>
+#endif
+#include "blacklist_client.h"
 #include "timers.h"
 #include <sm/exc.h>
 #include <sm/gen.h>
@@ -2735,6 +2739,8 @@ EXTERN int Hacks;	/* bit field of run-ti
 
 EXTERN int ConnectionRateWindowSize;
 
+EXTERN bool UseBlacklist;
+
 /*
 **  Declarations of useful functions
 */
