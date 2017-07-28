$NetBSD$

--- lib/ExecutionEngine/SectionMemoryManager.cpp.orig	2017-07-05 18:38:00.000000000 +0000
+++ lib/ExecutionEngine/SectionMemoryManager.cpp
@@ -84,11 +84,9 @@ uint8_t *SectionMemoryManager::allocateS
   // FIXME: Initialize the Near member for each memory group to avoid
   // interleaving.
   std::error_code ec;
-  sys::MemoryBlock MB = sys::Memory::allocateMappedMemory(RequiredSize,
-                                                          &MemGroup.Near,
-                                                          sys::Memory::MF_READ |
-                                                            sys::Memory::MF_WRITE,
-                                                          ec);
+  sys::MemoryBlock MB = sys::Memory::AllocateJIT(RequiredSize,
+                                                 &MemGroup.Near,
+                                                 ec);
   if (ec) {
     // FIXME: Add error propagation to the interface.
     return nullptr;
