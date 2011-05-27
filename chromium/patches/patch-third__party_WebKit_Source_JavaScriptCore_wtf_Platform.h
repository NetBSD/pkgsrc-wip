$NetBSD: patch-third__party_WebKit_Source_JavaScriptCore_wtf_Platform.h,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- third_party/WebKit/Source/JavaScriptCore/wtf/Platform.h.orig	2011-05-24 08:02:57.000000000 +0000
+++ third_party/WebKit/Source/JavaScriptCore/wtf/Platform.h
@@ -400,6 +400,11 @@
 #define WTF_OS_MAC_OS_X 1
 #endif
 
+/* OS(DRAGONFLY) - DragonFly */
+#ifdef __DragonFly__
+#define WTF_OS_DRAGONFLY 1
+#endif
+
 /* OS(FREEBSD) - FreeBSD */
 #if defined(__FreeBSD__) || defined(__DragonFly__)
 #define WTF_OS_FREEBSD 1
@@ -454,6 +459,7 @@
 #if   OS(AIX)              \
     || OS(ANDROID)          \
     || OS(DARWIN)           \
+    || OS(DRAGONFLY)        \
     || OS(FREEBSD)          \
     || OS(HAIKU)            \
     || OS(LINUX)            \
@@ -468,6 +474,14 @@
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
