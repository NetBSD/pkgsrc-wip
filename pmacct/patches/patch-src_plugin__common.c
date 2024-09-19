$NetBSD: patch-src_plugin__common.c,v 1.1 2015/02/10 00:21:42 mbowie Exp $
execv -> execvp, plus a little logging

--- src/plugin_common.c.orig	2015-02-09 18:22:14.000000000 +0000
+++ src/plugin_common.c	2015-02-09 18:25:43.000000000 +0000
@@ -690,16 +690,19 @@
 
 int P_trigger_exec(char *filename)
 {
-  char *args[1];
+  char *args[2];
   int pid;
 
   memset(args, 0, sizeof(args));
+  args[0] = filename;
+  args[1] = NULL;
 
   switch (pid = vfork()) {
   case -1:
     return -1;
   case 0:
-    execv(filename, args);
+    execvp(filename, args);
+    Log(LOG_ERR, "ERROR ( %s/%s ): Call to %s returned %d (%s).\n", config.name, config.type, filename, errno, strerror(errno));
     exit(0);
   }
 
