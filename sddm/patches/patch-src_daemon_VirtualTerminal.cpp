$NetBSD$

NetBSD support

--- src/daemon/VirtualTerminal.cpp.orig	2018-09-26 19:03:47.000000000 +0000
+++ src/daemon/VirtualTerminal.cpp
@@ -27,8 +27,12 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <signal.h>
+#if defined(Q_OS_NETBSD)
+#include <dev/wscons/wsdisplay_usl_io.h>
+#else
 #include <linux/vt.h>
 #include <linux/kd.h>
+#endif
 #include <sys/ioctl.h>
 
 #define RELEASE_DISPLAY_SIGNAL (SIGRTMAX)
@@ -81,10 +85,12 @@ namespace SDDM {
             if (getmodeReply.mode != VT_AUTO)
                 goto out;
 
+#ifdef KDGETMODE
             if (ioctl(fd, KDGETMODE, &kernelDisplayMode) < 0) {
                 qWarning() << "Failed to query kernel display mode:" << strerror(errno);
                 ok = false;
             }
+#endif
 
             if (kernelDisplayMode == KD_TEXT)
                 goto out;
