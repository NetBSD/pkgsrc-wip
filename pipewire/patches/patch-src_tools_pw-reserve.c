$NetBSD$

--- src/tools/pw-reserve.c.orig	2024-10-21 17:11:34.642954401 +0000
+++ src/tools/pw-reserve.c
@@ -107,7 +107,11 @@ int main(int argc, char *argv[])
 	setlinebuf(stdout);
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	while ((c = getopt_long(argc, argv, "hVn:a:p:mr", long_options, NULL)) != -1) {
 		switch (c) {
@@ -232,7 +236,11 @@ exit:
 	if (impl.mainloop)
 		pw_main_loop_destroy(impl.mainloop);
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 
 	return res;
 }
