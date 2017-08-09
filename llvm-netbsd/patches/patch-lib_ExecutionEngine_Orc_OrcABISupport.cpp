$NetBSD$

--- lib/ExecutionEngine/Orc/OrcABISupport.cpp.orig	2017-07-05 18:38:00.000000000 +0000
+++ lib/ExecutionEngine/Orc/OrcABISupport.cpp
@@ -157,7 +157,7 @@ Error OrcAArch64::emitIndirectStubsBlock
   std::error_code EC;
   auto StubsMem = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
       2 * NumPages * PageSize, nullptr,
-      sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+      sys::Memory::ProtectionMode::MF_WRITABLE, EC));
 
   if (EC)
     return errorCodeToError(EC);
@@ -177,7 +177,7 @@ Error OrcAArch64::emitIndirectStubsBlock
     Stub[I] = 0xd61f020058000010 | PtrOffsetField;
 
   if (auto EC = sys::Memory::protectMappedMemory(
-          StubsBlock, sys::Memory::MF_READ | sys::Memory::MF_EXEC))
+          StubsBlock, sys::Memory::ProtectionMode::MF_EXECUTABLE))
     return errorCodeToError(EC);
 
   // Initialize all pointers to point at FailureAddress.
@@ -239,7 +239,7 @@ Error OrcX86_64_Base::emitIndirectStubsB
   std::error_code EC;
   auto StubsMem = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
       2 * NumPages * PageSize, nullptr,
-      sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+      sys::Memory::ProtectionMode::MF_WRITABLE, EC));
 
   if (EC)
     return errorCodeToError(EC);
@@ -258,7 +258,7 @@ Error OrcX86_64_Base::emitIndirectStubsB
     Stub[I] = 0xF1C40000000025ff | PtrOffsetField;
 
   if (auto EC = sys::Memory::protectMappedMemory(
-          StubsBlock, sys::Memory::MF_READ | sys::Memory::MF_EXEC))
+          StubsBlock, sys::Memory::ProtectionMode::MF_EXECUTABLE))
     return errorCodeToError(EC);
 
   // Initialize all pointers to point at FailureAddress.
@@ -507,7 +507,7 @@ Error OrcI386::emitIndirectStubsBlock(In
   std::error_code EC;
   auto StubsMem = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
       2 * NumPages * PageSize, nullptr,
-      sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
+      sys::Memory::ProtectionMode::MF_WRITABLE, EC));
 
   if (EC)
     return errorCodeToError(EC);
@@ -525,7 +525,7 @@ Error OrcI386::emitIndirectStubsBlock(In
     Stub[I] = 0xF1C40000000025ff | (PtrAddr << 16);
 
   if (auto EC = sys::Memory::protectMappedMemory(
-          StubsBlock, sys::Memory::MF_READ | sys::Memory::MF_EXEC))
+          StubsBlock, sys::Memory::ProtectionMode::MF_EXECUTABLE))
     return errorCodeToError(EC);
 
   // Initialize all pointers to point at FailureAddress.
