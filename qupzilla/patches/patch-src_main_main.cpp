$NetBSD: patch-src_main_main.cpp,v 1.1 2014/01/08 14:08:46 nros Exp $

* No non-windows and non-linux needs <iostream> for standard output too

--- src/main/main.cpp.orig	2014-01-01 19:55:33.000000000 +0000
+++ src/main/main.cpp
@@ -114,6 +114,7 @@ void qupzilla_signal_handler(int s)
 #endif // defined(Q_OS_LINUX) || defined(__GLIBC__)
 
 #ifndef Q_OS_WIN
+#include <iostream>
 #if (QT_VERSION < 0x050000)
 void msgHandler(QtMsgType type, const char* msg)
 {
