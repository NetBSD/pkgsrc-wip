$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/cares/include/ares_build.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/deps/cares/include/ares_build.h
@@ -165,7 +165,9 @@
 #  define CARES_TYPEOF_ARES_SOCKLEN_T int
 
 #elif defined(_WIN32)
-#  define WIN32_LEAN_AND_MEAN
+#  ifndef WIN32_LEAN_AND_MEAN
+#    define WIN32_LEAN_AND_MEAN
+#  endif
 #  define CARES_TYPEOF_ARES_SOCKLEN_T int
 #  define CARES_HAVE_WINDOWS_H          1
 #  define CARES_HAVE_SYS_TYPES_H        1
