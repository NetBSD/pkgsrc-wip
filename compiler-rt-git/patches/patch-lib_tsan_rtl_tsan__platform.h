$NetBSD$

--- lib/tsan/rtl/tsan_platform.h.orig	2017-08-05 14:29:08.000000000 +0000
+++ lib/tsan/rtl/tsan_platform.h
@@ -42,6 +42,19 @@ C/C++ on linux/x86_64 and freebsd/x86_64
 7b00 0000 0000 - 7c00 0000 0000: heap
 7c00 0000 0000 - 7e80 0000 0000: -
 7e80 0000 0000 - 8000 0000 0000: modules and main thread stack
+
+C/C++ on netbsd/amd64 can reuse the same mapping:
+ * The address space starts from 0x1000 (option with 0x0) and ends with
+   0x7f7ffffff000.
+ * LoAppMem-kHeapMemEnd can be reused as it is.
+ * No VDSO support.
+ * No MidAppMem region.
+ * No additional HeapMem region.
+ * HiAppMem contains the stack, loader, shared libraries and heap.
+ * Stack on NetBSD/amd64 has prereserved 128MB.
+ * Heap grows downwards (top-down).
+ * ASLR must be disabled per-process or globally.
+
 */
 struct Mapping {
   static const uptr kMetaShadowBeg = 0x300000000000ull;
