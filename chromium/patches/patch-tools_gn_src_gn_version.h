$NetBSD$

--- tools/gn/src/gn/version.h.orig	2020-06-25 09:40:29.000000000 +0000
+++ tools/gn/src/gn/version.h
@@ -8,6 +8,14 @@
 #include <optional>
 #include <string>
 
+#if defined(major)
+#undef major
+#endif
+
+#if defined(minor)
+#undef minor
+#endif
+
 // Represents a semantic version.
 class Version {
  public:
