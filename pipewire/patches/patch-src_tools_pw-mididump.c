$NetBSD$

--- src/tools/pw-mididump.c.orig	2024-10-21 17:05:38.447958934 +0000
+++ src/tools/pw-mididump.c
@@ -178,7 +178,11 @@ int main(int argc, char *argv[])
 	};
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	setlinebuf(stdout);
 
@@ -209,6 +213,10 @@ int main(int argc, char *argv[])
 	} else {
 		res = dump_filter(&data);
 	}
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 	return res;
 }
