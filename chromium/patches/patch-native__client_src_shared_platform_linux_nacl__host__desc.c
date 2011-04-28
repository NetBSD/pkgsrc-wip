$NetBSD: patch-native__client_src_shared_platform_linux_nacl__host__desc.c,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- native_client/src/shared/platform/linux/nacl_host_desc.c.orig	2011-04-13 08:13:05.000000000 +0000
+++ native_client/src/shared/platform/linux/nacl_host_desc.c
@@ -383,7 +383,11 @@ int NaClHostDescIoctl(struct NaClHostDes
 int NaClHostDescFstat(struct NaClHostDesc  *d,
                       nacl_host_stat_t     *nhsp) {
 #if NACL_LINUX
+#if defined(__NetBSD__)
+  if (fstat(d->d, nhsp) == -1) {
+#else
   if (fstat64(d->d, nhsp) == -1) {
+#endif
     return -errno;
   }
 #elif NACL_OSX
@@ -418,7 +422,11 @@ int NaClHostDescStat(char const       *h
                      nacl_host_stat_t *nhsp) {
 
 #if NACL_LINUX
+#if defined(__NetBSD__)
+  if (stat(host_os_pathname, nhsp) == -1) {
+#else
   if (stat64(host_os_pathname, nhsp) == -1) {
+#endif
     return -errno;
   }
 #elif NACL_OSX
