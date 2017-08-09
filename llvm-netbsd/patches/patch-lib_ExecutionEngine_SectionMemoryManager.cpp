$NetBSD$

--- lib/ExecutionEngine/SectionMemoryManager.cpp.orig	2017-07-05 18:38:00.000000000 +0000
+++ lib/ExecutionEngine/SectionMemoryManager.cpp
@@ -86,8 +86,7 @@ uint8_t *SectionMemoryManager::allocateS
   std::error_code ec;
   sys::MemoryBlock MB = sys::Memory::allocateMappedMemory(RequiredSize,
                                                           &MemGroup.Near,
-                                                          sys::Memory::MF_READ |
-                                                            sys::Memory::MF_WRITE,
+                                                          sys::Memory::ProtectionMode::MF_WRITABLE,
                                                           ec);
   if (ec) {
     // FIXME: Add error propagation to the interface.
@@ -129,7 +128,7 @@ bool SectionMemoryManager::finalizeMemor
 
   // Make code memory executable.
   ec = applyMemoryGroupPermissions(CodeMem,
-                                   sys::Memory::MF_READ | sys::Memory::MF_EXEC);
+                                   sys::Memory::ProtectionMode::MF_EXECUTABLE);
   if (ec) {
     if (ErrMsg) {
       *ErrMsg = ec.message();
@@ -139,7 +138,7 @@ bool SectionMemoryManager::finalizeMemor
 
   // Make read-only data memory read-only.
   ec = applyMemoryGroupPermissions(RODataMem,
-                                   sys::Memory::MF_READ | sys::Memory::MF_EXEC);
+                                   sys::Memory::ProtectionMode::MF_READABLE);
   if (ec) {
     if (ErrMsg) {
       *ErrMsg = ec.message();
@@ -149,11 +148,6 @@ bool SectionMemoryManager::finalizeMemor
 
   // Read-write data memory already has the correct permissions
 
-  // Some platforms with separate data cache and instruction cache require
-  // explicit cache flush, otherwise JIT code manipulations (like resolved
-  // relocations) will get to the data cache but not to the instruction cache.
-  invalidateInstructionCache();
-
   return false;
 }
 
@@ -179,9 +173,9 @@ static sys::MemoryBlock trimBlockToPageS
 
 std::error_code
 SectionMemoryManager::applyMemoryGroupPermissions(MemoryGroup &MemGroup,
-                                                  unsigned Permissions) {
+                                                  sys::Memory::ProtectionMode Mode) {
   for (sys::MemoryBlock &MB : MemGroup.PendingMem)
-    if (std::error_code EC = sys::Memory::protectMappedMemory(MB, Permissions))
+    if (std::error_code EC = sys::Memory::protectMappedMemory(MB, Mode))
       return EC;
 
   MemGroup.PendingMem.clear();
@@ -203,11 +197,6 @@ SectionMemoryManager::applyMemoryGroupPe
   return std::error_code();
 }
 
-void SectionMemoryManager::invalidateInstructionCache() {
-  for (sys::MemoryBlock &Block : CodeMem.PendingMem)
-    sys::Memory::InvalidateInstructionCache(Block.base(), Block.size());
-}
-
 SectionMemoryManager::~SectionMemoryManager() {
   for (MemoryGroup *Group : {&CodeMem, &RWDataMem, &RODataMem}) {
     for (sys::MemoryBlock &Block : Group->AllocatedMem)
