$NetBSD$

--- include/llvm/ExecutionEngine/Orc/OrcRemoteTargetServer.h.orig	2017-07-05 18:41:32.000000000 +0000
+++ include/llvm/ExecutionEngine/Orc/OrcRemoteTargetServer.h
@@ -117,7 +117,7 @@ private:
     Error allocate(void *&Addr, size_t Size, uint32_t Align) {
       std::error_code EC;
       sys::MemoryBlock MB = sys::Memory::allocateMappedMemory(
-          Size, nullptr, sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC);
+          Size, nullptr, sys::Memory::ProtectionMode::MF_WRITABLE, EC);
       if (EC)
         return errorCodeToError(EC);
 
@@ -127,12 +127,12 @@ private:
       return Error::success();
     }
 
-    Error setProtections(void *block, unsigned Flags) {
+    Error setProtections(void *block, sys::Memory::ProtectionMode Mode) {
       auto I = Allocs.find(block);
       if (I == Allocs.end())
         return errorCodeToError(orcError(OrcErrorCode::RemoteMProtectAddrUnrecognized));
       return errorCodeToError(
-          sys::Memory::protectMappedMemory(I->second, Flags));
+          sys::Memory::protectMappedMemory(I->second, Mode));
     }
 
   private:
@@ -280,7 +280,7 @@ private:
     std::error_code EC;
     ResolverBlock = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
         TargetT::ResolverCodeSize, nullptr,
-        sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+        sys::Memory::ProtectionMode::MF_WRITABLE, EC));
     if (EC)
       return errorCodeToError(EC);
 
@@ -289,7 +289,7 @@ private:
 
     return errorCodeToError(sys::Memory::protectMappedMemory(
         ResolverBlock.getMemoryBlock(),
-        sys::Memory::MF_READ | sys::Memory::MF_EXEC));
+        sys::Memory::ProtectionMode::MF_EXECUTABLE));
   }
 
   Expected<std::tuple<JITTargetAddress, uint32_t>> handleEmitTrampolineBlock() {
@@ -297,7 +297,7 @@ private:
     auto TrampolineBlock =
         sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
             sys::Process::getPageSize(), nullptr,
-            sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+            sys::Memory::ProtectionMode::MF_WRITABLE, EC));
     if (EC)
       return errorCodeToError(EC);
 
@@ -310,8 +310,7 @@ private:
                               NumTrampolines);
 
     EC = sys::Memory::protectMappedMemory(TrampolineBlock.getMemoryBlock(),
-                                          sys::Memory::MF_READ |
-                                              sys::Memory::MF_EXEC);
+                                          sys::Memory::ProtectionMode::MF_EXECUTABLE);
 
     TrampolineBlocks.push_back(std::move(TrampolineBlock));
 
@@ -389,7 +388,7 @@ private:
   }
 
   Error handleSetProtections(ResourceIdMgr::ResourceId Id,
-                             JITTargetAddress Addr, uint32_t Flags) {
+                             JITTargetAddress Addr, sys::Memory::ProtectionMode Mode) {
     auto I = Allocators.find(Id);
     if (I == Allocators.end())
       return errorCodeToError(
@@ -397,10 +396,11 @@ private:
     auto &Allocator = I->second;
     void *LocalAddr = reinterpret_cast<void *>(static_cast<uintptr_t>(Addr));
     DEBUG(dbgs() << "  Allocator " << Id << " set permissions on " << LocalAddr
-                 << " to " << (Flags & sys::Memory::MF_READ ? 'R' : '-')
-                 << (Flags & sys::Memory::MF_WRITE ? 'W' : '-')
-                 << (Flags & sys::Memory::MF_EXEC ? 'X' : '-') << "\n");
-    return Allocator.setProtections(LocalAddr, Flags);
+                 << " to " << (Mode == sys::Memory::ProtectionMode::MF_READABLE ? "R--" : "")
+                 << (Mode == sys::Memory::ProtectionMode::MF_WRITABLE ? "RW-" : "")
+                 << (Mode == sys::Memory::ProtectionMode::MF_READABLE ? "R-X" : "")
+                 << "\n");
+    return Allocator.setProtections(LocalAddr, Mode);
   }
 
   Error handleTerminateSession() {
