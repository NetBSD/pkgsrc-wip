$NetBSD: patch-Source_WTF_wtf_Assertions.cpp,v 1.1 2015/02/23 16:11:06 leot1990 Exp $

* Add NetBSD support

--- src/qt/qtwebkit/Source/WTF/wtf/Assertions.cpp.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WTF/wtf/Assertions.cpp
@@ -61,7 +61,7 @@
 #include <windows.h>
 #endif
 
-#if (OS(DARWIN) || (OS(LINUX) && !defined(__UCLIBC__))) && !OS(ANDROID)
+#if (OS(DARWIN) || OS(NETBSD) || (OS(LINUX) && !defined(__UCLIBC__))) && !OS(ANDROID)
 #include <cxxabi.h>
 #include <dlfcn.h>
 #include <execinfo.h>
@@ -245,7 +245,7 @@ void WTFReportArgumentAssertionFailure(c
 
 void WTFGetBacktrace(void** stack, int* size)
 {
-#if (OS(DARWIN) || (OS(LINUX) && !defined(__UCLIBC__))) && !OS(ANDROID)
+#if (OS(DARWIN) || (OS_NETBSD) || (OS(LINUX) && !defined(__UCLIBC__))) && !OS(ANDROID)
     *size = backtrace(stack, *size);
 #elif OS(WINDOWS) && !OS(WINCE)
     // The CaptureStackBackTrace function is available in XP, but it is not defined
@@ -279,7 +279,7 @@ void WTFReportBacktrace()
     WTFPrintBacktrace(samples + framesToSkip, frames - framesToSkip);
 }
 
-#if OS(DARWIN) || OS(LINUX)
+#if OS(DARWIN) || OS(LINUX) || OS(NETBSD)
 #  if PLATFORM(QT) || PLATFORM(GTK)
 #    if defined(__GLIBC__) && !defined(__UCLIBC__)
 #      define WTF_USE_BACKTRACE_SYMBOLS 1
