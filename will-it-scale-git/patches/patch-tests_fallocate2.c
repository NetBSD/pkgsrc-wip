$NetBSD$

--- tests/fallocate2.c.orig	2019-11-20 22:52:24.000000000 +0000
+++ tests/fallocate2.c
@@ -1,3 +1,10 @@
+char *testcase_description = "Separate file fallocate";
+
+#if defined(__NetBSD__)
+void testcase(unsigned long long *iterations, unsigned long nr)
+{
+}
+#else
 #define _GNU_SOURCE             /* See feature_test_macros(7) */
 #include <errno.h>
 #include <fcntl.h>
@@ -9,8 +16,6 @@
 #define FILESIZE (1 * 1024 * 1024)
 #define BUFLEN (FILESIZE / 128)
 
-char *testcase_description = "Separate file fallocate";
-
 void testcase(unsigned long long *iterations, unsigned long nr)
 {
 	char tmpfile[] = "/tmp/willitscale.XXXXXX";
@@ -32,4 +37,4 @@ void testcase(unsigned long long *iterat
 		(*iterations)++;
 	}
 }
-
+#endif
