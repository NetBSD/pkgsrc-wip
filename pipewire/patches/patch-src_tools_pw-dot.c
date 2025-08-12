$NetBSD$

--- src/tools/pw-dot.c.orig	2024-10-21 17:02:53.122364745 +0000
+++ src/tools/pw-dot.c
@@ -1364,7 +1364,11 @@ int main(int argc, char *argv[])
 	int c;
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	while ((c = getopt_long(argc, argv, "hVasdr:o:L9j:", long_options, NULL)) != -1) {
 		switch (c) {
@@ -1436,7 +1440,11 @@ int main(int argc, char *argv[])
 		spa_list_remove(&g->link);
 		free(g);
 	}
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 
 	return 0;
 }
