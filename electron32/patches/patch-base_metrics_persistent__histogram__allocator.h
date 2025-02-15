$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/metrics/persistent_histogram_allocator.h.orig	2024-10-18 12:33:59.786263200 +0000
+++ base/metrics/persistent_histogram_allocator.h
@@ -47,8 +47,8 @@ class BASE_EXPORT PersistentSparseHistog
   ~PersistentSparseHistogramDataManager();
 
   // Returns an object that manages persistent-sample-map records for a given
-  // |id|. The returned object queries |this| for records. Hence, the returned
-  // object must not outlive |this|.
+  // `id`. The returned object queries `this` for records. Hence, the returned
+  // object must not outlive `this`.
   std::unique_ptr<PersistentSampleMapRecords> CreateSampleMapRecords(
       uint64_t id);
 
@@ -71,19 +71,19 @@ class BASE_EXPORT PersistentSparseHistog
   std::vector<ReferenceAndSample>* GetSampleMapRecordsWhileLocked(uint64_t id)
       EXCLUSIVE_LOCKS_REQUIRED(lock_);
 
-  // Returns sample-map records belonging to the specified |sample_map_records|.
-  // Only records found that were not yet seen by |sample_map_records| will be
-  // returned, determined by its |seen_| field. Records found for other
+  // Returns sample-map records belonging to the specified `sample_map_records`.
+  // Only records found that were not yet seen by `sample_map_records` will be
+  // returned, determined by its `seen_` field. Records found for other
   // sample-maps are held for later use without having to iterate again. This
   // should be called only from a PersistentSampleMapRecords object because
   // those objects have a contract that there are no other threads accessing the
-  // internal records_ field of the object that is passed in. If |until_value|
+  // internal records_ field of the object that is passed in. If `until_value`
   // is set and a sample is found with said value, the search will stop early
   // and the last entry in the returned vector will be that sample.
   // Note: The returned vector is not guaranteed to contain all unseen records
-  // for |sample_map_records|. If this is needed, then repeatedly call this
+  // for `sample_map_records`. If this is needed, then repeatedly call this
   // until an empty vector is returned, which definitely means that
-  // |sample_map_records| has seen all its records.
+  // `sample_map_records` has seen all its records.
   std::vector<PersistentMemoryAllocator::Reference> LoadRecords(
       PersistentSampleMapRecords* sample_map_records,
       std::optional<HistogramBase::Sample> until_value);
@@ -112,7 +112,7 @@ class BASE_EXPORT PersistentSampleMapRec
   // Constructs an instance of this class. The manager object must live longer
   // than all instances of this class that reference it, which is not usually
   // a problem since these objects are generally managed from within that
