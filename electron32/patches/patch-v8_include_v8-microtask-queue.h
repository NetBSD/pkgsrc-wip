$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/include/v8-microtask-queue.h.orig	2024-10-18 12:48:35.108423500 +0000
+++ v8/include/v8-microtask-queue.h
@@ -97,6 +97,9 @@ class V8_EXPORT MicrotaskQueue {
    */
   virtual int GetMicrotasksScopeDepth() const = 0;
 
+  virtual void set_microtasks_policy(v8::MicrotasksPolicy microtasks_policy) = 0;
+  virtual v8::MicrotasksPolicy microtasks_policy() const = 0;
+
   MicrotaskQueue(const MicrotaskQueue&) = delete;
   MicrotaskQueue& operator=(const MicrotaskQueue&) = delete;
 
