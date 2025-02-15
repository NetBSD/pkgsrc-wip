$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/metrics/persistent_memory_allocator.cc.orig	2024-10-18 12:33:59.786263200 +0000
+++ base/metrics/persistent_memory_allocator.cc
@@ -59,7 +59,7 @@ constexpr uint32_t kGlobalCookie = 0x408
 // the metadata, the version number can be queried to operate in a backward-
 // compatible manner until the memory segment is completely re-initalized.
 // Note: If you update the metadata in a non-backwards compatible way, reset
-// |kCompatibleVersions|. Otherwise, add the previous version.
+// `kCompatibleVersions`. Otherwise, add the previous version.
 constexpr uint32_t kGlobalVersion = 3;
 static constexpr uint32_t kOldCompatibleVersions[] = {2};
 
@@ -146,12 +146,12 @@ struct PersistentMemoryAllocator::Shared
 
   // The "iterable" queue is an M&S Queue as described here, append-only:
   // https://www.research.ibm.com/people/m/michael/podc-1996.pdf
-  // |queue| needs to be 64-bit aligned and is itself a multiple of 64 bits.
+  // `queue` needs to be 64-bit aligned and is itself a multiple of 64 bits.
   volatile std::atomic<uint32_t> tailptr;  // Last block of iteration queue.
   volatile BlockHeader queue;   // Empty block for linked-list head/tail.
 };
 
-// The "queue" block header is used to detect "last node" so that zero/null
+// The `queue` block header is used to detect the "last node" so that zero/null
 // can be used to indicate that it hasn't been added at all. It is part of
 // the SharedMetadata structure which itself is always located at offset zero.
 const PersistentMemoryAllocator::Reference
@@ -208,7 +208,8 @@ PersistentMemoryAllocator::Iterator::Get
 }
 
 PersistentMemoryAllocator::Reference
