$NetBSD$

--- lib/ExecutionEngine/SectionMemoryManager.cpp.orig	2017-07-05 18:38:00.000000000 +0000
+++ lib/ExecutionEngine/SectionMemoryManager.cpp
@@ -84,11 +84,9 @@ uint8_t *SectionMemoryManager::allocateS
   // FIXME: Initialize the Near member for each memory group to avoid
   // interleaving.
   std::error_code ec;
-  sys::MemoryBlock MB = sys::Memory::allocateMappedMemory(RequiredSize,
-                                                          &MemGroup.Near,
-                                                          sys::Memory::MF_READ |
-                                                            sys::Memory::MF_WRITE,
-                                                          ec);
+  sys::MemoryBlock MB = sys::Memory::AllocateJIT(RequiredSize,
+                                                 &MemGroup.Near,
+                                                 ec);
   if (ec) {
     // FIXME: Add error propagation to the interface.
     return nullptr;
@@ -128,8 +126,7 @@ bool SectionMemoryManager::finalizeMemor
   std::error_code ec;
 
   // Make code memory executable.
-  ec = applyMemoryGroupPermissions(CodeMem,
-                                   sys::Memory::MF_READ | sys::Memory::MF_EXEC);
+  ec = applyMemoryGroupPermissions(CodeMem, sys::Memory::setExecutable);
   if (ec) {
     if (ErrMsg) {
       *ErrMsg = ec.message();
@@ -138,8 +135,7 @@ bool SectionMemoryManager::finalizeMemor
   }
 
   // Make read-only data memory read-only.
-  ec = applyMemoryGroupPermissions(RODataMem,
-                                   sys::Memory::MF_READ | sys::Memory::MF_EXEC);
+  ec = applyMemoryGroupPermissions(RODataMem, sys::Memory::setReadable);
   if (ec) {
     if (ErrMsg) {
       *ErrMsg = ec.message();
@@ -179,9 +175,9 @@ static sys::MemoryBlock trimBlockToPageS
 
 std::error_code
 SectionMemoryManager::applyMemoryGroupPermissions(MemoryGroup &MemGroup,
-                                                  unsigned Permissions) {
+                                                  std::error_code (*fn)(const llvm::sys::MemoryBlock &)) {
   for (sys::MemoryBlock &MB : MemGroup.PendingMem)
-    if (std::error_code EC = sys::Memory::protectMappedMemory(MB, Permissions))
+    if (std::error_code EC = fn(MB))
       return EC;
 
   MemGroup.PendingMem.clear();
