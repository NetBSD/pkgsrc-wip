$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/metrics/persistent_memory_allocator.h.orig	2024-10-18 12:33:59.786263200 +0000
+++ base/metrics/persistent_memory_allocator.h
@@ -171,13 +171,13 @@ class BASE_EXPORT PersistentMemoryAlloca
   // eventually quit.
   class BASE_EXPORT Iterator {
    public:
-    // Constructs an iterator on a given |allocator|, starting at the beginning.
+    // Constructs an iterator on a given `allocator`, starting at the beginning.
     // The allocator must live beyond the lifetime of the iterator. This class
     // has read-only access to the allocator (hence "const") but the returned
     // references can be used on a read/write version, too.
     explicit Iterator(const PersistentMemoryAllocator* allocator);
 
-    // As above but resuming from the |starting_after| reference. The first call
+    // As above but resuming from the `starting_after` reference. The first call
     // to GetNext() will return the next object found after that reference. The
     // reference must be to an "iterable" object; references to non-iterable
     // objects (those that never had MakeIterable() called for them) will cause
@@ -193,7 +193,7 @@ class BASE_EXPORT PersistentMemoryAlloca
     // Resets the iterator back to the beginning.
     void Reset();
 
-    // Resets the iterator, resuming from the |starting_after| reference.
+    // Resets the iterator, resuming from the `starting_after` reference.
     void Reset(Reference starting_after);
 
     // Returns the previously retrieved reference, or kReferenceNull if none.
@@ -201,17 +201,17 @@ class BASE_EXPORT PersistentMemoryAlloca
     // that value.
     Reference GetLast();
 
-    // Gets the next iterable, storing that type in |type_return|. The actual
+    // Gets the next iterable, storing that type in `type_return`. The actual
     // return value is a reference to the allocation inside the allocator or
     // zero if there are no more. GetNext() may still be called again at a
     // later time to retrieve any new allocations that have been added.
-    Reference GetNext(uint32_t* type_return);
+    Reference GetNext(uint32_t* type_return, size_t* alloc_size = nullptr);
 
-    // Similar to above but gets the next iterable of a specific |type_match|.
+    // Similar to above but gets the next iterable of a specific `type_match`.
     // This should not be mixed with calls to GetNext() because any allocations
     // skipped here due to a type mis-match will never be returned by later
     // calls to GetNext() meaning it's possible to completely miss entries.
-    Reference GetNextOfType(uint32_t type_match);
+    Reference GetNextOfType(uint32_t type_match, size_t* alloc_size = nullptr);
 
     // As above but works using object type.
     template <typename T>
@@ -244,8 +244,8 @@ class BASE_EXPORT PersistentMemoryAlloca
     }
 
     // Convert a generic pointer back into a reference. A null reference will
-    // be returned if |memory| is not inside the persistent segment or does not
-    // point to an object of the specified |type_id|.
+    // be returned if `memory` is not inside the persistent segment or does not
+    // point to an object of the specified `type_id`.
     Reference GetAsReference(const void* memory, uint32_t type_id) const {
       return allocator_->GetAsReference(memory, type_id);
     }
@@ -308,12 +308,12 @@ class BASE_EXPORT PersistentMemoryAlloca
   // The allocator operates on any arbitrary block of memory. Creation and
   // persisting or sharing of that block with another process is the
   // responsibility of the caller. The allocator needs to know only the
-  // block's |base| address, the total |size| of the block, and any internal
-  // |page| size (zero if not paged) across which allocations should not span.
-  // The |id| is an arbitrary value the caller can use to identify a
+  // block's `base` address, the total `size` of the block, and any internal
+  // `page` size (zero if not paged) across which allocations should not span.
+  // The `id` is an arbitrary value the caller can use to identify a
   // particular memory segment. It will only be loaded during the initial
   // creation of the segment and can be checked by the caller for consistency.
-  // The |name|, if provided, is used to distinguish histograms for this
+  // The `name`, if provided, is used to distinguish histograms for this
   // allocator. Only the primary owner of the segment should define this value;
   // other processes can learn it from the shared state. If the access mode
   // is kReadOnly then no changes will be made to it. The resulting object
