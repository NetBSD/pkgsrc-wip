$NetBSD: patch-native__client_src_shared_platform_linux_nacl__host__dir.c,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- native_client/src/shared/platform/linux/nacl_host_dir.c.orig	2011-04-13 08:13:05.000000000 +0000
+++ native_client/src/shared/platform/linux/nacl_host_dir.c
@@ -34,6 +34,7 @@
 #include "native_client/src/trusted/service_runtime/include/sys/mman.h"
 #include "native_client/src/trusted/service_runtime/include/sys/stat.h"
 
+#if !defined(__NetBSD__)
 #ifdef _syscall3
 _syscall3(int, getdents, uint, fd, struct dirent *, dirp, uint, count)
 
@@ -44,6 +45,7 @@ int getdents(unsigned int fd, struct dir
   return syscall(SYS_getdents, fd, dirp, count);
 }
 #endif
+#endif
 
 int NaClHostDirOpen(struct NaClHostDir  *d,
                     char                *path) {
