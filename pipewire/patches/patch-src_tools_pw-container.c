$NetBSD$

--- src/tools/pw-container.c.orig	2024-10-21 17:02:04.736034476 +0000
+++ src/tools/pw-container.c
@@ -159,7 +159,11 @@ int main(int argc, char *argv[])
 			NULL);
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	while ((c = getopt_long(argc, argv, "hVr:P:", long_options, NULL)) != -1) {
 		switch (c) {
@@ -297,7 +301,11 @@ int main(int argc, char *argv[])
 	pw_context_destroy(data.context);
 	pw_main_loop_destroy(data.loop);
 	pw_properties_free(data.props);
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 
 	return 0;
 }
