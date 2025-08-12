$NetBSD$

--- src/tools/pw-top.c.orig	2024-10-21 17:10:39.289793310 +0000
+++ src/tools/pw-top.c
@@ -812,7 +812,11 @@ int main(int argc, char *argv[])
 	struct node *n;
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	data.iterations = -1;
 
@@ -921,7 +925,11 @@ int main(int argc, char *argv[])
 	pw_context_destroy(data.context);
 	pw_main_loop_destroy(data.loop);
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 
 	return 0;
 }
