$NetBSD: patch-bicon_pty__spawn.c,v 1.2 2015/03/06 18:36:43 mbowie Exp $
Terminal includes per http://daemonforums.org/attachment.php?attachmentid=537&d=1425436939
Patch authored by bcallah@openbsd.org

--- bicon/pty_spawn.c.orig	2015-03-05 07:25:26.000000000 -0800
+++ bicon/pty_spawn.c	2015-03-05 07:26:35.000000000 -0800
@@ -13,7 +13,14 @@
 #include <string.h>
 #include <unistd.h>
 #include <errno.h>
+#ifdef __linux__
 #include <pty.h>
+#endif
+#ifdef __NetBSD__ || __OpenBSD__
+#include <termios.h>
+#include <util.h>
+#include <sys/ioctl.h>
+#endif
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/select.h>
