$NetBSD$

--- test-server/fuzxy.c.orig	2016-02-25 02:11:01.000000000 +0000
+++ test-server/fuzxy.c
@@ -61,6 +61,9 @@
 #include <unistd.h>
 #include <sys/socket.h>
 #endif
+#ifdefined(__NetBSD__)
+#include <netinet/in.h>
+#endif
 
 #define MAX_FUZZ_BUF (1024 * 1024)
 
@@ -953,4 +956,3 @@ bail1:
 
 	return 0;
 }
-
