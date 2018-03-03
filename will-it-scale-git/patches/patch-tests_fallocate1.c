$NetBSD$

--- tests/fallocate1.c.orig	2018-03-02 23:24:04.000000000 +0000
+++ tests/fallocate1.c
@@ -1,3 +1,4 @@
+#if __linux__
 #define _GNU_SOURCE             /* See feature_test_macros(7) */
 #include <errno.h>
 #include <fcntl.h>
@@ -32,4 +33,9 @@ void testcase(unsigned long long *iterat
 		(*iterations)++;
 	}
 }
-
+#else
+char *testcase_description = "Separate file fallocate ";
+void testcase(unsigned long long *iterations, unsigned long nr)
+{
+}
+#endif
