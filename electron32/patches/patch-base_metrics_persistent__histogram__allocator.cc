$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/metrics/persistent_histogram_allocator.cc.orig	2024-10-18 12:33:59.786263200 +0000
+++ base/metrics/persistent_histogram_allocator.cc
@@ -89,13 +89,13 @@ std::unique_ptr<BucketRanges> CreateRang
 }
 
 // Calculate the number of bytes required to store all of a histogram's
-// "counts". This will return zero (0) if |bucket_count| is not valid.
+// "counts". This will return zero (0) if `bucket_count` is not valid.
 size_t CalculateRequiredCountsBytes(size_t bucket_count) {
   // 2 because each "sample count" also requires a backup "logged count"
   // used for calculating the delta during snapshot operations.
   const size_t kBytesPerBucket = 2 * sizeof(HistogramBase::AtomicCount);
 
-  // If the |bucket_count| is such that it would overflow the return type,
+  // If the `bucket_count` is such that it would overflow the return type,
   // perhaps as the result of a malicious actor, then return zero to
   // indicate the problem to the caller.
   if (bucket_count > std::numeric_limits<size_t>::max() / kBytesPerBucket)
@@ -190,7 +190,7 @@ std::vector<PersistentMemoryAllocator::R
 PersistentSparseHistogramDataManager::LoadRecords(
     PersistentSampleMapRecords* sample_map_records,
     std::optional<HistogramBase::Sample> until_value) {
-  // DataManager must be locked in order to access the |sample_records_|
+  // DataManager must be locked in order to access the `sample_records_`
   // vectors.
   base::AutoLock auto_lock(lock_);
 
@@ -236,7 +236,7 @@ PersistentSparseHistogramDataManager::Lo
   }
 
   // Return all references found that have not yet been seen by
-  // |sample_map_records|, up until |until_value| (if applicable).
+  // `sample_map_records`, up until `until_value` (if applicable).
   std::vector<PersistentMemoryAllocator::Reference> new_references;
   CHECK_GE(found_records.size(), sample_map_records->seen_);
   auto new_found_records = base::make_span(found_records)
@@ -244,9 +244,9 @@ PersistentSparseHistogramDataManager::Lo
   new_references.reserve(new_found_records.size());
   for (const auto& new_record : new_found_records) {
     new_references.push_back(new_record.reference);
-    // Maybe references after |until_value| were found. Stop here immediately in
+    // Maybe references after `until_value` were found. Stop here immediately in
     // such a case, since the caller will not expect any more samples after
-    // |until_value|.
+    // `until_value`.
     if (until_value.has_value() && new_record.value == until_value.value()) {
       break;
     }
@@ -335,9 +335,9 @@ std::unique_ptr<HistogramBase> Persisten
   // count data (while these must reference the persistent counts) and always
   // add it to the local list of known histograms (while these may be simple
   // references to histograms in other processes).
+  size_t length = 0;
   PersistentHistogramData* data =
-      memory_allocator_->GetAsObject<PersistentHistogramData>(ref);
-  const size_t length = memory_allocator_->GetAllocSize(ref);
+      memory_allocator_->GetAsObject<PersistentHistogramData>(ref, &length);
 
   // Check that metadata is reasonable: name is null-terminated and non-empty,
   // ID fields have been loaded with a hash of the name (0 is considered
@@ -345,7 +345,7 @@ std::unique_ptr<HistogramBase> Persisten
   if (!data || data->name[0] == '\0' ||
       reinterpret_cast<char*>(data)[length - 1] != '\0' ||
       data->samples_metadata.id == 0 || data->logged_metadata.id == 0 ||
-      // Note: Sparse histograms use |id + 1| in |logged_metadata|.
+      // Note: Sparse histograms use `id + 1` in `logged_metadata`.
       (data->logged_metadata.id != data->samples_metadata.id &&
        data->logged_metadata.id != data->samples_metadata.id + 1) ||
       // Most non-matching values happen due to truncated names. Ideally, we
@@ -388,7 +388,7 @@ std::unique_ptr<HistogramBase> Persisten
     histogram_data->histogram_type = histogram_type;
     histogram_data->flags = flags | HistogramBase::kIsPersistent;
 
-    // |counts_ref| relies on being zero'd out initially. Even though this
+    // `counts_ref` relies on being zero'd out initially. Even though this
     // should always be the case, manually zero it out again here in case there
     // was memory corruption (e.g. if the memory was mapped from a corrupted
     // spare file).
@@ -402,7 +402,7 @@ std::unique_ptr<HistogramBase> Persisten
     size_t bucket_count = bucket_ranges->bucket_count();
     size_t counts_bytes = CalculateRequiredCountsBytes(bucket_count);
     if (counts_bytes == 0) {
-      // |bucket_count| was out-of-range.
+      // `bucket_count` was out-of-range.
       return nullptr;
     }
 
@@ -410,8 +410,8 @@ std::unique_ptr<HistogramBase> Persisten
     // objects for re-use, it would be dangerous for one to hold a reference
     // from a persistent allocator that is not the global one (which is
     // permanent once set). If this stops being the case, this check can
-    // become an "if" condition beside "!ranges_ref" below and before
-    // set_persistent_reference() farther down.
+    // become an `if` condition beside `!ranges_ref` below and before
+    // `set_persistent_reference()` farther down.
     DCHECK_EQ(this, GlobalHistogramAllocator::Get());
 
     // Re-use an existing BucketRanges persistent allocation if one is known;
@@ -448,7 +448,7 @@ std::unique_ptr<HistogramBase> Persisten
     if (ranges_ref && histogram_data) {
       histogram_data->minimum = minimum;
       histogram_data->maximum = maximum;
-      // |bucket_count| must fit within 32-bits or the allocation of the counts
+      // `bucket_count` must fit within 32-bits or the allocation of the counts
       // array would have failed for being too large; the allocator supports
       // less than 4GB total size.
       histogram_data->bucket_count = static_cast<uint32_t>(bucket_count);
@@ -461,7 +461,7 @@ std::unique_ptr<HistogramBase> Persisten
 
   if (histogram_data) {
     // Create the histogram using resources in persistent memory. This ends up
-    // resolving the "ref" values stored in histogram_data instad of just
+    // resolving the `ref` values stored in histogram_data instead of just
     // using what is already known above but avoids duplicating the switch
     // statement here and serves as a double-check that everything is
     // correct before commiting the new histogram to persistent space.
@@ -600,17 +600,16 @@ std::unique_ptr<HistogramBase> Persisten
   uint32_t histogram_ranges_ref = histogram_data_ptr->ranges_ref;
   uint32_t histogram_ranges_checksum = histogram_data_ptr->ranges_checksum;
 
+  size_t allocated_bytes = 0;
   HistogramBase::Sample* ranges_data =
       memory_allocator_->GetAsArray<HistogramBase::Sample>(
           histogram_ranges_ref, kTypeIdRangesArray,
-          PersistentMemoryAllocator::kSizeAny);
+          PersistentMemoryAllocator::kSizeAny, &allocated_bytes);
 
   const uint32_t max_buckets =
       std::numeric_limits<uint32_t>::max() / sizeof(HistogramBase::Sample);
   size_t required_bytes =
       (histogram_bucket_count + 1) * sizeof(HistogramBase::Sample);
-  size_t allocated_bytes =
-      memory_allocator_->GetAllocSize(histogram_ranges_ref);
   if (!ranges_data || histogram_bucket_count < 2 ||
       histogram_bucket_count >= max_buckets ||
       allocated_bytes < required_bytes) {
@@ -638,11 +637,14 @@ std::unique_ptr<HistogramBase> Persisten
   }
 
   size_t counts_bytes = CalculateRequiredCountsBytes(histogram_bucket_count);
+  if (counts_bytes == 0) {
+    return nullptr;
+  }
+
   PersistentMemoryAllocator::Reference counts_ref =
       histogram_data_ptr->counts_ref.load(std::memory_order_acquire);
-  if (counts_bytes == 0 ||
-      (counts_ref != 0 &&
-       memory_allocator_->GetAllocSize(counts_ref) < counts_bytes)) {
+  if (counts_ref != 0 && !memory_allocator_->GetAsArray<uint8_t>(
+                             counts_ref, kTypeIdCountsArray, counts_bytes)) {
     return nullptr;
   }
 
@@ -970,7 +972,7 @@ void GlobalHistogramAllocator::Set(Globa
   // histogram allocator was initialized.
   //
   // TODO(crbug.com/40945497): CHECK(histogram_count == 0) and remove emit of
-  // early histogram count once |histogram_count| is reliably zero (0) for all
+  // early histogram count once `histogram_count` is reliably zero (0) for all
   // process types.
   size_t histogram_count = StatisticsRecorder::GetHistogramCount();
   if (histogram_count != 0) {
