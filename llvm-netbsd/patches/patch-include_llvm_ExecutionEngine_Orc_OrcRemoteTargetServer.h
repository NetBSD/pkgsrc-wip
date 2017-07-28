$NetBSD$

--- include/llvm/ExecutionEngine/Orc/OrcRemoteTargetServer.h.orig	2017-07-05 18:41:32.000000000 +0000
+++ include/llvm/ExecutionEngine/Orc/OrcRemoteTargetServer.h
@@ -116,8 +116,8 @@ private:
 
     Error allocate(void *&Addr, size_t Size, uint32_t Align) {
       std::error_code EC;
-      sys::MemoryBlock MB = sys::Memory::allocateMappedMemory(
-          Size, nullptr, sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC);
+      sys::MemoryBlock MB = sys::Memory::AllocateJIT(
+          Size, nullptr, EC);
       if (EC)
         return errorCodeToError(EC);
 
@@ -278,26 +278,23 @@ private:
 
   Error handleEmitResolverBlock() {
     std::error_code EC;
-    ResolverBlock = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-        TargetT::ResolverCodeSize, nullptr,
-        sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+    ResolverBlock = sys::OwningMemoryBlock(sys::Memory::AllocateJIT(
+        TargetT::ResolverCodeSize, nullptr, EC));
     if (EC)
       return errorCodeToError(EC);
 
     TargetT::writeResolverCode(static_cast<uint8_t *>(ResolverBlock.base()),
                                &reenter, this);
 
-    return errorCodeToError(sys::Memory::protectMappedMemory(
-        ResolverBlock.getMemoryBlock(),
-        sys::Memory::MF_READ | sys::Memory::MF_EXEC));
+    return errorCodeToError(sys::Memory::setExecutable(
+        ResolverBlock.getMemoryBlock()));
   }
 
   Expected<std::tuple<JITTargetAddress, uint32_t>> handleEmitTrampolineBlock() {
     std::error_code EC;
     auto TrampolineBlock =
-        sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-            sys::Process::getPageSize(), nullptr,
-            sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+        sys::OwningMemoryBlock(sys::Memory::AllocateJIT(
+            sys::Process::getPageSize(), nullptr, EC));
     if (EC)
       return errorCodeToError(EC);
 
@@ -309,9 +306,7 @@ private:
     TargetT::writeTrampolines(TrampolineMem, ResolverBlock.base(),
                               NumTrampolines);
 
-    EC = sys::Memory::protectMappedMemory(TrampolineBlock.getMemoryBlock(),
-                                          sys::Memory::MF_READ |
-                                              sys::Memory::MF_EXEC);
+    EC = sys::Memory::setExecutable(TrampolineBlock.getMemoryBlock());
 
     TrampolineBlocks.push_back(std::move(TrampolineBlock));
 
