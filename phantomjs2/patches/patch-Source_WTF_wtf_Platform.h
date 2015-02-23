$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.1 2015/02/23 16:11:06 leot1990 Exp $

* Disable JIT support for NetBSD, fix segfault of qtwebkit consumers
* Use system's malloc for NetBSD, do not use fastmalloc from qt5,
  fix segfault of qtwebkit consumers

--- src/qt/qtwebkit/Source/WTF/wtf/Platform.h.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WTF/wtf/Platform.h
@@ -36,6 +36,9 @@
    macros, policy decision macros, and top-level port definitions. ==== */
 #define PLATFORM(WTF_FEATURE) (defined WTF_PLATFORM_##WTF_FEATURE  && WTF_PLATFORM_##WTF_FEATURE)
 
+#if defined(__NetBSD__)
+#define ENABLE_JIT 0
+#endif
 
 /* ==== Platform adaptation macros: these describe properties of the target environment. ==== */
 
@@ -714,6 +717,11 @@
 #endif
 #endif
 
+/* Workaround an issue with fastMalloc on NetBSD */
+#if OS(NETBSD)
+#define USE_SYSTEM_MALLOC 1
+#endif
+
 #if PLATFORM(EFL)
 #define ENABLE_GLOBAL_FASTMALLOC_NEW 0
 #endif
