$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/metrics/field_trial.cc.orig	2024-10-18 12:33:59.782265400 +0000
+++ base/metrics/field_trial.cc
@@ -124,7 +124,7 @@ void PickleFieldTrial(const FieldTrial::
 }
 
 // Returns the boundary value for comparing against the FieldTrial's added
-// groups for a given |divisor| (total probability) and |entropy_value|.
+// groups for a given `divisor` (total probability) and `entropy_value`.
 FieldTrial::Probability GetGroupBoundaryValue(
     FieldTrial::Probability divisor,
     double entropy_value) {
@@ -138,7 +138,7 @@ FieldTrial::Probability GetGroupBoundary
   const double kEpsilon = 1e-8;
   const FieldTrial::Probability result =
       static_cast<FieldTrial::Probability>(divisor * entropy_value + kEpsilon);
-  // Ensure that adding the epsilon still results in a value < |divisor|.
+  // Ensure that adding the epsilon still results in a value < `divisor`.
   return std::min(result, divisor - 1);
 }
 
@@ -259,7 +259,7 @@ void FieldTrial::AppendGroup(const std::
   if (forced_) {
     DCHECK(!group_name_.empty());
     if (name == group_name_) {
-      // Note that while |group_| may be equal to |kDefaultGroupNumber| on the
+      // Note that while `group_` may be equal to `kDefaultGroupNumber` on the
       // forced trial, it will not have the same value as the default group
       // number returned from the non-forced |FactoryGetFieldTrial()| call,
       // which takes care to ensure that this does not happen.
@@ -326,7 +326,7 @@ bool FieldTrial::IsOverridden() const {
 void FieldTrial::EnableBenchmarking() {
   // We don't need to see field trials created via CreateFieldTrial() for
   // benchmarking, because such field trials have only a single group and are
-  // not affected by randomization that |enable_benchmarking_| would disable.
+  // not affected by randomization that `enable_benchmarking_` would disable.
   DCHECK_EQ(0u, FieldTrialList::GetRandomizedFieldTrialCount());
   enable_benchmarking_ = true;
 }
@@ -453,7 +453,7 @@ void FieldTrial::FinalizeGroupChoice() {
   if (group_ != kNotFinalized)
     return;
   accumulated_group_probability_ = divisor_;
-  // Here it's OK to use |kDefaultGroupNumber| since we can't be forced and not
+  // Here it's OK to use `kDefaultGroupNumber` since we can't be forced and not
   // finalized.
   DCHECK(!forced_);
   SetGroupChoice(default_group_name_, kDefaultGroupNumber);
@@ -807,7 +807,7 @@ FieldTrial* FieldTrialList::CreateFieldT
   field_trial = new FieldTrial(name, kTotalProbability, group_name, 0,
                                is_low_anonymity, is_overridden);
   // The group choice will be finalized in this method. So
-  // |is_randomized_trial| should be false.
+  // `is_randomized_trial` should be false.
   FieldTrialList::Register(field_trial, /*is_randomized_trial=*/false);
   // Force the trial, which will also finalize the group choice.
   field_trial->SetForced();
@@ -910,12 +910,12 @@ bool FieldTrialList::GetParamsFromShared
   if (!field_trial->ref_)
     return false;
 
+  size_t allocated_size = 0;
   const FieldTrial::FieldTrialEntry* entry =
       global_->field_trial_allocator_->GetAsObject<FieldTrial::FieldTrialEntry>(
-          field_trial->ref_);
+          field_trial->ref_, &allocated_size);
+  CHECK(entry);
 
-  size_t allocated_size =
-      global_->field_trial_allocator_->GetAllocSize(field_trial->ref_);
   uint64_t actual_size =
       sizeof(FieldTrial::FieldTrialEntry) + entry->pickle_size;
   if (allocated_size < actual_size)
