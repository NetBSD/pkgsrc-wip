$NetBSD$

--- third_party/pipewire/spa/utils/string.h.orig	2026-05-06 17:22:14.042192519 +0000
+++ third_party/pipewire/spa/utils/string.h
@@ -25,6 +25,12 @@ extern "C" {
  #endif
 #endif
 
+#ifdef __NetBSD__
+#define uselocale(loc) ((locale_t)0)
+#define freelocale(loc) ((void)(loc))
+#define newlocale(mask, loc, base) ((locale_t)0)
+#endif
+
 /**
  * \defgroup spa_string String handling
  * String handling utilities
