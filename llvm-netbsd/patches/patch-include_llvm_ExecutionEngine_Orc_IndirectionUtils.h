$NetBSD$

--- include/llvm/ExecutionEngine/Orc/IndirectionUtils.h.orig	2017-07-05 18:41:32.000000000 +0000
+++ include/llvm/ExecutionEngine/Orc/IndirectionUtils.h
@@ -165,17 +165,14 @@ public:
       : JITCompileCallbackManager(ErrorHandlerAddress) {
     /// Set up the resolver block.
     std::error_code EC;
-    ResolverBlock = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-        TargetT::ResolverCodeSize, nullptr,
-        sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+    ResolverBlock = sys::OwningMemoryBlock(sys::Memory::AllocateJIT(
+        TargetT::ResolverCodeSize, nullptr, EC));
     assert(!EC && "Failed to allocate resolver block");
 
     TargetT::writeResolverCode(static_cast<uint8_t *>(ResolverBlock.base()),
                                &reenter, this);
 
-    EC = sys::Memory::protectMappedMemory(ResolverBlock.getMemoryBlock(),
-                                          sys::Memory::MF_READ |
-                                              sys::Memory::MF_EXEC);
+    EC = sys::Memory::setExecutable(ResolverBlock.getMemoryBlock());
     assert(!EC && "Failed to mprotect resolver block");
   }
 
@@ -193,9 +190,8 @@ private:
 
     std::error_code EC;
     auto TrampolineBlock =
-        sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-            sys::Process::getPageSize(), nullptr,
-            sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+        sys::OwningMemoryBlock(sys::Memory::AllocateJIT(
+            sys::Process::getPageSize(), nullptr, EC));
     assert(!EC && "Failed to allocate trampoline block");
 
     unsigned NumTrampolines =
@@ -211,9 +207,7 @@ private:
           static_cast<JITTargetAddress>(reinterpret_cast<uintptr_t>(
               TrampolineMem + (I * TargetT::TrampolineSize))));
 
-    EC = sys::Memory::protectMappedMemory(TrampolineBlock.getMemoryBlock(),
-                                          sys::Memory::MF_READ |
-                                              sys::Memory::MF_EXEC);
+    EC = sys::Memory::setExecutable(TrampolineBlock.getMemoryBlock());
     assert(!EC && "Failed to mprotect trampoline block");
 
     TrampolineBlocks.push_back(std::move(TrampolineBlock));
