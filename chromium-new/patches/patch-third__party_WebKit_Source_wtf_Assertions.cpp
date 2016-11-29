$NetBSD$

--- third_party/WebKit/Source/wtf/Assertions.cpp.orig	2016-11-10 20:02:27.000000000 +0000
+++ third_party/WebKit/Source/wtf/Assertions.cpp
@@ -59,7 +59,7 @@
 #include <windows.h>
 #endif
 
-#if OS(MACOSX) || (OS(LINUX) && !defined(__UCLIBC__))
+#if OS(MACOSX) || ((OS(LINUX) || OS(BSD)) && !defined(__UCLIBC__))
 #include <cxxabi.h>
 #include <dlfcn.h>
 #include <execinfo.h>
@@ -163,7 +163,7 @@ void WTFReportAssertionFailure(const cha
 
 void WTFGetBacktrace(void** stack, int* size)
 {
-#if OS(MACOSX) || (OS(LINUX) && !defined(__UCLIBC__))
+#if OS(MACOSX) || ((OS(LINUX) || OS(BSD)) && !defined(__UCLIBC__))
     *size = backtrace(stack, *size);
 #elif OS(WIN)
     // The CaptureStackBackTrace function is available in XP, but it is not defined
@@ -214,7 +214,7 @@ FrameToNameScope::FrameToNameScope(void*
     : m_name(0)
     , m_cxaDemangled(0)
 {
-#if OS(MACOSX) || (OS(LINUX) && !defined(__UCLIBC__))
+#if OS(MACOSX) || ((OS(LINUX) || OS(BSD)) && !defined(__UCLIBC__))
     Dl_info info;
     if (!dladdr(addr, &info) || !info.dli_sname)
         return;
