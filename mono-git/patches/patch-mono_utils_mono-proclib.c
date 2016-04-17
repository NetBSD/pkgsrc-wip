$NetBSD$

--- mono/utils/mono-proclib.c.orig	2016-04-17 12:53:59.000000000 +0000
+++ mono/utils/mono-proclib.c
@@ -58,7 +58,7 @@
 #define kinfo_pid_member ki_pid
 #define kinfo_name_member ki_comm
 #endif
-#define USE_SYSCTL 1
+#define USE_SYSCTL 0
 #endif
 
 /**
