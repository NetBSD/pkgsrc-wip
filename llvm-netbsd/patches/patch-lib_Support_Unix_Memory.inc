$NetBSD$

--- lib/Support/Unix/Memory.inc.orig	2017-07-05 18:38:14.000000000 +0000
+++ lib/Support/Unix/Memory.inc
@@ -82,8 +82,16 @@ MemoryBlock
 Memory::allocateMappedMemory(size_t NumBytes,
                              const MemoryBlock *const NearBlock,
                              unsigned PFlags,
-                             std::error_code &EC) {
+                             std::error_code &EC,
+                             unsigned MaxPFlags) {
   EC = std::error_code();
+
+  // W^X restriction
+  if ((PFlags & (MF_WRITE | MF_EXEC)) == (MF_WRITE | MF_EXEC)) {
+    EC = std::error_code(EACCES, std::generic_category());
+    return MemoryBlock();
+  }
+
   if (NumBytes == 0)
     return MemoryBlock();
 
@@ -102,6 +110,13 @@ Memory::allocateMappedMemory(size_t NumB
 
   int Protect = getPosixProtectionFlags(PFlags);
 
+  MaxPFlags |= PFlags;
+
+  // NetBSD with PaX MPROTECT must reserve additional allowable protection bits
+#if defined(__NetBSD__) && defined(PROT_MPROTECT)
+  Protect |= PROT_MPROTECT(getPosixProtectionFlags(MaxPFlags & (~PFlags)));
+#endif
+
   // Use any near hint and the page size to set a page-aligned starting address
   uintptr_t Start = NearBlock ? reinterpret_cast<uintptr_t>(NearBlock->base()) +
                                       NearBlock->size() : 0;
@@ -112,7 +127,7 @@ Memory::allocateMappedMemory(size_t NumB
                       Protect, MMFlags, fd, 0);
   if (Addr == MAP_FAILED) {
     if (NearBlock) //Try again without a near hint
-      return allocateMappedMemory(NumBytes, nullptr, PFlags, EC);
+      return allocateMappedMemory(NumBytes, nullptr, PFlags, EC, MaxPFlags);
 
     EC = std::error_code(errno, std::generic_category());
     return MemoryBlock();
@@ -121,6 +136,7 @@ Memory::allocateMappedMemory(size_t NumB
   MemoryBlock Result;
   Result.Address = Addr;
   Result.Size = NumPages*PageSize;
+  Result.MaxProtection = MaxPFlags;
 
   if (PFlags & MF_EXEC)
     Memory::InvalidateInstructionCache(Result.Address, Result.Size);
@@ -144,6 +160,14 @@ Memory::releaseMappedMemory(MemoryBlock 
 
 std::error_code
 Memory::protectMappedMemory(const MemoryBlock &M, unsigned Flags) {
+  // W^X restriction
+  if ((Flags & (MF_WRITE | MF_EXEC)) == (MF_WRITE | MF_EXEC))
+    return std::error_code(EACCES, std::generic_category());
+
+  // Check whether new protection bits are allowed
+  if ((~M.MaxProtection) & Flags)
+    return std::error_code(EACCES, std::generic_category());
+
   static const size_t PageSize = Process::getPageSize();
   if (M.Address == nullptr || M.Size == 0)
     return std::error_code();
