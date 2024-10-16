$NetBSD$

Use NetBSD getopt_long(3).

--- texturator.c.orig	2024-08-11 10:17:40.690591302 +0000
+++ texturator.c
@@ -864,7 +864,11 @@ int main(int argc, char *argv[])
 	unsigned int len;
 	unsigned int vrefresh = 0;
 
+#ifdef __NetBSD__
+	while ((opt = getopt_long(argc, argv, shortopts, longopts, NULL)) != -1) {
+#else
 	while ((opt = getopt_long_only(argc, argv, shortopts, longopts, NULL)) != -1) {
+#endif
 		switch (opt) {
 		case 'D':
 			device = optarg;
