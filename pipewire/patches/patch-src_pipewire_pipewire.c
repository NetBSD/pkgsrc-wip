$NetBSD$

https://gitlab.freedesktop.org/pipewire/pipewire/-/issues/1819

--- src/pipewire/pipewire.c.orig	2024-09-27 10:02:20.000000000 +0000
+++ src/pipewire/pipewire.c
@@ -7,7 +7,7 @@
 #include <unistd.h>
 #include <limits.h>
 #include <stdio.h>
-#if !defined(__FreeBSD__) && !defined(__MidnightBSD__) && !defined(__GNU__)
+#if !defined(__FreeBSD__) && !defined(__MidnightBSD__) && !defined(__NetBSD__) && !defined(__GNU__)
 #include <sys/prctl.h>
 #endif
 #include <pwd.h>
@@ -484,7 +484,7 @@ static struct spa_log *load_journal_logg
  * This function can be called multiple times.
  */
 SPA_EXPORT
-void pw_init(int *argc, char **argv[])
+void pipewire_init(int *argc, char **argv[])
 {
 	const char *str;
 	struct spa_dict_item items[6];
@@ -596,7 +596,7 @@ done:
  * used again after being deinitialized with a new pw_init() call.
  */
 SPA_EXPORT
-void pw_deinit(void)
+void pipewire_deinit(void)
 {
 	struct support *support = &global_support;
 	struct registry *registry = &support->registry;
@@ -622,6 +622,21 @@ done:
 
 }
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
+#undef pw_init
+SPA_EXPORT
+void pw_init(int *argc, char **argv[])
+{
+	pipewire_init(argc, argv);
+}
+#undef pw_deinit
+SPA_EXPORT
+void pw_deinit(void)
+{
+	pipewire_deinit();
+}
+#endif
+
 /** Check if a debug category is enabled
  *
  * \param name the name of the category to check
@@ -669,7 +684,7 @@ static void init_prgname(void)
 		}
 	}
 #endif
-#if !defined(__FreeBSD__) && !defined(__MidnightBSD__) && !defined(__GNU__)
+#if !defined(__FreeBSD__) && !defined(__MidnightBSD__) && !defined(__GNU__) && !defined(__NetBSD__)
 	{
 		if (prctl(PR_GET_NAME, (unsigned long) name, 0, 0, 0) == 0) {
 			prgname = name;
