$NetBSD: patch-tools_syslogd.c,v 1.1 2014/08/13 10:51:04 fhajny Exp $

Need errno.h on NetBSD. Fix default PID path.
--- tools/syslogd.c.orig	2014-06-02 09:53:19.000000000 +0000
+++ tools/syslogd.c
@@ -58,15 +58,19 @@
 #include <time.h>
 #include <assert.h>
 
-#ifdef OS_SOLARIS
+#if defined(OS_SOLARIS) || defined(__NetBSD__)
 #	include <errno.h>
+#else
+#	include <sys/errno.h>
+#endif
+
+#ifdef OS_SOLARIS
 #	include <fcntl.h>
 #	include <stropts.h>
 #	include <sys/termios.h>
 #	include <sys/types.h>
 #else
 #	include <libgen.h>
-#	include <sys/errno.h>
 #endif
 
 #include <sys/ioctl.h>
@@ -136,10 +140,10 @@ void rsyslogdDoDie(int sig);
 
 #if defined(SYSLOGD_PIDNAME)
 #	undef _PATH_LOGPID
-#	define _PATH_LOGPID "/etc/" SYSLOGD_PIDNAME
+#	define _PATH_LOGPID "@RSYSLOG_PIDDIR@/" SYSLOGD_PIDNAME
 #else
 #	ifndef _PATH_LOGPID
-#		define _PATH_LOGPID "/etc/rsyslogd.pid"
+#		define _PATH_LOGPID "@RSYSLOG_PIDDIR@/rsyslogd.pid"
 #	endif
 #endif
 
