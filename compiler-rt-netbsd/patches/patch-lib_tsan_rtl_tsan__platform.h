$NetBSD$

--- lib/tsan/rtl/tsan_platform.h.orig	2017-10-05 14:37:53.556451290 +0000
+++ lib/tsan/rtl/tsan_platform.h
@@ -26,7 +26,68 @@ namespace __tsan {
 
 #if !SANITIZER_GO
 
-#if defined(__x86_64__)
+#if SANITIZER_NETBSD
+/*
+C/C++ on NetBSD/x86_64
+
+On exec() kernel maps program segments (.text, .data, .rodata...), stack and
+interpreter (if a dynamic loadable executable). Interpeter (usually ld.elf_so)
+maps into the vmmap shared libraries on the heap.
+
+The program segments are loaded on the beginning (alternatively there were
+pointed out by the ELF metadata) on the virtual address space, and the stack is
+mapped on the end of virtual address space available for user programs
+(7f7f ffff f000).
+
+AMD64 stack grows downwards and has prereserved 128GB of memory.
+There comes barrier and linker under the stack.
+
+Heap starts after another gap and goes downwards.
+
+PIE programs have randomized (ASLR) main binary segments.
+
+The position of stack, linker, heap is by default randomized by ASLR.
+The NetBSD version of ASLR can shift a mapping by 0-64MB.
+
+The first page (address 0x0) cannot be mapped (vm.user_va0_disable)
+in normal circumsances.
+
+0000 0000 1000 - 0080 0000 0000: main binary
+                               : -
+0100 0000 0000 - 2000 0000 0000: shadow
+                               : -
+3000 0000 0000 - 4000 0000 0000: metainfo (memory blocks and sync objects)
+                               : -
+6000 0000 0000 - 6200 0000 0000: traces
+                               : -
+7000 0000 0000 - 7c00 0000 0000: heap and dynamically loaded shared libraries
+                               : -
+7e00 0000 0000 - 7f7f ffff f000: main thread stack and ld.so_elf
+*/
+struct Mapping {
+  static const uptr kLoAppMemBeg   = 0x000000000000ull;
+  static const uptr kLoAppMemEnd   = 0x008000000000ull;
+
+  static const uptr kShadowBeg     = 0x010000000000ull;
+  static const uptr kShadowEnd     = 0x200000000000ull;
+
+  static const uptr kMetaShadowBeg = 0x300000000000ull;
+  static const uptr kMetaShadowEnd = 0x340000000000ull;
+
+  static const uptr kTraceMemBeg   = 0x600000000000ull;
+  static const uptr kTraceMemEnd   = 0x620000000000ull;
+
+  static const uptr kHeapMemBeg    = 0x780000000000ull;
+  static const uptr kHeapMemEnd    = 0x7c0000000000ull;
+
+  static const uptr kHiAppMemBeg   = 0x7e0000000000ull;
+  static const uptr kHiAppMemEnd   = 0x7f7ffffff000ull;
+
+  static const uptr kAppMemMsk     = 0x780000000000ull;
+  static const uptr kAppMemXor     = 0x040000000000ull;
+};
+
+#elif defined(__x86_64__)
 /*
 C/C++ on linux/x86_64 and freebsd/x86_64
 0000 0000 1000 - 0080 0000 0000: main binary and/or MAP_32BIT mappings (512GB)
@@ -387,7 +448,9 @@ enum MappingType {
   MAPPING_META_SHADOW_END,
   MAPPING_TRACE_BEG,
   MAPPING_TRACE_END,
+#if !SANITIZER_NETBSD
   MAPPING_VDSO_BEG,
+#endif
 };
 
 template<typename Mapping, int Type>
@@ -404,7 +467,9 @@ uptr MappingImpl(void) {
     case MAPPING_HI_APP_END: return Mapping::kHiAppMemEnd;
     case MAPPING_HEAP_BEG: return Mapping::kHeapMemBeg;
     case MAPPING_HEAP_END: return Mapping::kHeapMemEnd;
+#if !SANITIZER_NETBSD
     case MAPPING_VDSO_BEG: return Mapping::kVdsoBeg;
+#endif
 #else
     case MAPPING_APP_BEG: return Mapping::kAppMemBeg;
     case MAPPING_APP_END: return Mapping::kAppMemEnd;
@@ -478,10 +543,12 @@ uptr HiAppMemEnd(void) {
   return MappingArchImpl<MAPPING_HI_APP_END>();
 }
 
+#if !SANITIZER_NETBSD
 ALWAYS_INLINE
 uptr VdsoBeg(void) {
   return MappingArchImpl<MAPPING_VDSO_BEG>();
 }
+#endif
 
 #else
 
