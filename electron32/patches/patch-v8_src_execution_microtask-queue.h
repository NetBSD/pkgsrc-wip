$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/execution/microtask-queue.h.orig	2024-10-18 12:48:35.308422300 +0000
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
