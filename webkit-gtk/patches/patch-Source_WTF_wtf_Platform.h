$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.3 2015/01/24 01:33:08 leot1990 Exp $

--- Source/WTF/wtf/Platform.h.orig	2015-01-15 09:40:35.000000000 +0000
+++ Source/WTF/wtf/Platform.h
@@ -572,7 +572,7 @@
 #endif
 
 #if !defined(HAVE_STRNSTR)
-#if OS(DARWIN) || (OS(FREEBSD) && !defined(__GLIBC__))
+#if OS(DARWIN) || ((OS(FREEBSD) || OS(NETBSD)) && !defined(__GLIBC__))
 #define HAVE_STRNSTR 1
 #endif
 #endif
@@ -625,6 +625,11 @@
 #define USE_SYSTEM_MALLOC 1
 #endif
 
+/* Workaround an alignment issue with fastMalloc on NetBSD/arm */
+#if OS(NETBSD) && CPU(ARM)
+#define USE_SYSTEM_MALLOC 1
+#endif
+
 #define ENABLE_DEBUG_WITH_BREAKPOINT 0
 #define ENABLE_SAMPLING_COUNTERS 0
 #define ENABLE_SAMPLING_FLAGS 0
