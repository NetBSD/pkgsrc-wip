$NetBSD$

--- src/daemon/pipewire.c.orig	2024-10-21 16:45:20.167265470 +0000
+++ src/daemon/pipewire.c
@@ -63,7 +63,11 @@ int main(int argc, char *argv[])
 	config_name = basename(path);
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	level = pw_log_level;
 
@@ -136,7 +140,11 @@ done:
 		pw_context_destroy(context);
 	if (loop)
 		pw_main_loop_destroy(loop);
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 
 	return res;
 }
