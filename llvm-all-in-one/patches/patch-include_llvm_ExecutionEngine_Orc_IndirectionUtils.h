$NetBSD$

--- include/llvm/ExecutionEngine/Orc/IndirectionUtils.h.orig	2017-07-05 18:41:32.000000000 +0000
+++ include/llvm/ExecutionEngine/Orc/IndirectionUtils.h
@@ -164,15 +164,16 @@ public:
   LocalJITCompileCallbackManager(JITTargetAddress ErrorHandlerAddress)
       : JITCompileCallbackManager(ErrorHandlerAddress) {
     /// Set up the resolver block.
-    std::error_code EC;
-    ResolverBlock = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-        TargetT::ResolverCodeSize, nullptr,
-        sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
-    assert(!EC && "Failed to allocate resolver block");
+    std::string Err;
+    ResolverBlock = sys::OwningMemoryBlock(
+        sys::Memory::AllocateRWX(TargetT::ResolverCodeSize, nullptr, &Err));
+    if (!ResolverBlock.base())
+      report_fatal_error("Can't allocate enough memory: " + Err);
 
     TargetT::writeResolverCode(static_cast<uint8_t *>(ResolverBlock.base()),
                                &reenter, this);
 
+    std::error_code EC;
     EC = sys::Memory::protectMappedMemory(ResolverBlock.getMemoryBlock(),
                                           sys::Memory::MF_READ |
                                               sys::Memory::MF_EXEC);
@@ -191,12 +192,11 @@ private:
   void grow() override {
     assert(this->AvailableTrampolines.empty() && "Growing prematurely?");
 
-    std::error_code EC;
-    auto TrampolineBlock =
-        sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-            sys::Process::getPageSize(), nullptr,
-            sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
-    assert(!EC && "Failed to allocate trampoline block");
+    std::string Err;
+    auto TrampolineBlock = sys::OwningMemoryBlock(
+        sys::Memory::AllocateRWX(sys::Process::getPageSize(), nullptr, &Err));
+    if (!TrampolineBlock.base())
+      report_fatal_error("Can't allocate enough memory: " + Err);
 
     unsigned NumTrampolines =
         (sys::Process::getPageSize() - TargetT::PointerSize) /
@@ -211,6 +211,7 @@ private:
           static_cast<JITTargetAddress>(reinterpret_cast<uintptr_t>(
               TrampolineMem + (I * TargetT::TrampolineSize))));
 
+    std::error_code EC;
     EC = sys::Memory::protectMappedMemory(TrampolineBlock.getMemoryBlock(),
                                           sys::Memory::MF_READ |
                                               sys::Memory::MF_EXEC);
