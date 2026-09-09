$NetBSD$

To ensure that the constructor works as intended, major and minor must not be macros.

--- src/versioninfo.h.orig	2026-08-30 21:50:54.327639658 +0000
+++ src/versioninfo.h
@@ -19,6 +19,13 @@
 
 #include <string>
 
+#ifdef major
+#undef major
+#endif
+#ifdef minor
+#undef minor
+#endif
+
 class FString;
 
 struct VersionInfo
