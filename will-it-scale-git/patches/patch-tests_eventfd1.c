$NetBSD$

--- tests/eventfd1.c.orig	2018-03-02 23:24:04.000000000 +0000
+++ tests/eventfd1.c
@@ -1,3 +1,4 @@
+#ifdef __linux__
 #include <string.h>
 #include <unistd.h>
 #include <errno.h>
@@ -31,3 +32,10 @@ void testcase(unsigned long long *iterat
 		(*iterations)++;
 	}
 }
+#else
+char *testcase_description = "eventfd read/write of 8 bytes";
+
+void testcase(unsigned long long *iterations, unsigned long nr)
+{
+}
+#endif
