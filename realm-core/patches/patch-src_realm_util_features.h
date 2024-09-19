$NetBSD$

--- src/realm/util/features.h.orig	2020-06-30 08:11:11.000000000 +0000
+++ src/realm/util/features.h
@@ -262,6 +262,12 @@
 #define REALM_TVOS 0
 #endif
 
+#if defined(__NetBSD__)
+#define REALM_NETBSD 1
+#else
+#define REALM_NETBSD 0
+#endif
+
 #if REALM_ANDROID || REALM_IOS || REALM_WATCHOS || REALM_TVOS || REALM_UWP
 #define REALM_MOBILE 1
 #else
