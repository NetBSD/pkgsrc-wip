$NetBSD$

--- src/tools/pw-cli.c.orig	2025-07-23 15:42:58.000000000 +0000
+++ src/tools/pw-cli.c
@@ -2335,7 +2335,11 @@ int main(int argc, char *argv[])
 	setlinebuf(stdout);
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	while ((c = getopt_long(argc, argv, "hVmdr:", long_options, NULL)) != -1) {
 		switch (c) {
@@ -2447,7 +2451,11 @@ int main(int argc, char *argv[])
 	pw_context_destroy(data.context);
 	pw_main_loop_destroy(data.loop);
 	pw_map_clear(&data.vars);
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 
 	return 0;
 }
