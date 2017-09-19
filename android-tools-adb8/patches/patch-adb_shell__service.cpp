$NetBSD$

--- adb/shell_service.cpp.orig	2017-06-27 22:39:52.000000000 +0000
+++ adb/shell_service.cpp
@@ -83,9 +83,14 @@
 
 #include <errno.h>
 #include <paths.h>
+#if defined(__linux__)
 #include <pty.h>
+#elif defined(__NetBSD__)
+#include <util.h>
+#endif
 #include <pwd.h>
 #include <sys/select.h>
+#include <sys/ioctl.h>
 #include <termios.h>
 
 #include <memory>
@@ -104,6 +109,8 @@
 #include "adb_utils.h"
 #include "security_log_tags.h"
 
+extern char **environ;
+
 namespace {
 
 // Reads from |fd| until close or failure.
