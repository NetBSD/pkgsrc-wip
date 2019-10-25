$NetBSD$

Support NetBSD.

--- scribus/util_debug.cpp.orig	2019-07-30 22:35:07.000000000 +0000
+++ scribus/util_debug.cpp
@@ -24,7 +24,7 @@ for which a new license (GPL+exception) 
 #include <QDateTime>
 #include <QtGlobal>
 
-#if !defined(_WIN32) && !defined(Q_OS_MAC)
+#if !defined(_WIN32) && !defined(Q_OS_MAC) && !defined(Q_OS_NETBSD)
 #include <execinfo.h>
 #include <cxxabi.h>
 #endif
@@ -54,7 +54,7 @@ void tDebug(const QString& message)
  */
 void printBacktrace ( int nFrames )
 {
-#if !defined(_WIN32) && !defined(Q_OS_MAC) && !defined(Q_OS_OPENBSD) && !defined(Q_OS_FREEBSD)
+#if !defined(_WIN32) && !defined(Q_OS_MAC) && !defined(Q_OS_OPENBSD) && !defined(Q_OS_FREEBSD)  && !defined(Q_OS_NETBSD)
 	void ** trace = new void*[nFrames + 1];
 	char **messages = ( char ** ) nullptr;
 	int i, trace_size = 0;
