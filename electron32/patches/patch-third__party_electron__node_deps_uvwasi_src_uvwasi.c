$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uvwasi/src/uvwasi.c.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/deps/uvwasi/src/uvwasi.c
@@ -1,4 +1,8 @@
 #include <stdlib.h>
+#if defined(__NetBSD__)
+// strnlen, telldir, seekdir
+#define _NETBSD_SOURCE
+#endif
 #include <string.h>
 
 #ifndef _WIN32
