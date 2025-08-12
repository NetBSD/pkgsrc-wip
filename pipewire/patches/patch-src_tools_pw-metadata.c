$NetBSD$

--- src/tools/pw-metadata.c.orig	2024-10-21 17:06:44.708173773 +0000
+++ src/tools/pw-metadata.c
@@ -194,7 +194,11 @@ int main(int argc, char *argv[])
 	setlinebuf(stdout);
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	data.opt_name = "default";
 
@@ -289,7 +293,11 @@ int main(int argc, char *argv[])
 	pw_core_disconnect(data.core);
 	pw_context_destroy(data.context);
 	pw_main_loop_destroy(data.loop);
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 
 	return res;
 }
