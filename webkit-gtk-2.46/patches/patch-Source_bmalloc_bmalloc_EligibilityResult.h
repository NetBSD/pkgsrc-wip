$NetBSD$

X11/X.h:#define Success                0    /* everything's okay */

--- Source/bmalloc/bmalloc/EligibilityResult.h.orig	2024-11-07 09:18:27.511670291 +0000
+++ Source/bmalloc/bmalloc/EligibilityResult.h
@@ -29,6 +29,11 @@
 
 #if !BUSE(LIBPAS)
 
+/* avoid conflict with symbol from X11 headers */
+#ifdef Success
+#undef Success
+#endif
+
 namespace bmalloc {
 
 enum class EligibilityKind {
