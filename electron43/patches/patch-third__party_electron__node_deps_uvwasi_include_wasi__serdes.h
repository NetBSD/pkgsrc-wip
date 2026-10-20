$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/deps/uvwasi/include/wasi_serdes.h.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/deps/uvwasi/include/wasi_serdes.h
@@ -3,6 +3,13 @@
 
 #include "wasi_types.h"
 
+#ifdef __NetBSD__
+#undef uint8_t
+#undef uint16_t
+#undef uint32_t
+#undef uint64_t
+#endif
+
 /* Basic uint{8,16,32,64}_t read/write functions. */
 
 #define BASIC_TYPE(name, type)                                                \
