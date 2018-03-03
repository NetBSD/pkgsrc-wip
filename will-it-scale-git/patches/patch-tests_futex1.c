$NetBSD$

--- tests/futex1.c.orig	2018-03-02 23:24:04.000000000 +0000
+++ tests/futex1.c
@@ -1,3 +1,4 @@
+#ifdef __linux__
 #define _GNU_SOURCE
 #include <unistd.h>
 #include <sys/syscall.h>
@@ -17,3 +18,9 @@ void testcase(unsigned long long *iterat
 		(*iterations)++;
 	}
 }
+#else
+char *testcase_description = "futex(FUTEX_WAKE)";
+void testcase(unsigned long long *iterations, unsigned long nr)
+{
+}
+#endif
