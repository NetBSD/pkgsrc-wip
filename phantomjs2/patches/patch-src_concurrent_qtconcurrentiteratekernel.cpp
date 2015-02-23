$NetBSD: patch-src_concurrent_qtconcurrentiteratekernel.cpp,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

--- src/qt/qtbase/src/concurrent/qtconcurrentiteratekernel.cpp.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtbase/src/concurrent/qtconcurrentiteratekernel.cpp
@@ -41,7 +41,7 @@
 
 #include "qtconcurrentiteratekernel.h"
 
-#if defined(Q_OS_MAC)
+#if defined(Q_OS_MAC) || defined(__APPLE__)
 #include <mach/mach.h>
 #include <mach/mach_time.h>
 #include <unistd.h>
@@ -67,7 +67,7 @@ enum {
     MedianSize = 7
 };
 
-#if defined(Q_OS_MAC)
+#if defined(Q_OS_MAC) || defined(__APPLE__)
 
 static qint64 getticks()
 {
