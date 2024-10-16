$NetBSD$

Use NetBSD getopt_long(3).

--- kmscube.c.orig	2024-08-11 10:18:48.284248438 +0000
+++ kmscube.c
@@ -122,7 +122,11 @@ int main(int argc, char *argv[])
 	GST_DEBUG_CATEGORY_INIT(kmscube_debug, "kmscube", 0, "kmscube video pipeline");
 #endif
 
+#ifdef __NetBSD__
+	while ((opt = getopt_long(argc, argv, shortopts, longopts, NULL)) != -1) {
+#else
 	while ((opt = getopt_long_only(argc, argv, shortopts, longopts, NULL)) != -1) {
+#endif
 		switch (opt) {
 		case 'A':
 			atomic = 1;
