$NetBSD$

--- codelite_terminal/MainFrame.cpp.orig	2016-01-30 10:49:18.000000000 +0000
+++ codelite_terminal/MainFrame.cpp
@@ -16,6 +16,11 @@
 #include <sys/ioctl.h>
 #include <termios.h>
 #include <libutil.h>
+#elif defined(__NetBSD__)
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <util.h>
 #elif defined(__WXGTK__)
 #include <pty.h>
 #else
