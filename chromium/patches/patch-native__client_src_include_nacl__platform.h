$NetBSD: patch-native__client_src_include_nacl__platform.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- native_client/src/include/nacl_platform.h.orig	2011-04-13 08:13:05.000000000 +0000
+++ native_client/src/include/nacl_platform.h
@@ -49,13 +49,11 @@
 /* mmap enums, e.g.  PROT_READ, PROT_WRITE*/
 #if NACL_WINDOWS
 #include "native_client/src/include/win/mman.h"
-#elif NACL_OSX
+#elif NACL_OSX || NACL_LINUX
 # include <sys/mman.h>
 #ifndef MAP_ANONYMOUS
 #define MAP_ANONYMOUS MAP_ANON
 #endif
-#elif NACL_LINUX
-# include <sys/mman.h>
 #endif
 
 #endif  /* NATIVE_CLIENT_SRC_INCLUDE_NACL_PLATFORM_H_ */
