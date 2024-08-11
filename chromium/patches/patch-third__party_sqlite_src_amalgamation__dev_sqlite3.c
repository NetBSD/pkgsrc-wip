$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/sqlite/src/amalgamation_dev/sqlite3.c.orig	2024-07-24 02:46:40.672795800 +0000
+++ third_party/sqlite/src/amalgamation_dev/sqlite3.c
@@ -20545,6 +20545,9 @@ SQLITE_PRIVATE int sqlite3HeapNearlyFull
 ** The alloca() routine never returns NULL.  This will cause code paths
 ** that deal with sqlite3StackAlloc() failures to be unreachable.
 */
+#if defined(__NetBSD__)
+# undef SQLITE_USE_ALLOCA
+#endif
 #ifdef SQLITE_USE_ALLOCA
 # define sqlite3StackAllocRaw(D,N)   alloca(N)
 # define sqlite3StackAllocRawNN(D,N) alloca(N)
