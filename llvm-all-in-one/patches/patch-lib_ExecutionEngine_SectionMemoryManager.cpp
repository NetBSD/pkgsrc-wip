$NetBSD$

--- lib/ExecutionEngine/SectionMemoryManager.cpp.orig	2017-07-05 18:38:00.000000000 +0000
+++ lib/ExecutionEngine/SectionMemoryManager.cpp
@@ -83,16 +83,11 @@ uint8_t *SectionMemoryManager::allocateS
   //
   // FIXME: Initialize the Near member for each memory group to avoid
   // interleaving.
-  std::error_code ec;
-  sys::MemoryBlock MB = sys::Memory::allocateMappedMemory(RequiredSize,
-                                                          &MemGroup.Near,
-                                                          sys::Memory::MF_READ |
-                                                            sys::Memory::MF_WRITE,
-                                                          ec);
-  if (ec) {
-    // FIXME: Add error propagation to the interface.
-    return nullptr;
-  }
+  std::string Err;
+  sys::MemoryBlock MB =
+      sys::Memory::AllocateRWX(RequiredSize, &MemGroup.Near, &Err);
+  if (!MB.base())
+    report_fatal_error("Can't allocate enough memory: " + Err);
 
   // Save this address as the basis for our next request
   MemGroup.Near = MB;
