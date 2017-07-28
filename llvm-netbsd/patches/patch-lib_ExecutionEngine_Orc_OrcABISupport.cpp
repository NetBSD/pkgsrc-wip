$NetBSD$

--- lib/ExecutionEngine/Orc/OrcABISupport.cpp.orig	2017-07-05 18:38:00.000000000 +0000
+++ lib/ExecutionEngine/Orc/OrcABISupport.cpp
@@ -155,9 +155,8 @@ Error OrcAArch64::emitIndirectStubsBlock
 
   // Allocate memory for stubs and pointers in one call.
   std::error_code EC;
-  auto StubsMem = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-      2 * NumPages * PageSize, nullptr,
-      sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+  auto StubsMem = sys::OwningMemoryBlock(sys::Memory::AllocateJIT(
+      2 * NumPages * PageSize, nullptr, EC));
 
   if (EC)
     return errorCodeToError(EC);
@@ -176,8 +175,7 @@ Error OrcAArch64::emitIndirectStubsBlock
   for (unsigned I = 0; I < NumStubs; ++I)
     Stub[I] = 0xd61f020058000010 | PtrOffsetField;
 
-  if (auto EC = sys::Memory::protectMappedMemory(
-          StubsBlock, sys::Memory::MF_READ | sys::Memory::MF_EXEC))
+  if (auto EC = sys::Memory::setExecutable(StubsBlock))
     return errorCodeToError(EC);
 
   // Initialize all pointers to point at FailureAddress.
@@ -237,9 +235,8 @@ Error OrcX86_64_Base::emitIndirectStubsB
 
   // Allocate memory for stubs and pointers in one call.
   std::error_code EC;
-  auto StubsMem = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-      2 * NumPages * PageSize, nullptr,
-      sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+  auto StubsMem = sys::OwningMemoryBlock(sys::Memory::AllocateJIT(
+      2 * NumPages * PageSize, nullptr, EC));
 
   if (EC)
     return errorCodeToError(EC);
@@ -257,8 +254,7 @@ Error OrcX86_64_Base::emitIndirectStubsB
   for (unsigned I = 0; I < NumStubs; ++I)
     Stub[I] = 0xF1C40000000025ff | PtrOffsetField;
 
-  if (auto EC = sys::Memory::protectMappedMemory(
-          StubsBlock, sys::Memory::MF_READ | sys::Memory::MF_EXEC))
+  if (auto EC = sys::Memory::setExecutable(StubsBlock))
     return errorCodeToError(EC);
 
   // Initialize all pointers to point at FailureAddress.
@@ -505,9 +501,8 @@ Error OrcI386::emitIndirectStubsBlock(In
 
   // Allocate memory for stubs and pointers in one call.
   std::error_code EC;
-  auto StubsMem = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-      2 * NumPages * PageSize, nullptr,
-      sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+  auto StubsMem = sys::OwningMemoryBlock(sys::Memory::AllocateJIT(
+      2 * NumPages * PageSize, nullptr, EC));
 
   if (EC)
     return errorCodeToError(EC);
@@ -524,8 +519,7 @@ Error OrcI386::emitIndirectStubsBlock(In
   for (unsigned I = 0; I < NumStubs; ++I, PtrAddr += 4)
     Stub[I] = 0xF1C40000000025ff | (PtrAddr << 16);
 
-  if (auto EC = sys::Memory::protectMappedMemory(
-          StubsBlock, sys::Memory::MF_READ | sys::Memory::MF_EXEC))
+  if (auto EC = sys::Memory::setExecutable(StubsBlock))
     return errorCodeToError(EC);
 
   // Initialize all pointers to point at FailureAddress.
