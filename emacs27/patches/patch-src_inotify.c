$NetBSD$

need sys/filio.h for FIONREAD on SunOS

--- src/inotify.c.orig	2020-07-27 21:21:49.000000000 +0000
+++ src/inotify.c
@@ -25,6 +25,10 @@ along with GNU Emacs.  If not, see <http
 #include "keyboard.h"
 #include "termhooks.h"
 
+#if defined(__sun)
+#include <sys/filio.h>
+#endif
+
 #include <errno.h>
 #include <sys/inotify.h>
 #include <sys/ioctl.h>
