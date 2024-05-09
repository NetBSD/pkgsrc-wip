$NetBSD$

Fix NetBSD & FreeBSD compatibility.
https://github.com/SerenityOS/serenity/pull/24273

--- Userland/Libraries/LibJS/Heap/BlockAllocator.cpp.orig	2024-05-09 18:56:01.000000000 +0000
+++ Userland/Libraries/LibJS/Heap/BlockAllocator.cpp
@@ -55,9 +55,9 @@ void* BlockAllocator::allocate_block([[m
     }
 
 #ifdef AK_OS_SERENITY
-    auto* block = (HeapBlock*)serenity_mmap(nullptr, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_RANDOMIZED | MAP_PRIVATE, 0, 0, HeapBlock::block_size, name);
+    auto* block = (HeapBlock*)serenity_mmap(nullptr, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_RANDOMIZED | MAP_PRIVATE, -1, 0, HeapBlock::block_size, name);
 #else
-    auto* block = (HeapBlock*)mmap(nullptr, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
+    auto* block = (HeapBlock*)mmap(nullptr, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
 #endif
     VERIFY(block != MAP_FAILED);
     LSAN_REGISTER_ROOT_REGION(block, HeapBlock::block_size);
@@ -74,7 +74,7 @@ void BlockAllocator::deallocate_block(vo
         perror("munmap");
         VERIFY_NOT_REACHED();
     }
-    if (mmap(block, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED, 0, 0) != block) {
+    if (mmap(block, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED, -1, 0) != block) {
         perror("mmap");
         VERIFY_NOT_REACHED();
     }
