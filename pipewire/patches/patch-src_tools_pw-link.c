$NetBSD$

--- src/tools/pw-link.c.orig	2024-10-21 17:08:16.721868216 +0000
+++ src/tools/pw-link.c
@@ -1099,9 +1099,17 @@ int main(int argc, char *argv[])
 	setlocale(LC_ALL, "");
 	setlinebuf(stdout);
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 	int res = run(argc, argv);
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 
 	return res;
 }
