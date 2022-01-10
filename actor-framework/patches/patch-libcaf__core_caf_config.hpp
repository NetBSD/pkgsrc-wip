$NetBSD$

* add NetBSD support
* add Solaris support

--- libcaf_core/caf/config.hpp.orig	2021-07-16 09:33:16.000000000 +0000
+++ libcaf_core/caf/config.hpp
@@ -191,17 +191,21 @@
 #  endif
 #elif defined(__FreeBSD__)
 #  define CAF_BSD
+#elif defined(__NetBSD__)
+#  define CAF_NETBSD
 #elif defined(__OpenBSD__)
 #  define CAF_BSD
 #elif defined(__CYGWIN__)
 #  define CAF_CYGWIN
 #elif defined(WIN32) || defined(_WIN32)
 #  define CAF_WINDOWS
+#elif defined(__sun) || defined(__sun__) || defined(__illumos__)
+#  define CAF_SOLARIS
 #else
 #  error Platform and/or compiler not supported
 #endif
 #if defined(CAF_MACOS) || defined(CAF_LINUX) || defined(CAF_BSD)               \
-  || defined(CAF_CYGWIN)
+  || defined(CAF_CYGWIN) || defined(CAF_SOLARIS) || defined(CAF_NETBSD)
 #  define CAF_POSIX
 #endif
 
