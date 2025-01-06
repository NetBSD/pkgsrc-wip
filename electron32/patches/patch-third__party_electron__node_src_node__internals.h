$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_internals.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_internals.h
@@ -117,7 +117,9 @@ v8::Maybe<bool> InitializePrimordials(v8
 
 class NodeArrayBufferAllocator : public ArrayBufferAllocator {
  public:
-  inline uint32_t* zero_fill_field() { return &zero_fill_field_; }
+  NodeArrayBufferAllocator();
+  ~NodeArrayBufferAllocator() override;
+  inline uint32_t* zero_fill_field() { return zero_fill_field_; }
 
   void* Allocate(size_t size) override;  // Defined in src/node.cc
   void* AllocateUninitialized(size_t size) override;
@@ -135,7 +137,7 @@ class NodeArrayBufferAllocator : public 
   }
 
  private:
-  uint32_t zero_fill_field_ = 1;  // Boolean but exposed as uint32 to JS land.
+  uint32_t* zero_fill_field_ = nullptr;  // Boolean but exposed as uint32 to JS land.
   std::atomic<size_t> total_mem_usage_ {0};
 
   // Delegate to V8's allocator for compatibility with the V8 memory cage.
