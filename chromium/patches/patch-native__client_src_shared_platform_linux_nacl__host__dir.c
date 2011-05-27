$NetBSD: patch-native__client_src_shared_platform_linux_nacl__host__dir.c,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- native_client/src/shared/platform/linux/nacl_host_dir.c.orig	2011-05-24 08:19:24.000000000 +0000
+++ native_client/src/shared/platform/linux/nacl_host_dir.c
@@ -40,6 +40,7 @@
 #include "native_client/src/trusted/service_runtime/include/sys/mman.h"
 #include "native_client/src/trusted/service_runtime/include/sys/stat.h"
 
+#if !defined(__NetBSD__) && !defined(__DragonFly__)
 #ifdef _syscall3
 _syscall3(int, getdents, uint, fd, struct dirent *, dirp, uint, count)
 
@@ -50,6 +51,7 @@ int getdents(unsigned int fd, struct dir
   return syscall(SYS_getdents, fd, dirp, count);
 }
 #endif
+#endif
 
 #define offsetof(T, member) (((char *) &((T *) 0)->member) - (char *) 0)
 
