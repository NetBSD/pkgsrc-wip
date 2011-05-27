$NetBSD: patch-native__client_src_shared_platform_nacl__host__desc.h,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- native_client/src/shared/platform/nacl_host_desc.h.orig	2011-05-24 08:19:24.000000000 +0000
+++ native_client/src/shared/platform/nacl_host_desc.h
@@ -46,7 +46,11 @@ typedef int64_t nacl_off64_t;
  * compatible w/ nacl_off64_t above.
  */
 #if NACL_LINUX
+#if defined(__NetBSD__) || defined(__DragonFly__)
+typedef struct stat nacl_host_stat_t;
+#else
 typedef struct stat64 nacl_host_stat_t;
+#endif
 #elif NACL_OSX
 typedef struct stat nacl_host_stat_t;
 #elif NACL_WINDOWS
