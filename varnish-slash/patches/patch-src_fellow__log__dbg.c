$NetBSD$

--- src/fellow_log_dbg.c.orig	2023-02-06 07:10:31.000000000 +0000
+++ src/fellow_log_dbg.c
@@ -32,7 +32,9 @@
 #elif HAVE_SYS_DKIO_H
 #include <sys/types.h>
 #include <sys/dkio.h>
+#if !defined(__NetBSD__)
 #include <sys/vtoc.h>
+#endif
 #else
 #error No support to determine device size
 #endif
@@ -79,6 +81,8 @@ getsize(const char *filename)
 		if (ioctl(fd, BLKGETSIZE, &r))
 			goto err;
 		r *= 512;
+#elif defined(HAVE_SYS_DKIO_H) && defined(__NetBSD__)
+		assert(0 /* fixme ioctl */);
 #elif HAVE_SYS_DKIO_H
 		{
 		struct dk_minfo dkmp;
