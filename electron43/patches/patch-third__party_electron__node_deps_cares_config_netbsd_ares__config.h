$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/deps/cares/config/netbsd/ares_config.h.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/deps/cares/config/netbsd/ares_config.h
@@ -119,7 +119,7 @@
 /* #undef HAVE_GETRANDOM */
 
 /* Define to 1 if you have `getservbyport_r` */
-#define HAVE_GETSERVBYPORT_R 1
+/*#define HAVE_GETSERVBYPORT_R 1*/
 
 /* Define to 1 if you have `gettimeofday` */
 #define HAVE_GETTIMEOFDAY 1
@@ -580,4 +580,4 @@
 /* #undef __MINGW_USE_VC2005_COMPAT */
 
 /* Define as 'unsigned int' if <stddef.h> doesn't define. */
-/* #undef size_t */
\ No newline at end of file
+/* #undef size_t */
