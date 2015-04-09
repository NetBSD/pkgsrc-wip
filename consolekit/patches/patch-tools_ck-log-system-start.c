$NetBSD: patch-tools_ck-log-system-start.c,v 1.3 2015/04/09 13:56:05 krytarowski Exp $

XXX: only for Linux

--- tools/ck-log-system-start.c.orig	2010-09-03 13:54:31.000000000 +0000
+++ tools/ck-log-system-start.c
@@ -41,7 +41,9 @@
 
 #define DEFAULT_LOG_FILENAME LOCALSTATEDIR "/log/ConsoleKit/history"
 
+#ifdef __linux__
 #define LINUX_KERNEL_CMDLINE "/proc/cmdline"
+#endif /* __linux__ */
 
 /* Adapted from auditd auditd-event.c */
 static gboolean
@@ -162,6 +164,7 @@ write_log_for_event (CkLogEvent *event)
 static char *
 get_boot_arguments (void)
 {
+#ifdef __linux__
         char *contents;
         gboolean res;
 
@@ -178,6 +181,9 @@ get_boot_arguments (void)
         }
 
         return contents;
+#else
+        return NULL;
+#endif
 }
 
 int