@@ -367,12 +367,12 @@ class BASE_EXPORT PersistentMemoryAlloca
   uint8_t GetMemoryState() const;
 
   // Create internal histograms for tracking memory use and allocation sizes
-  // for allocator of |name| (which can simply be the result of Name()). This
-  // is done seperately from construction for situations such as when the
+  // for allocator of `name` (which can simply be the result of Name()). This
+  // is done separately from construction for situations such as when the
   // histograms will be backed by memory provided by this very allocator.
   //
   // IMPORTANT: tools/metrics/histograms/metadata/uma/histograms.xml must
-  // be updated with the following histograms for each |name| param:
+  // be updated with the following histograms for each `name` param:
   //    UMA.PersistentAllocator.name.Errors
   //    UMA.PersistentAllocator.name.UsedPct
   void CreateTrackingHistograms(std::string_view name);
@@ -382,13 +382,13 @@ class BASE_EXPORT PersistentMemoryAlloca
   // OS that all the data should be sent to the disk immediately. This is
   // useful in the rare case where something has just been stored that needs
   // to survive a hard shutdown of the machine like from a power failure.
-  // The |sync| parameter indicates if this call should block until the flush
+  // The `sync` parameter indicates if this call should block until the flush
   // is complete but is only advisory and may or may not have an effect
   // depending on the capabilities of the OS. Synchronous flushes are allowed
-  // only from threads that are allowed to do I/O but since |sync| is only
+  // only from threads that are allowed to do I/O but since `sync` is only
   // advisory, all flushes should be done on IO-capable threads.
-  // TODO: Since |sync| is ignored on Windows, consider making it re-post on a
-  // background thread with |sync| set to true so that |sync| is not just
+  // TODO: Since `sync` is ignored on Windows, consider making it re-post on a
+  // background thread with `sync` set to true so that `sync` is not just
   // advisory.
   void Flush(bool sync);
 
@@ -400,9 +400,9 @@ class BASE_EXPORT PersistentMemoryAlloca
   size_t size() const { return mem_size_; }
   size_t used() const;
 
-  // Get an object referenced by a |ref|. For safety reasons, the |type_id|
-  // code and size-of(|T|) are compared to ensure the reference is valid
-  // and cannot return an object outside of the memory segment. A |type_id| of
+  // Get an object referenced by a `ref`. For safety reasons, the `type_id`
+  // code and size-of(`T`) are compared to ensure the reference is valid
+  // and cannot return an object outside of the memory segment. A `type_id` of
   // kTypeIdAny (zero) will match any though the size is still checked. NULL is
   // returned if any problem is detected, such as corrupted storage or incorrect
   // parameters. Callers MUST check that the returned value is not-null EVERY
@@ -422,7 +422,7 @@ class BASE_EXPORT PersistentMemoryAlloca
   // largest architecture, including at the end.
   //
   // To protected against mistakes, all objects must have the attribute
-  // |kExpectedInstanceSize| (static constexpr size_t)  that is a hard-coded
+  // `kExpectedInstanceSize` (static constexpr size_t)  that is a hard-coded
   // numerical value -- NNN, not sizeof(T) -- that can be tested. If the
   // instance size is not fixed, at least one build will fail.
   //
@@ -442,27 +442,28 @@ class BASE_EXPORT PersistentMemoryAlloca
   // nature of that keyword to the caller. It can add it back, if necessary,
   // based on knowledge of how the allocator is being used.
   template <typename T>
-  T* GetAsObject(Reference ref) {
+  T* GetAsObject(Reference ref, size_t* alloc_size = nullptr) {
     static_assert(std::is_standard_layout_v<T>, "only standard objects");
     static_assert(!std::is_array_v<T>, "use GetAsArray<>()");
     static_assert(T::kExpectedInstanceSize == sizeof(T), "inconsistent size");
     return const_cast<T*>(reinterpret_cast<volatile T*>(
-        GetBlockData(ref, T::kPersistentTypeId, sizeof(T))));
+        GetBlockData(ref, T::kPersistentTypeId, sizeof(T), alloc_size)));
   }
   template <typename T>
