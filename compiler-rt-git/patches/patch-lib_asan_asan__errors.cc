$NetBSD$

--- lib/asan/asan_errors.cc.orig	2017-08-05 14:29:08.000000000 +0000
+++ lib/asan/asan_errors.cc
@@ -59,7 +59,7 @@ static void MaybeDumpRegisters(void *con
 }
 
 static void MaybeReportNonExecRegion(uptr pc) {
-#if SANITIZER_FREEBSD || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
   MemoryMappingLayout proc_maps(/*cache_enabled*/ true);
   MemoryMappedSegment segment;
   while (proc_maps.Next(&segment)) {
