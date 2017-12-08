$NetBSD$

--- lib/msan/msan_allocator.cc.orig	2017-10-17 18:35:51.000000000 +0000
+++ lib/msan/msan_allocator.cc
@@ -62,7 +62,8 @@ struct MsanMapUnmapCallback {
   };
   typedef SizeClassAllocator32<AP32> PrimaryAllocator;
 #elif defined(__x86_64__)
-#if SANITIZER_LINUX && !defined(MSAN_LINUX_X86_64_OLD_MAPPING)
+#if SANITIZER_NETBSD || \
+    (SANITIZER_LINUX && !defined(MSAN_LINUX_X86_64_OLD_MAPPING))
   static const uptr kAllocatorSpace = 0x700000000000ULL;
 #else
   static const uptr kAllocatorSpace = 0x600000000000ULL;
