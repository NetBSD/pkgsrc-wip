$NetBSD$

--- src/tools/pw-mon.c.orig	2024-10-21 16:59:19.555160910 +0000
+++ src/tools/pw-mon.c
@@ -805,7 +805,11 @@ int main(int argc, char *argv[])
 	bool colors = false;
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	setlinebuf(stdout);
 
@@ -911,7 +915,11 @@ int main(int argc, char *argv[])
 	spa_hook_remove(&data.core_listener);
 	pw_context_destroy(data.context);
 	pw_main_loop_destroy(data.loop);
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 
 	return 0;
 }
