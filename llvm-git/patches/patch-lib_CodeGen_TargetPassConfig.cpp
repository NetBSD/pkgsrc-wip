$NetBSD$

--- lib/CodeGen/TargetPassConfig.cpp.orig	2017-02-02 23:04:55.000000000 +0000
+++ lib/CodeGen/TargetPassConfig.cpp
@@ -733,7 +733,7 @@ MachinePassRegistry RegisterRegAlloc::Re
 
 /// A dummy default pass factory indicates whether the register allocator is
 /// overridden on the command line.
-LLVM_DEFINE_ONCE_FLAG(InitializeDefaultRegisterAllocatorFlag);
+static llvm::once_flag InitializeDefaultRegisterAllocatorFlag;
 static FunctionPass *useDefaultRegisterAllocator() { return nullptr; }
 static RegisterRegAlloc
 defaultRegAlloc("default",
