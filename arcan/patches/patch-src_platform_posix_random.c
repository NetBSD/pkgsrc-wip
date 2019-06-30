$NetBSD$

NetBSD has KERN_ARND like FreeBSD, share code.

--- src/platform/posix/random.c.orig	2018-12-10 23:33:36.000000000 +0000
+++ src/platform/posix/random.c
@@ -40,7 +40,7 @@ failure:
 	errno = EIO;
 	return -1;
 }
-#elif __FreeBSD__
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 extern int __sysctl(int*, u_int, void*, size_t*, void*, size_t);
 static int getentropy(void* buf, size_t buflen)
@@ -66,6 +66,7 @@ out:
 	return 0;
 }
 
+
 #elif __OpenBSD__
 #include <unistd.h>
 #else