-  const T* GetAsObject(Reference ref) const {
+  const T* GetAsObject(Reference ref, size_t* alloc_size = nullptr) const {
     static_assert(std::is_standard_layout_v<T>, "only standard objects");
     static_assert(!std::is_array_v<T>, "use GetAsArray<>()");
     static_assert(T::kExpectedInstanceSize == sizeof(T), "inconsistent size");
     return const_cast<const T*>(reinterpret_cast<const volatile T*>(
-        GetBlockData(ref, T::kPersistentTypeId, sizeof(T))));
+        GetBlockData(ref, T::kPersistentTypeId, sizeof(T), alloc_size)));
   }
 
-  // Like GetAsObject but get an array of simple, fixed-size types.
+  // Like GetAsObject() but get an array of simple, fixed-size types.
   //
-  // Use a |count| of the required number of array elements, or kSizeAny.
-  // GetAllocSize() can be used to calculate the upper bound but isn't reliable
-  // because padding can make space for extra elements that were not written.
+  // Use a `count` of the required number of array elements, or kSizeAny.
+  // The, optionally returned, `alloc_size` can be used to calculate the upper
+  // bound but isn't reliable because padding can make space for extra elements
+  // that were not written.
   //
   // Remember that an array of char is a string but may not be NUL terminated.
   //
@@ -470,29 +471,29 @@ class BASE_EXPORT PersistentMemoryAlloca
   // compatibilty when using these accessors. Only use fixed-size types such
   // as char, float, double, or (u)intXX_t.
   template <typename T>
-  T* GetAsArray(Reference ref, uint32_t type_id, size_t count) {
+  T* GetAsArray(Reference ref,
+                uint32_t type_id,
+                size_t count,
+                size_t* alloc_size = nullptr) {
     static_assert(std::is_fundamental_v<T>, "use GetAsObject<>()");
     return const_cast<T*>(reinterpret_cast<volatile T*>(
-        GetBlockData(ref, type_id, count * sizeof(T))));
+        GetBlockData(ref, type_id, count * sizeof(T), alloc_size)));
   }
   template <typename T>
-  const T* GetAsArray(Reference ref, uint32_t type_id, size_t count) const {
+  const T* GetAsArray(Reference ref,
+                      uint32_t type_id,
+                      size_t count,
+                      size_t* alloc_size = nullptr) const {
     static_assert(std::is_fundamental_v<T>, "use GetAsObject<>()");
     return const_cast<const char*>(reinterpret_cast<const volatile T*>(
-        GetBlockData(ref, type_id, count * sizeof(T))));
+        GetBlockData(ref, type_id, count * sizeof(T), alloc_size)));
   }
 
   // Get the corresponding reference for an object held in persistent memory.
-  // If the |memory| is not valid or the type does not match, a kReferenceNull
+  // If the `memory` is not valid or the type does not match, a kReferenceNull
   // result will be returned.
   Reference GetAsReference(const void* memory, uint32_t type_id) const;
 
-  // Get the number of bytes allocated to a block. This is useful when storing
-  // arrays in order to validate the ending boundary. The returned value will
-  // include any padding added to achieve the required alignment and so could
-  // be larger than given in the original Allocate() request.
-  size_t GetAllocSize(Reference ref) const;
-
   // Access the internal "type" of an object. This generally isn't necessary
   // but can be used to "clear" the type and so effectively mark it as deleted
   // even though the memory stays valid and allocated. Changing the type is
@@ -500,8 +501,8 @@ class BASE_EXPORT PersistentMemoryAlloca
   // It will return false if the existing type is not what is expected.
   //
   // Changing the type doesn't mean the data is compatible with the new type.
-  // Passing true for |clear| will zero the memory after the type has been
-  // changed away from |from_type_id| but before it becomes |to_type_id| meaning
+  // Passing true for `clear` will zero the memory after the type has been
+  // changed away from `from_type_id` but before it becomes `to_type_id` meaning
   // that it is done in a manner that is thread-safe. Memory is guaranteed to
   // be zeroed atomically by machine-word in a monotonically increasing order.
   //
@@ -553,13 +554,15 @@ class BASE_EXPORT PersistentMemoryAlloca
   // While the above works much like malloc & free, these next methods provide
   // an "object" interface similar to new and delete.
 
-  // Reserve space in the memory segment of the desired |size| and |type_id|.
+  // Reserve space in the memory segment of the desired `size` and `type_id`.
   //
   // A return value of zero indicates the allocation failed, otherwise the
   // returned reference can be used by any process to get a real pointer via
