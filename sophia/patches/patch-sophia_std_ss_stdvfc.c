$NetBSD$
--- sophia/std/ss_stdvfs.c.orig	2018-02-06 22:08:26.000000000 -0800
+++ sophia/std/ss_stdvfs.c	2018-02-06 22:09:25.000000000 -0800
@@ -232,7 +232,8 @@
 #if  defined(__APPLE__) || \
      defined(__FreeBSD__) || \
     (defined(__FreeBSD_kernel__) && defined(__GLIBC__)) || \
-     defined(__DragonFly__)
+     defined(__DragonFly__) || \
+     defined(__NetBSD__)
 	p = mmap(NULL, size, PROT_READ|PROT_WRITE,
 	         MAP_PRIVATE|MAP_ANON, -1, 0);
 	if (p == MAP_FAILED)
