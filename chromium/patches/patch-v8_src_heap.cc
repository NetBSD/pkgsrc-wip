$NetBSD: patch-v8_src_heap.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- v8/src/heap.cc.orig	2011-05-24 08:20:55.000000000 +0000
+++ v8/src/heap.cc
@@ -87,7 +87,8 @@ intptr_t Heap::max_old_generation_size_ 
 int Heap::initial_semispace_size_ = 128*KB;
 intptr_t Heap::code_range_size_ = 0;
 intptr_t Heap::max_executable_size_ = max_old_generation_size_;
-#elif defined(V8_TARGET_ARCH_X64)
+#elif defined(V8_TARGET_ARCH_X64) && \
+      !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 static const int default_max_semispace_size_  = 16*MB;
 intptr_t Heap::max_old_generation_size_ = 1*GB;
 int Heap::initial_semispace_size_ = 1*MB;