-PersistentMemoryAllocator::Iterator::GetNext(uint32_t* type_return) {
+PersistentMemoryAllocator::Iterator::GetNext(uint32_t* type_return,
+                                             size_t* alloc_size) {
   // Make a copy of the existing count of found-records, acquiring all changes
   // made to the allocator, notably "freeptr" (see comment in loop for why
   // the load of that value cannot be moved above here) that occurred during
@@ -219,12 +220,13 @@ PersistentMemoryAllocator::Iterator::Get
   // "count" was fetched _after_ "freeptr" then it would be possible for
   // this thread to be interrupted between them and other threads perform
   // multiple allocations, make-iterables, and iterations (with the included
-  // increment of |record_count_|) culminating in the check at the bottom
+  // increment of `record_count_`) culminating in the check at the bottom
   // mistakenly determining that a loop exists. Isn't this stuff fun?
   uint32_t count = record_count_.load(std::memory_order_acquire);
 
   Reference last = last_record_.load(std::memory_order_acquire);
-  Reference next;
+  Reference next = 0;
+  size_t next_size = 0;
   while (true) {
     const volatile BlockHeader* block =
         allocator_->GetBlock(last, 0, 0, true, false);
@@ -245,7 +247,7 @@ PersistentMemoryAllocator::Iterator::Get
     next = block->next.load(std::memory_order_acquire);
     if (next == kReferenceQueue)  // No next allocation in queue.
       return kReferenceNull;
-    block = allocator_->GetBlock(next, 0, 0, false, false);
+    block = allocator_->GetBlock(next, 0, 0, false, false, &next_size);
     if (!block) {  // Memory is corrupt.
       allocator_->SetCorrupt();
       return kReferenceNull;
@@ -286,21 +288,29 @@ PersistentMemoryAllocator::Iterator::Get
   // It does not matter if it falls behind temporarily so long as it never
   // gets ahead.
   record_count_.fetch_add(1, std::memory_order_release);
+  if (alloc_size) {
+    *alloc_size = next_size;
+  }
   return next;
 }
 
 PersistentMemoryAllocator::Reference
-PersistentMemoryAllocator::Iterator::GetNextOfType(uint32_t type_match) {
+PersistentMemoryAllocator::Iterator::GetNextOfType(uint32_t type_match,
+                                                   size_t* alloc_size) {
   Reference ref;
+  size_t size;
   uint32_t type_found;
-  while ((ref = GetNext(&type_found)) != 0) {
-    if (type_found == type_match)
+  while ((ref = GetNext(&type_found, &size)) != 0) {
+    if (type_found == type_match) {
+      if (alloc_size) {
+        *alloc_size = size;
+      }
       return ref;
+    }
   }
   return kReferenceNull;
 }
 
-
 // static
 bool PersistentMemoryAllocator::IsMemoryAcceptable(const void* base,
                                                    size_t size,
@@ -475,12 +485,12 @@ uint64_t PersistentMemoryAllocator::Id()
 
 const char* PersistentMemoryAllocator::Name() const {
   Reference name_ref = shared_meta()->name;
-  const char* name_cstr =
-      GetAsArray<char>(name_ref, 0, PersistentMemoryAllocator::kSizeAny);
+  size_t name_length = 0;
+  const char* name_cstr = GetAsArray<char>(
+      name_ref, 0, PersistentMemoryAllocator::kSizeAny, &name_length);
   if (!name_cstr)
     return "";
 
-  size_t name_length = GetAllocSize(name_ref);
   if (name_cstr[name_length - 1] != '\0') {
     NOTREACHED_IN_MIGRATION();
     SetCorrupt();
@@ -555,23 +565,6 @@ PersistentMemoryAllocator::Reference Per
   return ref;
 }
 
-size_t PersistentMemoryAllocator::GetAllocSize(Reference ref) const {
-  const volatile BlockHeader* const block = GetBlock(ref, 0, 0, false, false);
-  if (!block)
-    return 0;
-  uint32_t size = block->size;
-  // Header was verified by GetBlock() but a malicious actor could change
-  // the value between there and here. Check it again.
-  uint32_t total_size;
-  if (size <= sizeof(BlockHeader) ||
-      !base::CheckAdd(ref, size).AssignIfValid(&total_size) ||
-      total_size > mem_size_) {
-    SetCorrupt();
-    return 0;
-  }
-  return size - sizeof(BlockHeader);
-}
-
 uint32_t PersistentMemoryAllocator::GetType(Reference ref) const {
   const volatile BlockHeader* const block = GetBlock(ref, 0, 0, false, false);
   if (!block)
@@ -641,8 +634,9 @@ bool PersistentMemoryAllocator::ChangeTy
 
 PersistentMemoryAllocator::Reference PersistentMemoryAllocator::Allocate(
     size_t req_size,
-    uint32_t type_id) {
-  Reference ref = AllocateImpl(req_size, type_id);
+    uint32_t type_id,
+    size_t* alloc_size) {
+  Reference ref = AllocateImpl(req_size, type_id, alloc_size);
   if (ref) {
     // Success: Record this allocation in usage stats (if active).
     if (allocs_histogram_)
@@ -657,7 +651,8 @@ PersistentMemoryAllocator::Reference Per
 
 PersistentMemoryAllocator::Reference PersistentMemoryAllocator::AllocateImpl(
     size_t req_size,
-    uint32_t type_id) {
+    uint32_t type_id,
+    size_t* alloc_size) {
   DCHECK_NE(access_mode_, kReadOnly);
 
   // Validate req_size to ensure it won't overflow when used as 32-bit value.
@@ -820,6 +815,11 @@ PersistentMemoryAllocator::Reference Per
     block->size = static_cast<uint32_t>(size);
     block->cookie = kBlockCookieAllocated;
     block->type_id.store(type_id, std::memory_order_relaxed);
+
+    // Return the allocation size if requested.
+    if (alloc_size) {
+      *alloc_size = size - sizeof(BlockHeader);
+    }
     return freeptr;
   }
 }
@@ -932,17 +932,16 @@ bool PersistentMemoryAllocator::IsFull()
   return CheckFlag(&shared_meta()->flags, kFlagFull);
 }
 
-// Dereference a block |ref| and ensure that it's valid for the desired
-// |type_id| and |size|. |special| indicates that we may try to access block
-// headers not available to callers but still accessed by this module. By
-// having internal dereferences go through this same function, the allocator
-// is hardened against corruption.
 const volatile PersistentMemoryAllocator::BlockHeader*
 PersistentMemoryAllocator::GetBlock(Reference ref,
                                     uint32_t type_id,
                                     size_t size,
                                     bool queue_ok,
-                                    bool free_ok) const {
+                                    bool free_ok,
+                                    size_t* alloc_size) const {
+  // The caller cannot request `alloc_size` if `queue_ok` or `free_ok`.
+  CHECK(!(alloc_size && (queue_ok || free_ok)));
+
   // Handle special cases.
   if (ref == kReferenceQueue && queue_ok)
     return reinterpret_cast<const volatile BlockHeader*>(mem_base_ + ref);
@@ -961,29 +960,39 @@ PersistentMemoryAllocator::GetBlock(Refe
     return nullptr;
   }
 
+  const volatile BlockHeader* const block =
+      reinterpret_cast<volatile BlockHeader*>(mem_base_ + ref);
+
   // Validation of referenced block-header.
   if (!free_ok) {
-    const volatile BlockHeader* const block =
-        reinterpret_cast<volatile BlockHeader*>(mem_base_ + ref);
     if (block->cookie != kBlockCookieAllocated)
       return nullptr;
-    if (block->size < size)
+    const uint32_t block_size = block->size;
+    if (block_size < size) {
       return nullptr;
-    uint32_t block_size;
-    if (!base::CheckAdd(ref, block->size).AssignIfValid(&block_size)) {
+    }
+    // Find a validate the end of the block.
+    uint32_t block_end_ref;
+    if (!base::CheckAdd(ref, block_size).AssignIfValid(&block_end_ref)) {
       return nullptr;
     }
-    if (block_size > mem_size_) {
+    if (block_end_ref > mem_size_) {
+      // The end of the alloc extends beyond the allocator's bounds.
+      SetCorrupt();
       return nullptr;
     }
     if (type_id != 0 &&
         block->type_id.load(std::memory_order_relaxed) != type_id) {
       return nullptr;
     }
+    // Return `alloc_size` if requested by the caller.
+    if (alloc_size) {
+      *alloc_size = block_size - sizeof(BlockHeader);
+    }
   }
 
   // Return pointer to block data.
-  return reinterpret_cast<const volatile BlockHeader*>(mem_base_ + ref);
+  return block;
 }
 
 void PersistentMemoryAllocator::FlushPartial(size_t length, bool sync) {
@@ -1009,10 +1018,11 @@ uint32_t PersistentMemoryAllocator::vers
 const volatile void* PersistentMemoryAllocator::GetBlockData(
     Reference ref,
     uint32_t type_id,
-    size_t size) const {
+    size_t size,
+    size_t* alloc_size) const {
   DCHECK(size > 0);
   const volatile BlockHeader* block =
-      GetBlock(ref, type_id, size, false, false);
+      GetBlock(ref, type_id, size, false, false, alloc_size);
   if (!block)
     return nullptr;
   return reinterpret_cast<const volatile char*>(block) + sizeof(BlockHeader);
@@ -1191,14 +1201,14 @@ void FilePersistentMemoryAllocator::Cach
                                                 base::BlockingType::MAY_BLOCK);
 
   // Calculate begin/end addresses so that the first byte of every page
-  // in that range can be read. Keep within the used space. The |volatile|
+  // in that range can be read. Keep within the used space. The `volatile`
   // keyword makes it so the compiler can't make assumptions about what is
   // in a given memory location and thus possibly avoid the read.
   const volatile char* mem_end = mem_base_ + used();
   const volatile char* mem_begin = mem_base_;
 
   // Iterate over the memory a page at a time, reading the first byte of
-  // every page. The values are added to a |total| so that the compiler
+  // every page. The values are added to a `total` so that the compiler
   // can't omit the read.
   int total = 0;
   for (const volatile char* memory = mem_begin; memory < mem_end;
@@ -1206,7 +1216,7 @@ void FilePersistentMemoryAllocator::Cach
     total += *memory;
   }
 
-  // Tell the compiler that |total| is used so that it can't optimize away
+  // Tell the compiler that `total` is used so that it can't optimize away
   // the memory accesses above.
   debug::Alias(&total);
 }
@@ -1276,7 +1286,8 @@ span<uint8_t> DelayedPersistentAllocatio
 #endif  // !BUILDFLAG(IS_NACL)
 
   if (!ref) {
-    ref = allocator_->Allocate(size_, type_);
+    [[maybe_unused]] size_t alloc_size = 0;
+    ref = allocator_->Allocate(size_, type_, &alloc_size);
     if (!ref) {
       return span<uint8_t>();
     }
@@ -1292,7 +1303,7 @@ span<uint8_t> DelayedPersistentAllocatio
       // allocation, and stored its reference. Purge the allocation that was
       // just done and use the other one instead.
       DCHECK_EQ(type_, allocator_->GetType(existing));
-      DCHECK_LE(size_, allocator_->GetAllocSize(existing));
+      DCHECK_LE(size_, alloc_size);
       allocator_->ChangeType(ref, 0, type_, /*clear=*/false);
       ref = existing;
 #if !BUILDFLAG(IS_NACL)
@@ -1328,13 +1339,13 @@ span<uint8_t> DelayedPersistentAllocatio
     SCOPED_CRASH_KEY_NUMBER("PersistentMemoryAllocator", "size_", size_);
     if (ref == 0xC8799269) {
       // There are many crash reports containing the corrupted "0xC8799269"
-      // value in |ref|. This value is actually a "magic" number to indicate
+      // value in `ref`. This value is actually a "magic" number to indicate
       // that a certain block in persistent memory was successfully allocated,
       // so it should not appear there. Include some extra crash keys to see if
       // the surrounding values were also corrupted. If so, the value before
       // would be the size of the allocated object, and the value after would be
       // the type id of the allocated object. If they are not corrupted, these
-      // would contain |ranges_checksum| and the start of |samples_metadata|
+      // would contain `ranges_checksum` and the start of `samples_metadata`
       // respectively (see PersistentHistogramData struct). We do some pointer
       // arithmetic here -- it should theoretically be safe, unless something
       // went terribly wrong...
