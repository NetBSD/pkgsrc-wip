$NetBSD$

--- src/modules/procstats/process.c.orig	2023-12-23 16:08:09.000000000 +0000
+++ src/modules/procstats/process.c
@@ -1,12 +1,14 @@
-#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__NetBSD__)
 # include <sys/types.h>
 # include <sys/sysctl.h>
+#if ! defined(__NetBSD__)
 # include <sys/user.h>
+#endif
 # include <sys/proc.h>
 # include <libgen.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__NetBSD__)
 # include <libgen.h>
 # include <unistd.h>
 # include <fcntl.h>
@@ -93,7 +95,7 @@ _process_state_name(char state)
       case SIDL:
         statename = "idle";
         break;
-
+#if !defined(__NetBSD__)
       case SRUN:
         statename = "run";
         break;
@@ -101,17 +103,33 @@ _process_state_name(char state)
       case SSLEEP:
         statename = "sleep";
         break;
+#else
+      case LSRUN:
+        statename = "run";
+        break;
 
+      case LSSLEEP:
+        statename = "sleep";
+        break;
+#endif
       case SSTOP:
         statename = "stop";
         break;
 
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) 
+#if defined(__NetBSD__)
+      case PWAIT:
+#else
       case SWAIT:
+#endif
         statename = "wait";
         break;
 
+#if defined(__NetBSD__)
+      case PLOCK:
+#else
       case SLOCK:
+#endif
         statename = "lock";
         break;
 
