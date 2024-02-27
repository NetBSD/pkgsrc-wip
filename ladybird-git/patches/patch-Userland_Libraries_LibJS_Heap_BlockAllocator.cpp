$NetBSD$

Fix compilation on NetBSD.
https://github.com/SerenityOS/serenity/issues/23375

--- Userland/Libraries/LibJS/Heap/BlockAllocator.cpp.orig	2024-02-27 18:49:14.164744463 +0000
+++ Userland/Libraries/LibJS/Heap/BlockAllocator.cpp
@@ -52,8 +52,10 @@ void* BlockAllocator::allocate_block([[m
         return block;
     }
 
-#ifdef AK_OS_SERENITY
+#if defined(AK_OS_SERENITY)
     auto* block = (HeapBlock*)serenity_mmap(nullptr, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_RANDOMIZED | MAP_PRIVATE, 0, 0, HeapBlock::block_size, name);
+#elif defined(AK_OS_NETBSD)
+    auto* block = (HeapBlock*)mmap(nullptr, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
 #else
     auto* block = (HeapBlock*)mmap(nullptr, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
 #endif
