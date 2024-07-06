$NetBSD$

Switch NetBSD from pty to pts terminal ops.

--- qmltermwidget/lib/kpty.cpp.orig	2022-03-02 01:05:10.815701940 +0000
+++ qmltermwidget/lib/kpty.cpp
@@ -39,7 +39,9 @@
 #if defined(__NetBSD__)
 #define HAVE_LOGIN
 #define HAVE_UTIL_H
-#define HAVE_OPENPTY
+#define HAVE_PTSNAME
+#define HAVE_UNLOCKPT
+#define HAVE_GRANTPT
 #endif
 
 #if defined(__APPLE__)
