$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/histogram/src/hdr_atomic.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/deps/histogram/src/hdr_atomic.h
@@ -14,6 +14,13 @@
 #include <intrin.h>
 #include <stdbool.h>
 
+#if !defined(_ReadBarrier) || !defined(_WriteBarrier)
+
+#define _ReadBarrier() __asm__ __volatile__("" ::: "memory")
+#define _WriteBarrier() __asm__ __volatile__("" ::: "memory")
+
+#endif
+
 static void __inline * hdr_atomic_load_pointer(void** pointer)
 {
 	_ReadBarrier();