-  // the GetAsObject() or GetAsArray calls. The actual allocated size may be
+  // the GetAsObject() or GetAsArray() calls. The actual allocated size may be
   // larger and will always be a multiple of 8 bytes (64 bits).
-  Reference Allocate(size_t size, uint32_t type_id);
+  Reference Allocate(size_t size,
+                     uint32_t type_id,
+                     size_t* alloc_size = nullptr);
 
   // Allocate and construct an object in persistent memory. The type must have
   // both (size_t) kExpectedInstanceSize and (uint32_t) kPersistentTypeId
@@ -586,7 +589,7 @@ class BASE_EXPORT PersistentMemoryAlloca
   }
 
   // Similar to New, above, but construct the object out of an existing memory
-  // block and of an expected type. If |clear| is true, memory will be zeroed
+  // block and of an expected type. If `clear` is true, memory will be zeroed
   // before construction. Though this is not standard object behavior, it
   // is present to match with new allocations that always come from zeroed
   // memory. Anything previously present simply ceases to exist; no destructor
@@ -596,13 +599,16 @@ class BASE_EXPORT PersistentMemoryAlloca
   // results. USE WITH CARE!
   template <typename T>
   T* New(Reference ref, uint32_t from_type_id, bool clear) {
-    DCHECK_LE(sizeof(T), GetAllocSize(ref)) << "alloc not big enough for obj";
     // Make sure the memory is appropriate. This won't be used until after
     // the type is changed but checking first avoids the possibility of having
     // to change the type back.
-    void* mem = const_cast<void*>(GetBlockData(ref, 0, sizeof(T)));
+    size_t alloc_size = 0;
+    void* mem = const_cast<void*>(GetBlockData(ref, 0, sizeof(T), &alloc_size));
     if (!mem)
       return nullptr;
+
+    DCHECK_LE(sizeof(T), alloc_size) << "alloc not big enough for obj";
+
     // Ensure the allocator's internal alignment is sufficient for this object.
     // This protects against coding errors in the allocator.
     DCHECK_EQ(0U, reinterpret_cast<uintptr_t>(mem) & (alignof(T) - 1));
@@ -633,7 +639,7 @@ class BASE_EXPORT PersistentMemoryAlloca
     // First change the type to "transitioning" so there is no race condition
     // where another thread could find the object through iteration while it
     // is been destructed. This will "acquire" the memory so no changes get
-    // reordered before it. It will fail if |ref| is invalid.
+    // reordered before it. It will fail if `ref` is invalid.
     if (!ChangeType(ref, kTypeIdTransitioning, T::kPersistentTypeId, false))
       return;
     // Destruct the object.
@@ -677,7 +683,7 @@ class BASE_EXPORT PersistentMemoryAlloca
   };
 
   // Constructs the allocator. Everything is the same as the public allocator
-  // except |memory| which is a structure with additional information besides
+  // except `memory` which is a structure with additional information besides
   // the base address.
   PersistentMemoryAllocator(Memory memory,
                             size_t size,
@@ -715,32 +721,52 @@ class BASE_EXPORT PersistentMemoryAlloca
   }
 
   // Actual method for doing the allocation.
-  Reference AllocateImpl(size_t size, uint32_t type_id);
+  Reference AllocateImpl(size_t size, uint32_t type_id, size_t* alloc_size);
 
