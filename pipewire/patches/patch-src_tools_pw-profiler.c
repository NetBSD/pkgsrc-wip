$NetBSD$

--- src/tools/pw-profiler.c.orig	2025-07-23 15:42:58.000000000 +0000
+++ src/tools/pw-profiler.c
@@ -691,7 +691,11 @@ int main(int argc, char *argv[])
 	int c;
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	while ((c = getopt_long(argc, argv, "hVr:o:Jn:", long_options, NULL)) != -1) {
 		switch (c) {
@@ -795,7 +799,11 @@ int main(int argc, char *argv[])
 		printf("{ } ]\n");
 	}
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 
 	return 0;
 }
