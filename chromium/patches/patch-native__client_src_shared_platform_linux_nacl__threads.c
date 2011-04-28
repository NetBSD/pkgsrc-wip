$NetBSD: patch-native__client_src_shared_platform_linux_nacl__threads.c,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- native_client/src/shared/platform/linux/nacl_threads.c.orig	2011-04-13 08:13:05.000000000 +0000
+++ native_client/src/shared/platform/linux/nacl_threads.c
@@ -24,6 +24,10 @@
 #include "native_client/src/shared/platform/nacl_threads.h"
 #include "native_client/src/trusted/service_runtime/nacl_config.h"
 
+#if defined(__NetBSD__)
+#define PTHREAD_STACK_MIN MINSIGSTKSZ
+#endif
+
 #if !defined(__native_client__) && NACL_KERN_STACK_SIZE < PTHREAD_STACK_MIN
 # error "NaCl service runtime stack size is smaller than PTHREAD_STACK_MIN"
 #endif
