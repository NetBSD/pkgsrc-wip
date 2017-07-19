$NetBSD$

--- lib/ExecutionEngine/Orc/OrcABISupport.cpp.orig	2017-07-05 18:38:00.000000000 +0000
+++ lib/ExecutionEngine/Orc/OrcABISupport.cpp
@@ -154,13 +154,11 @@ Error OrcAArch64::emitIndirectStubsBlock
   unsigned NumStubs = (NumPages * PageSize) / StubSize;
 
   // Allocate memory for stubs and pointers in one call.
-  std::error_code EC;
-  auto StubsMem = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-      2 * NumPages * PageSize, nullptr,
-      sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
-
-  if (EC)
-    return errorCodeToError(EC);
+  std::string Err;
+  auto StubsMem = sys::OwningMemoryBlock(
+      sys::Memory::AllocateRWX(2 * NumPages * PageSize, nullptr, &Err));
+  if (!StubsMem.base())
+    report_fatal_error("Can't allocate enough memory: " + Err);
 
   // Create separate MemoryBlocks representing the stubs and pointers.
   sys::MemoryBlock StubsBlock(StubsMem.base(), NumPages * PageSize);
@@ -236,13 +234,11 @@ Error OrcX86_64_Base::emitIndirectStubsB
   unsigned NumStubs = (NumPages * PageSize) / StubSize;
 
   // Allocate memory for stubs and pointers in one call.
-  std::error_code EC;
-  auto StubsMem = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-      2 * NumPages * PageSize, nullptr,
-      sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
-
-  if (EC)
-    return errorCodeToError(EC);
+  std::string Err;
+  auto StubsMem = sys::OwningMemoryBlock(
+      sys::Memory::AllocateRWX(2 * NumPages * PageSize, nullptr, &Err));
+  if (!StubsMem.base())
+    report_fatal_error("Can't allocate enough memory: " + Err);
 
   // Create separate MemoryBlocks representing the stubs and pointers.
   sys::MemoryBlock StubsBlock(StubsMem.base(), NumPages * PageSize);
@@ -504,13 +500,11 @@ Error OrcI386::emitIndirectStubsBlock(In
   unsigned NumStubs = (NumPages * PageSize) / StubSize;
 
   // Allocate memory for stubs and pointers in one call.
-  std::error_code EC;
-  auto StubsMem = sys::OwningMemoryBlock(sys::Memory::allocateMappedMemory(
-      2 * NumPages * PageSize, nullptr,
-      sys::Memory::MF_READ | sys::Memory::MF_WRITE, EC));
-
-  if (EC)
-    return errorCodeToError(EC);
+  std::string Err;
+  auto StubsMem = sys::OwningMemoryBlock(
+      sys::Memory::AllocateRWX(2 * NumPages * PageSize, nullptr, &Err));
+  if (!StubsMem.base())
+    report_fatal_error("Can't allocate enough memory: " + Err);
 
   // Create separate MemoryBlocks representing the stubs and pointers.
   sys::MemoryBlock StubsBlock(StubsMem.base(), NumPages * PageSize);
