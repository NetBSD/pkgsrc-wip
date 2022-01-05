$NetBSD$

* add NetBSD support

--- libcaf_core/caf/config.hpp.orig	2021-07-16 09:33:16.000000000 +0000
+++ libcaf_core/caf/config.hpp
@@ -191,6 +191,9 @@
 #  endif
 #elif defined(__FreeBSD__)
 #  define CAF_BSD
+#elif defined(__NetBSD__)
+#  define CAF_BSD
+#  define CAF_NETBSD
 #elif defined(__OpenBSD__)
 #  define CAF_BSD
 #elif defined(__CYGWIN__)
