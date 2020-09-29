$NetBSD$

--- monitor/hal/hal-volume-monitor-daemon.c.orig	2020-09-28 23:58:08.642966101 +0000
+++ monitor/hal/hal-volume-monitor-daemon.c
@@ -27,14 +27,33 @@
 #include <glib/gi18n-lib.h>
 #include <gmodule.h>
 #include <gio/gio.h>
+#include <signal.h>
+#include <unistd.h>
 
 #include <gvfsproxyvolumemonitordaemon.h>
 
 #include "ghalvolumemonitor.h"
 
+static char	**saveargs;
+
+static void reset(int s) {
+	sigset_t	set;
+
+	sigemptyset(&set);
+	sigaddset(&set,SIGHUP);
+	sigprocmask(SIG_UNBLOCK,&set,NULL);
+	execvp(saveargs[0],saveargs);
+}
+
 int
 main (int argc, char *argv[])
 {
+
+  if (signal(SIGHUP, reset) ==  SIG_ERR) {
+	perror ("SIGHUP");
+	exit (1);
+  }
+  saveargs=argv;
   g_vfs_proxy_volume_monitor_daemon_init ();
   return g_vfs_proxy_volume_monitor_daemon_main (argc,
                                                  argv,
