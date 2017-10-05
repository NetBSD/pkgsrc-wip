$NetBSD$

--- lib/tsan/rtl/tsan_platform_posix.cc.orig	2017-07-16 22:40:10.000000000 +0000
+++ lib/tsan/rtl/tsan_platform_posix.cc
@@ -124,8 +124,10 @@ void CheckAndProtect() {
     if (segment.start >= HeapMemEnd() && segment.start < HeapEnd()) continue;
     if (segment.protection == 0)  // Zero page or mprotected.
       continue;
+#if !SANITIZER_NETBSD
     if (segment.start >= VdsoBeg())  // vdso
       break;
+#endif
     Printf("FATAL: ThreadSanitizer: unexpected memory mapping %p-%p\n",
            segment.start, segment.end);
     Die();
