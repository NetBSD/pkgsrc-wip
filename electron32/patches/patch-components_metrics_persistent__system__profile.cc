$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/metrics/persistent_system_profile.cc.orig	2024-10-18 12:34:06.882349300 +0000
+++ components/metrics/persistent_system_profile.cc
@@ -104,7 +104,7 @@ bool PersistentSystemProfile::RecordAllo
       if (!AddSegment(remaining_size))
         return false;
     }
-    // Write out as much of the data as possible. |data| and |remaining_size|
+    // Write out as much of the data as possible. `data` and `remaining_size`
     // are updated in place.
     if (!WriteData(type, &data, &remaining_size))
       return false;
@@ -147,8 +147,7 @@ bool PersistentSystemProfile::RecordAllo
 
 bool PersistentSystemProfile::RecordAllocator::NextSegment() const {
   base::PersistentMemoryAllocator::Iterator iter(allocator_, alloc_reference_);
-  alloc_reference_ = iter.GetNextOfType(kTypeIdSystemProfile);
-  alloc_size_ = allocator_->GetAllocSize(alloc_reference_);
+  alloc_reference_ = iter.GetNextOfType(kTypeIdSystemProfile, &alloc_size_);
   end_offset_ = 0;
   return alloc_reference_ != 0;
 }
@@ -169,13 +168,15 @@ bool PersistentSystemProfile::RecordAllo
   size_t size =
       std::max(CalculateRecordSize(min_size), kSystemProfileAllocSize);
 
-  uint32_t ref = allocator_->Allocate(size, kTypeIdSystemProfile);
+  size_t new_alloc_size = 0;
+  uint32_t ref =
+      allocator_->Allocate(size, kTypeIdSystemProfile, &new_alloc_size);
   if (!ref)
     return false;  // Allocator must be full.
   allocator_->MakeIterable(ref);
 
   alloc_reference_ = ref;
-  alloc_size_ = allocator_->GetAllocSize(ref);
+  alloc_size_ = new_alloc_size;
   return true;
 }
 
@@ -284,7 +285,7 @@ void PersistentSystemProfile::RegisterPe
     base::PersistentMemoryAllocator* memory_allocator) {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
 
-  // Create and store the allocator. A |min_size| of "1" ensures that a memory
+  // Create and store the allocator. A `min_size` of "1" ensures that a memory
   // block is reserved now.
   RecordAllocator allocator(memory_allocator, 1);
   allocators_.push_back(std::move(allocator));
