$NetBSD: patch-nodm.c,v 1.1 2013/04/07 20:54:18 khorben Exp $

Give it more chances to work on NetBSD

--- nodm.c.orig	2009-07-26 18:36:14.000000000 +0000
+++ nodm.c
@@ -69,10 +69,16 @@
 #include <time.h>
 #include <unistd.h>
 #include <fcntl.h>
-#include <sys/vt.h>
+#ifdef __NetBSD__
+# include <dev/wscons/wsdisplay_usl_io.h>
+#else
+# include <sys/vt.h>
+#endif
 
 #include <security/pam_appl.h>
-#include <security/pam_misc.h>
+#ifndef __NetBSD__
+# include <security/pam_misc.h>
+#endif
 
 static struct pam_conv conv = {
 	misc_conv,
@@ -267,7 +273,11 @@ cleanup:
 static int get_vtstate(struct vt_stat* vtstat)
 {
 	if (try_vtstate("/dev/tty", vtstat)) return 1;
+#ifdef __NetBSD__
+	if (try_vtstate("/dev/ttyE0", vtstat)) return 1;
+#else
 	if (try_vtstate("/dev/tty0", vtstat)) return 1;
+#endif
 	if (try_vtstate("/dev/console", vtstat)) return 1;
 	return 0;
 }
