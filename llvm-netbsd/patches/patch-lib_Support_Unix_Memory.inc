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
@@ -166,128 +190,24 @@ Memory::protectMappedMemory(const Memory
   return std::error_code();
 }
 
-/// AllocateRWX - Allocate a slab of memory with read/write/execute
-/// permissions.  This is typically used for JIT applications where we want
-/// to emit code to the memory then jump to it.  Getting this type of memory
-/// is very OS specific.
-///
 MemoryBlock
-Memory::AllocateRWX(size_t NumBytes, const MemoryBlock* NearBlock,
-                    std::string *ErrMsg) {
-  if (NumBytes == 0) return MemoryBlock();
-
-  static const size_t PageSize = Process::getPageSize();
-  size_t NumPages = (NumBytes+PageSize-1)/PageSize;
-
-  int fd = -1;
-
-  int flags = MAP_PRIVATE |
-#ifdef MAP_ANONYMOUS
-  MAP_ANONYMOUS
-#else
-  MAP_ANON
-#endif
-  ;
-
-  void* start = NearBlock ? (unsigned char*)NearBlock->base() +
-                            NearBlock->size() : nullptr;
-
-#if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
-  void *pa = ::mmap(start, PageSize*NumPages, PROT_READ|PROT_EXEC,
-                    flags, fd, 0);
-#elif defined(__NetBSD__) && defined(PROT_MPROTECT)
-  void *pa =
-      ::mmap(start, PageSize * NumPages,
-             PROT_READ | PROT_WRITE | PROT_MPROTECT(PROT_EXEC), flags, fd, 0);
-#else
-  void *pa = ::mmap(start, PageSize*NumPages, PROT_READ|PROT_WRITE|PROT_EXEC,
-                    flags, fd, 0);
-#endif
-  if (pa == MAP_FAILED) {
-    if (NearBlock) //Try again without a near hint
-      return AllocateRWX(NumBytes, nullptr);
-
-    MakeErrMsg(ErrMsg, "Can't allocate RWX Memory");
-    return MemoryBlock();
-  }
-
-#if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
-  kern_return_t kr = vm_protect(mach_task_self(), (vm_address_t)pa,
-                                (vm_size_t)(PageSize*NumPages), 0,
-                                VM_PROT_READ | VM_PROT_EXECUTE | VM_PROT_COPY);
-  if (KERN_SUCCESS != kr) {
-    MakeErrMsg(ErrMsg, "vm_protect max RX failed");
-    return MemoryBlock();
-  }
-
-  kr = vm_protect(mach_task_self(), (vm_address_t)pa,
-                  (vm_size_t)(PageSize*NumPages), 0,
-                  VM_PROT_READ | VM_PROT_WRITE);
-  if (KERN_SUCCESS != kr) {
-    MakeErrMsg(ErrMsg, "vm_protect RW failed");
-    return MemoryBlock();
-  }
-#endif
-
-  MemoryBlock result;
-  result.Address = pa;
-  result.Size = NumPages*PageSize;
-
-  return result;
-}
-
-bool Memory::ReleaseRWX(MemoryBlock &M, std::string *ErrMsg) {
-  if (M.Address == nullptr || M.Size == 0) return false;
-  if (0 != ::munmap(M.Address, M.Size))
-    return MakeErrMsg(ErrMsg, "Can't release RWX Memory");
-  return false;
-}
-
-bool Memory::setWritable (MemoryBlock &M, std::string *ErrMsg) {
-#if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
-  if (M.Address == 0 || M.Size == 0) return false;
-  Memory::InvalidateInstructionCache(M.Address, M.Size);
-  kern_return_t kr = vm_protect(mach_task_self(), (vm_address_t)M.Address,
-    (vm_size_t)M.Size, 0, VM_PROT_READ | VM_PROT_WRITE);
-  return KERN_SUCCESS == kr;
-#else
-  return true;
-#endif
+Memory::AllocateJIT(size_t NumBytes, const MemoryBlock* NearBlock,
+                    std::error_code &EC) {
+  return allocateMappedMemory(NumBytes, NearBlock, MF_READ | MF_WRITE, EC, MF_EXEC);
 }
 
-bool Memory::setExecutable (MemoryBlock &M, std::string *ErrMsg) {
-  if (M.Address == nullptr || M.Size == 0) return false;
-  Memory::InvalidateInstructionCache(M.Address, M.Size);
-#if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
-  kern_return_t kr = vm_protect(mach_task_self(), (vm_address_t)M.Address,
-    (vm_size_t)M.Size, 0, VM_PROT_READ | VM_PROT_EXECUTE | VM_PROT_COPY);
-  return KERN_SUCCESS == kr;
-#else
-  return true;
-#endif
+std::error_code
+Memory::setWritable (const MemoryBlock &M) {
+  return protectMappedMemory(M, MF_READ | MF_WRITE);
 }
 
-bool Memory::setRangeWritable(const void *Addr, size_t Size) {
-#if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
-  kern_return_t kr = vm_protect(mach_task_self(), (vm_address_t)Addr,
-                                (vm_size_t)Size, 0,
-                                VM_PROT_READ | VM_PROT_WRITE);
-  return KERN_SUCCESS == kr;
-#else
-  return true;
-#endif
+std::error_code
+Memory::setExecutable (const MemoryBlock &M) {
+  if (M.Address != nullptr && M.Size != 0)
+    Memory::InvalidateInstructionCache(M.Address, M.Size);
+  return protectMappedMemory(M, MF_READ | MF_EXEC);
 }
 
-bool Memory::setRangeExecutable(const void *Addr, size_t Size) {
-#if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
-  kern_return_t kr = vm_protect(mach_task_self(), (vm_address_t)Addr,
-                                (vm_size_t)Size, 0,
-                                VM_PROT_READ | VM_PROT_EXECUTE | VM_PROT_COPY);
-  return KERN_SUCCESS == kr;
-#else
-  return true;
-#endif
-}
 
 /// InvalidateInstructionCache - Before the JIT can run a block of code
 /// that has been emitted it must invalidate the instruction cache on some
