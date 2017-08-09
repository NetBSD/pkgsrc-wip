$NetBSD$

--- include/llvm/ExecutionEngine/Orc/IndirectionUtils.h.orig	2017-07-05 18:41:32.000000000 +0000
+++ include/llvm/ExecutionEngine/Orc/IndirectionUtils.h
@@ -167,15 +167,14 @@ public:
     std::error_code EC;
     ResolverBlock = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
         TargetT::ResolverCodeSize, nullptr,
-        sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+        sys::Memory::ProtectionMode::MF_WRITABLE, EC));
     assert(!EC && "Failed to allocate resolver block");
 
     TargetT::writeResolverCode(static_cast<uint8_t *>(ResolverBlock.base()),
                                &reenter, this);
 
     EC = sys::Memory::protectMappedMemory(ResolverBlock.getMemoryBlock(),
-                                          sys::Memory::MF_READ |
-                                              sys::Memory::MF_EXEC);
+                                          sys::Memory::ProtectionMode::MF_EXECUTABLE);
     assert(!EC && "Failed to mprotect resolver block");
   }
 
@@ -195,7 +194,7 @@ private:
     auto TrampolineBlock =
         sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
             sys::Process::getPageSize(), nullptr,
-            sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+            sys::Memory::ProtectionMode::MF_WRITABLE, EC));
     assert(!EC && "Failed to allocate trampoline block");
 
     unsigned NumTrampolines =
@@ -212,8 +211,7 @@ private:
               TrampolineMem + (I * TargetT::TrampolineSize))));
 
     EC = sys::Memory::protectMappedMemory(TrampolineBlock.getMemoryBlock(),
-                                          sys::Memory::MF_READ |
-                                              sys::Memory::MF_EXEC);
+                                          sys::Memory::ProtectionMode::MF_EXECUTABLE);
     assert(!EC && "Failed to mprotect trampoline block");
 
     TrampolineBlocks.push_back(std::move(TrampolineBlock));