-  // manager instance. The same caveats apply for for the |records| vector.
+  // manager instance. The same caveats apply for for the `records` vector.
   PersistentSampleMapRecords(
       PersistentSparseHistogramDataManager* data_manager,
       uint64_t sample_map_id,
@@ -125,18 +125,18 @@ class BASE_EXPORT PersistentSampleMapRec
 
   ~PersistentSampleMapRecords();
 
-  // Gets next references to persistent sample-map records. If |until_value| is
+  // Gets next references to persistent sample-map records. If `until_value` is
   // passed, and said value is found, then it will be the last element in the
   // returned vector. The type and layout of the data being referenced is
   // defined entirely within the PersistentSampleMap class.
   // Note: The returned vector is not guaranteed to contain all unseen records
-  // for |this|. If this is needed, then repeatedly call this until an empty
-  // vector is returned, which definitely means that |this| has seen all its
+  // for `this`. If this is needed, then repeatedly call this until an empty
+  // vector is returned, which definitely means that `this` has seen all its
   // records.
   std::vector<PersistentMemoryAllocator::Reference> GetNextRecords(
       std::optional<HistogramBase::Sample> until_value);
 
-  // Creates a new persistent sample-map record for sample |value| and returns
+  // Creates a new persistent sample-map record for sample `value` and returns
   // a reference to it.
   PersistentMemoryAllocator::Reference CreateNew(HistogramBase::Sample value);
 
@@ -160,7 +160,7 @@ class BASE_EXPORT PersistentSampleMapRec
   // ID of PersistentSampleMap to which these records apply.
   const uint64_t sample_map_id_;
 
-  // This is the count of how many "records" have already been read by |this|.
+  // This is the count of how many "records" have already been read by `this`.
   size_t seen_ = 0;
 
   // This is the set of records found during iteration through memory, owned by
@@ -185,7 +185,7 @@ class BASE_EXPORT PersistentHistogramAll
   // See PersistentMemoryAllocator::Iterator for more information.
   class BASE_EXPORT Iterator {
    public:
-    // Constructs an iterator on a given |allocator|, starting at the beginning.
+    // Constructs an iterator on a given `allocator`, starting at the beginning.
     // The allocator must live beyond the lifetime of the iterator.
     explicit Iterator(PersistentHistogramAllocator* allocator);
 
@@ -198,7 +198,7 @@ class BASE_EXPORT PersistentHistogramAll
     std::unique_ptr<HistogramBase> GetNext() { return GetNextWithIgnore(0); }
 
     // Gets the next histogram from persistent memory, ignoring one particular
-    // reference in the process. Pass |ignore| of zero (0) to ignore nothing.
+    // reference in the process. Pass `ignore` of zero (0) to ignore nothing.
     std::unique_ptr<HistogramBase> GetNextWithIgnore(Reference ignore);
 
    private:
@@ -239,7 +239,7 @@ class BASE_EXPORT PersistentHistogramAll
 
   // Recreate a Histogram from data held in persistent memory. Though this
   // object will be local to the current process, the sample data will be
-  // shared with all other threads referencing it. This method takes a |ref|
+  // shared with all other threads referencing it. This method takes a `ref`
   // to where the top-level histogram data may be found in this allocator.
   // This method will return null if any problem is detected with the data.
   std::unique_ptr<HistogramBase> GetHistogram(Reference ref);
@@ -256,7 +256,7 @@ class BASE_EXPORT PersistentHistogramAll
       Reference* ref_ptr);
 
   // Finalize the creation of the histogram, making it available to other
-  // processes if |registered| (as in: added to the StatisticsRecorder) is
+  // processes if `registered` (as in: added to the StatisticsRecorder) is
   // True, forgetting it otherwise.
   void FinalizeHistogram(Reference ref, bool registered);
 
@@ -274,36 +274,36 @@ class BASE_EXPORT PersistentHistogramAll
       const HistogramBase* histogram);
 
   // Returns an object that manages persistent-sample-map records for a given
-  // |id|. The returned object queries |sparse_histogram_data_manager_| for
+  // `id`. The returned object queries `sparse_histogram_data_manager_` for
   // records. Hence, the returned object must not outlive
-  // |sparse_histogram_data_manager_| (and hence |this|).
+  // `sparse_histogram_data_manager_` (and hence `this`).
   std::unique_ptr<PersistentSampleMapRecords> CreateSampleMapRecords(
       uint64_t id);
 
   // Creates internal histograms for tracking memory use and allocation sizes
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
   void UpdateTrackingHistograms();
 
-  // Sets the internal |ranges_manager_|, which will be used by the allocator to
-  // register BucketRanges. Takes ownership of the passed |ranges_manager|.
+  // Sets the internal `ranges_manager_`, which will be used by the allocator to
+  // register BucketRanges. Takes ownership of the passed `ranges_manager`.
   //
-  // WARNING: Since histograms may be created from |this| from multiple threads,
+  // WARNING: Since histograms may be created from `this` from multiple threads,
   // for example through a direct call to CreateHistogram(), or while iterating
-  // through |this|, then the passed manager may also be accessed concurrently.
+  // through `this`, then the passed manager may also be accessed concurrently.
   // Hence, care must be taken to ensure that either:
   //   1) The passed manager is threadsafe (see ThreadSafeRangesManager), or
-  //   2) |this| is not used concurrently.
+  //   2) `this` is not used concurrently.
   void SetRangesManager(RangesManager* ranges_manager);
 
-  // Clears the internal |last_created_| reference so testing can validate
+  // Clears the internal `last_created_` reference so testing can validate
   // operation without that optimization.
   void ClearLastCreatedReferenceForTesting();
 
