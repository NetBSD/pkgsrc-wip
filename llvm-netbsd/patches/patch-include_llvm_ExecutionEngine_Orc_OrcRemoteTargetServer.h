$NetBSD$

--- include/llvm/ExecutionEngine/Orc/OrcRemoteTargetServer.h.orig	2017-07-05 18:41:32.000000000 +0000
+++ include/llvm/ExecutionEngine/Orc/OrcRemoteTargetServer.h
@@ -115,11 +115,11 @@ private:
     }
 
     Error allocate(void *&Addr, size_t Size, uint32_t Align) {
-      std::error_code EC;
-      sys::MemoryBlock MB = sys::Memory::allocateMappedMemory(
-          Size, nullptr, sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC);
-      if (EC)
-        return errorCodeToError(EC);
+      std::string Err;
+      sys::MemoryBlock MB = sys::Memory::AllocateRWX(
+          Size, nullptr, &Err);
+      if (!MB.base())
+        report_fatal_error("Can't allocate enough memory: " + Err);
 
       Addr = MB.base();
       assert(Allocs.find(MB.base()) == Allocs.end() && "Duplicate alloc");
@@ -277,12 +277,11 @@ private:
   }
 
   Error handleEmitResolverBlock() {
-    std::error_code EC;
-    ResolverBlock = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-        TargetT::ResolverCodeSize, nullptr,
-        sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
-    if (EC)
-      return errorCodeToError(EC);
+    std::string Err;
+    ResolverBlock = sys::OwningMemoryBlock(sys::Memory::AllocateRWX(
+        TargetT::ResolverCodeSize, nullptr, &Err));
+    if (!ResolverBlock.base())
+      report_fatal_error("Can't allocate enough memory: " + Err);
 
     TargetT::writeResolverCode(static_cast<uint8_t *>(ResolverBlock.base()),
                                &reenter, this);
@@ -293,13 +292,12 @@ private:
   }
 
   Expected<std::tuple<JITTargetAddress, uint32_t>> handleEmitTrampolineBlock() {
-    std::error_code EC;
+    std::string Err;
     auto TrampolineBlock =
-        sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-            sys::Process::getPageSize(), nullptr,
-            sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
-    if (EC)
-      return errorCodeToError(EC);
+        sys::OwningMemoryBlock(sys::Memory::AllocateRWX(
+            sys::Process::getPageSize(), nullptr, &Err));
+    if (!TrampolineBlock.base())
+      report_fatal_error("Can't allocate enough memory: " + Err);
 
     uint32_t NumTrampolines =
         (sys::Process::getPageSize() - TargetT::PointerSize) /
@@ -309,6 +307,7 @@ private:
     TargetT::writeTrampolines(TrampolineMem, ResolverBlock.base(),
                               NumTrampolines);
 
+    std::error_code EC;
     EC = sys::Memory::protectMappedMemory(TrampolineBlock.getMemoryBlock(),
                                           sys::Memory::MF_READ |
                                               sys::Memory::MF_EXEC);
