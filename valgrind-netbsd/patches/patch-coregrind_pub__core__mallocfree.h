$NetBSD$

--- coregrind/pub_core_mallocfree.h.orig	2018-07-13 08:52:05.000000000 +0000
+++ coregrind/pub_core_mallocfree.h
@@ -82,6 +82,7 @@ typedef Int ArenaId;
       defined(VGP_x86_darwin)     || \
       defined(VGP_amd64_darwin)   || \
       defined(VGP_arm64_linux)    || \
+      defined(VGP_amd64_netbsd)    || \
       defined(VGP_amd64_solaris)
 #  define VG_MIN_MALLOC_SZB       16
 #else
