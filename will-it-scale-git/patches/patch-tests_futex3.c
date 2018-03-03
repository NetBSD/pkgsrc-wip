$NetBSD$

--- tests/futex3.c.orig	2018-03-02 23:24:04.000000000 +0000
+++ tests/futex3.c
@@ -1,5 +1,7 @@
+#ifdef __linux__
 #define _GNU_SOURCE
 #include <unistd.h>
+
 #include <sys/syscall.h>
 #include <linux/futex.h>
 
@@ -17,3 +19,9 @@ void testcase(unsigned long long *iterat
 		(*iterations)++;
 	}
 }
+#else
+char *testcase_description = "futex(FUTEX_WAKE_PRIVATE)";
+void testcase(unsigned long long *iterations, unsigned long nr)
+{
+}
+#endif
