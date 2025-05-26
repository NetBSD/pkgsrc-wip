$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/execution/microtask-queue.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ v8/src/execution/microtask-queue.h
@@ -93,10 +93,10 @@ class V8_EXPORT_PRIVATE MicrotaskQueue f
   }
 #endif
 
-  void set_microtasks_policy(v8::MicrotasksPolicy microtasks_policy) {
+  void set_microtasks_policy(v8::MicrotasksPolicy microtasks_policy) override {
     microtasks_policy_ = microtasks_policy;
   }
-  v8::MicrotasksPolicy microtasks_policy() const { return microtasks_policy_; }
+  v8::MicrotasksPolicy microtasks_policy() const override { return microtasks_policy_; }
 
   intptr_t capacity() const { return capacity_; }
   intptr_t size() const { return size_; }
