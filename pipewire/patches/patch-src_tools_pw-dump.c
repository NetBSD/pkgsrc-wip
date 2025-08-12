$NetBSD$

--- src/tools/pw-dump.c.orig	2024-10-21 17:03:44.349655454 +0000
+++ src/tools/pw-dump.c
@@ -1538,7 +1538,11 @@ int main(int argc, char *argv[])
 	int c;
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	data.out = stdout;
 	if (getenv("NO_COLOR") == NULL && isatty(fileno(data.out)))
@@ -1640,7 +1644,11 @@ int main(int argc, char *argv[])
 	spa_hook_remove(&data.core_listener);
 	pw_context_destroy(data.context);
 	pw_main_loop_destroy(data.loop);
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#elsee
+	pipewire_deinit();
+#endif
 
 	return 0;
 }