@@ -329,7 +329,7 @@ class BASE_EXPORT PersistentHistogramAll
       PersistentHistogramData* histogram_data_ptr);
 
   // Gets or creates an object in the global StatisticsRecorder matching
-  // the |histogram| passed. Null is returned if one was not found and
+  // the `histogram` passed. Null is returned if one was not found and
   // one could not be created.
   HistogramBase* GetOrCreateStatisticsRecorderHistogram(
       const HistogramBase* histogram);
@@ -365,7 +365,7 @@ class BASE_EXPORT GlobalHistogramAllocat
 
   ~GlobalHistogramAllocator() override;
 
-  // Create a global allocator using the passed-in memory |base|, |size|, and
+  // Create a global allocator using the passed-in memory `base`, `size`, and
   // other parameters. Ownership of the memory segment remains with the caller.
   static void CreateWithPersistentMemory(void* base,
                                          size_t size,
@@ -374,17 +374,17 @@ class BASE_EXPORT GlobalHistogramAllocat
                                          std::string_view name);
 
   // Create a global allocator using an internal block of memory of the
-  // specified |size| taken from the heap.
+  // specified `size` taken from the heap.
   static void CreateWithLocalMemory(size_t size,
                                     uint64_t id,
                                     std::string_view name);
 
 #if !BUILDFLAG(IS_NACL)
-  // Create a global allocator by memory-mapping a |file|. If the file does
-  // not exist, it will be created with the specified |size|. If the file does
+  // Create a global allocator by memory-mapping a `file`. If the file does
+  // not exist, it will be created with the specified `size`. If the file does
   // exist, the allocator will use and add to its contents, ignoring the passed
   // size in favor of the existing size. Returns whether the global allocator
-  // was set. If |exclusive_write| is true, the file will be opened in a mode
+  // was set. If `exclusive_write` is true, the file will be opened in a mode
   // that disallows multiple concurrent writers (no effect on non-Windows).
   static bool CreateWithFile(const FilePath& file_path,
                              size_t size,
@@ -392,9 +392,9 @@ class BASE_EXPORT GlobalHistogramAllocat
                              std::string_view name,
                              bool exclusive_write = false);
 
-  // Creates a new file at |active_path|. If it already exists, it will first be
-  // moved to |base_path|. In all cases, any old file at |base_path| will be
-  // removed. If |spare_path| is non-empty and exists, that will be renamed and
+  // Creates a new file at `active_path`. If it already exists, it will first be
+  // moved to `base_path`. In all cases, any old file at `base_path` will be
+  // removed. If `spare_path` is non-empty and exists, that will be renamed and
   // used as the active file. Otherwise, the file will be created using the
   // given size, id, and name. Returns whether the global allocator was set.
   static bool CreateWithActiveFile(const FilePath& base_path,
@@ -405,9 +405,9 @@ class BASE_EXPORT GlobalHistogramAllocat
                                    std::string_view name);
 
   // Uses ConstructBaseActivePairFilePaths() to build a pair of file names which
-  // are then used for CreateWithActiveFile(). |name| is used for both the
+  // are then used for CreateWithActiveFile(). `name` is used for both the
   // internal name for the allocator and also for the name of the file inside
-  // |dir|.
+  // `dir`.
   static bool CreateWithActiveFileInDir(const FilePath& dir,
                                         size_t size,
                                         uint64_t id,
@@ -442,7 +442,7 @@ class BASE_EXPORT GlobalHistogramAllocat
 #endif
 
   // Create a global allocator using a block of shared memory accessed
-  // through the given |region|. The allocator maps the shared memory into
+  // through the given `region`. The allocator maps the shared memory into
   // current process's virtual address space and frees it upon destruction.
   // The memory will continue to live if other processes have access to it.
   static void CreateWithSharedMemoryRegion(
@@ -481,7 +481,7 @@ class BASE_EXPORT GlobalHistogramAllocat
   bool HasPersistentLocation() const;
 
   // Moves the file being used to persist this allocator's data to the directory
-  // specified by |dir|. Returns whether the operation was successful.
+  // specified by `dir`. Returns whether the operation was successful.
   bool MovePersistentFile(const FilePath& dir);
 
   // Writes the internal data to a previously set location. This is generally
