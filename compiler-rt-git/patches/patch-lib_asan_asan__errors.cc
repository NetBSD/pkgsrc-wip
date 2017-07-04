$NetBSD$

--- lib/asan/asan_errors.cc.orig	2017-07-03 15:33:06.000000000 +0000
+++ lib/asan/asan_errors.cc
@@ -59,7 +59,7 @@ static void MaybeDumpRegisters(void *con
 }
 
 static void MaybeReportNonExecRegion(uptr pc) {
-#if SANITIZER_FREEBSD || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
   MemoryMappingLayout proc_maps(/*cache_enabled*/ true);
   uptr start, end, protection;
   while (proc_maps.Next(&start, &end, nullptr, nullptr, 0, &protection)) {
