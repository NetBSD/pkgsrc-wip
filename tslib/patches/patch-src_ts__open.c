$NetBSD$

Add support for identifying more operating systems.

--- src/ts_open.c.orig	2018-04-19 13:06:37.000000000 +0000
+++ src/ts_open.c
@@ -41,8 +41,12 @@ static void print_host_os(void)
 	printf("Host OS: Linux");
 #elif defined (__FreeBSD__)
 	printf("Host OS: FreeBSD");
+#elif defined (__NetBSD__)
+	printf("Host OS: NetBSD");
 #elif defined (__OpenBSD__)
 	printf("Host OS: OpenBSD");
+#elif defined (__sun)
+	printf("Host OS: Solaris");
 #elif defined (__GNU__) && defined (__MACH__)
 	printf("Host OS: Hurd");
 #elif defined (__HAIKU__)
