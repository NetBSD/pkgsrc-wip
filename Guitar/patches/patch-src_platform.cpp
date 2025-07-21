$NetBSD$

For environ.

--- src/platform.cpp.orig	2025-07-21 19:39:15.714158714 +0000
+++ src/platform.cpp
@@ -1,6 +1,10 @@
 #include "platform.h"
 #include "ApplicationGlobal.h"
 
+#ifndef Q_OS_WIN
+extern char** environ;
+#endif
+
 namespace platform {
 
 void initNetworking()