-  // Gets the block header associated with a specific reference.
+  // Dereferences a block `ref` to retrieve a pointer to the block header for
+  // the reference. This method ensures that the referenced block is valid for
+  // the desired `type_id` and `size`. Optionally, if `alloc_sizes` is not
+  // nullptr, the validated size of the underlying allocation is returned.
+  //
+  // Special cases for internal use only:
+  //
+  // * If `queue_ok` is true and `ref` is kReferenceQueueindicates then the
+  //   block header for the allocation queue is returned.
+  //
+  // * if `free_ok` then the block header is allowed to point to a block that
+  //   may not be in the `allocated` state. This bypasses block validation.
+  //
+  // Because they bypass block valoidation, it is not premitted to request the
+  // `alloc_size` when either of `queue_ok` or `free_ok` are true.
   const volatile BlockHeader* GetBlock(Reference ref,
                                        uint32_t type_id,
                                        size_t size,
                                        bool queue_ok,
-                                       bool free_ok) const;
+                                       bool free_ok,
+                                       size_t* alloc_size = nullptr) const;
   volatile BlockHeader* GetBlock(Reference ref,
                                  uint32_t type_id,
                                  size_t size,
                                  bool queue_ok,
-                                 bool free_ok) {
+                                 bool free_ok,
+                                 size_t* alloc_size = nullptr) {
     return const_cast<volatile BlockHeader*>(
         const_cast<const PersistentMemoryAllocator*>(this)->GetBlock(
-            ref, type_id, size, queue_ok, free_ok));
+            ref, type_id, size, queue_ok, free_ok, alloc_size));
   }
 
   // Gets the actual data within a block associated with a specific reference.
   const volatile void* GetBlockData(Reference ref,
                                     uint32_t type_id,
-                                    size_t size) const;
-  volatile void* GetBlockData(Reference ref, uint32_t type_id, size_t size) {
+                                    size_t size,
+                                    size_t* alloc_size = nullptr) const;
+  volatile void* GetBlockData(Reference ref,
+                              uint32_t type_id,
+                              size_t size,
+                              size_t* alloc_size = nullptr) {
     return const_cast<volatile void*>(
         const_cast<const PersistentMemoryAllocator*>(this)->GetBlockData(
-            ref, type_id, size));
+            ref, type_id, size, alloc_size));
   }
 
   // Records an error in the internal histogram.
@@ -792,12 +818,12 @@ class BASE_EXPORT LocalPersistentMemoryA
   ~LocalPersistentMemoryAllocator() override;
 
  private:
-  // Allocates a block of local memory of the specified |size|, ensuring that
+  // Allocates a block of local memory of the specified `size`, ensuring that
   // the memory will not be physically allocated until accessed and will read
   // as zero when that happens.
   static Memory AllocateLocalMemory(size_t size, std::string_view name);
 
-  // Deallocates a block of local |memory| of the specified |size|.
+  // Deallocates a block of local `memory` of the specified `size`.
   static void DeallocateLocalMemory(void* memory, size_t size, MemoryType type);
 };
 
@@ -865,8 +891,8 @@ class BASE_EXPORT ReadOnlySharedPersiste
 class BASE_EXPORT FilePersistentMemoryAllocator
     : public PersistentMemoryAllocator {
  public:
-  // A |max_size| of zero will use the length of the file as the maximum
-  // size. The |file| object must have been already created with sufficient
+  // A `max_size` of zero will use the length of the file as the maximum
+  // size. The `file` object must have been already created with sufficient
   // permissions (read, read/write, or read/write/extend).
   FilePersistentMemoryAllocator(std::unique_ptr<MemoryMappedFile> file,
                                 size_t max_size,
@@ -916,18 +942,18 @@ class BASE_EXPORT DelayedPersistentAlloc
  public:
   using Reference = PersistentMemoryAllocator::Reference;
 
-  // Creates a delayed allocation using the specified |allocator|. When
-  // needed, the memory will be allocated using the specified |type| and
-  // |size|. If |offset| is given, the returned pointer will be at that
+  // Creates a delayed allocation using the specified `allocator`. When
+  // needed, the memory will be allocated using the specified `type` and
+  // `size`. If `offset` is given, the returned pointer will be at that
   // offset into the segment; this allows combining allocations into a
   // single persistent segment to reduce overhead and means an "all or
-  // nothing" request. Note that |size| is always the total memory size
-  // and |offset| is just indicating the start of a block within it.
+  // nothing" request. Note that `size` is always the total memory size
+  // and `offset` is just indicating the start of a block within it.
   //
-  // Once allocated, a reference to the segment will be stored at |ref|.
+  // Once allocated, a reference to the segment will be stored at `ref`.
   // This shared location must be initialized to zero (0); it is checked
   // with every Get() request to see if the allocation has already been
-  // done. If reading |ref| outside of this object, be sure to do an
+  // done. If reading `ref` outside of this object, be sure to do an
   // "acquire" load. Don't write to it -- leave that to this object.
   DelayedPersistentAllocation(PersistentMemoryAllocator* allocator,
                               std::atomic<Reference>* ref,
