$NetBSD$

sudo.cpp: Make pty header conditional depending on linux

--- sudo.cpp.orig	2019-02-23 23:40:30.000000000 +0000
+++ sudo.cpp
@@ -38,7 +38,13 @@
 #include <QThread>
 #include <QProcessEnvironment>
 #include <QTimer>
+#if defined(__Linux__)
 #include <pty.h>
+#else
+#include <errno.h>
+#include <termios.h>
+#include <util.h>
+#endif
 #include <unistd.h>
 #include <memory>
 #include <csignal>
