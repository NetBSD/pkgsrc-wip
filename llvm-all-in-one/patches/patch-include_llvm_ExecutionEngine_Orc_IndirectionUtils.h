$NetBSD$

--- include/llvm/ExecutionEngine/Orc/IndirectionUtils.h.orig	2017-10-02 15:23:26.164151727 +0000
+++ include/llvm/ExecutionEngine/Orc/IndirectionUtils.h
@@ -168,15 +168,16 @@ public:
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
@@ -195,13 +196,11 @@ private:
   Error grow() override {
     assert(this->AvailableTrampolines.empty() && "Growing prematurely?");
 
-    std::error_code EC;
-    auto TrampolineBlock =
-        sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-            sys::Process::getPageSize(), nullptr,
-            sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
-    if (EC)
-      return errorCodeToError(EC);
+    std::string Err;
+    auto TrampolineBlock = sys::OwningMemoryBlock(
+        sys::Memory::AllocateRWX(sys::Process::getPageSize(), nullptr, &Err));
+    if (!TrampolineBlock.base())
+      report_fatal_error("Can't allocate enough memory: " + Err);
 
     unsigned NumTrampolines =
         (sys::Process::getPageSize() - TargetT::PointerSize) /
