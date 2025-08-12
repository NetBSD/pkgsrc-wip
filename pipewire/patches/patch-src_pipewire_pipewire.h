$NetBSD$

--- src/pipewire/pipewire.h.orig	2024-10-21 16:43:48.330236571 +0000
+++ src/pipewire/pipewire.h
@@ -50,9 +50,17 @@ extern "C" {
  * \{
  */
 void
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 pw_init(int *argc, char **argv[]);
+#else
+pipewire_init(int *argc, char **argv[]);
+#endif
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 void pw_deinit(void);
+#else
+void pipewire_deinit(void);
+#endif
 
 bool
 pw_debug_is_category_enabled(const char *name);
