$NetBSD: patch-third__party_WebKit_Source_JavaScriptCore_wtf_Platform.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/JavaScriptCore/wtf/Platform.h.orig	2011-04-13 08:12:03.000000000 +0000
+++ third_party/WebKit/Source/JavaScriptCore/wtf/Platform.h
@@ -398,6 +398,11 @@
 #define WTF_OS_MAC_OS_X 1
 #endif
 
+/* OS(DRAGONFLY) - DragonFly */
+#ifdef __DragonFly__
+#define WTF_OS_DRAGONFLY 1
+#endif
+
 /* OS(FREEBSD) - FreeBSD */
 #ifdef __FreeBSD__
 #define WTF_OS_FREEBSD 1
@@ -452,6 +457,7 @@
 #if   OS(AIX)              \
     || OS(ANDROID)          \
     || OS(DARWIN)           \
+    || OS(DRAGONFLY)        \
     || OS(FREEBSD)          \
     || OS(HAIKU)            \
     || OS(LINUX)            \
@@ -466,6 +472,14 @@
 #define WTF_OS_UNIX 1
 #endif
 
+/* OS(BSD) - Any BSD system */
+#if    OS(DRAGONFLY)        \
+    || OS(FREEBSD)          \
+    || OS(NETBSD)           \
+    || OS(OPENBSD)
+#define WTF_OS_BSD 1
+#endif
+
 /* Operating environments */
 
 /* FIXME: these are all mixes of OS, operating environment and policy choices. */
