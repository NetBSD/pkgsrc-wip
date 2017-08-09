$NetBSD$

--- lib/Support/Unix/Memory.inc.orig	2017-07-05 18:38:14.000000000 +0000
+++ lib/Support/Unix/Memory.inc
@@ -40,39 +40,64 @@ extern "C" void __clear_cache(void *, vo
 
 namespace {
 
-int getPosixProtectionFlags(unsigned Flags) {
-  switch (Flags) {
-  case llvm::sys::Memory::MF_READ:
+int getPosixProtectionFlags(llvm::sys::Memory::ProtectionMode Mode) {
+  switch (Mode) {
+  case llvm::sys::Memory::ProtectionMode::MF_READABLE:
     return PROT_READ;
-  case llvm::sys::Memory::MF_WRITE:
-    return PROT_WRITE;
-  case llvm::sys::Memory::MF_READ|llvm::sys::Memory::MF_WRITE:
+  case llvm::sys::Memory::ProtectionMode::MF_WRITABLE:
     return PROT_READ | PROT_WRITE;
-  case llvm::sys::Memory::MF_READ|llvm::sys::Memory::MF_EXEC:
+  case llvm::sys::Memory::ProtectionMode::MF_EXECUTABLE:
     return PROT_READ | PROT_EXEC;
-  case llvm::sys::Memory::MF_READ | llvm::sys::Memory::MF_WRITE |
-      llvm::sys::Memory::MF_EXEC:
-    return PROT_READ | PROT_WRITE | PROT_EXEC;
-  case llvm::sys::Memory::MF_EXEC:
-#if defined(__FreeBSD__)
-    // On PowerPC, having an executable page that has no read permission
-    // can have unintended consequences.  The function InvalidateInstruction-
-    // Cache uses instructions dcbf and icbi, both of which are treated by
-    // the processor as loads.  If the page has no read permissions,
-    // executing these instructions will result in a segmentation fault.
-    // Somehow, this problem is not present on Linux, but it does happen
-    // on FreeBSD.
-    return PROT_READ | PROT_EXEC;
-#else
-    return PROT_EXEC;
-#endif
-  default:
-    llvm_unreachable("Illegal memory protection flag specified!");
   }
   // Provide a default return value as required by some compilers.
   return PROT_NONE;
 }
 
+/// InvalidateInstructionCache - Before the JIT can run a block of code
+/// that has been emitted it must invalidate the instruction cache on some
+/// platforms.
+void InvalidateInstructionCache(const void *Addr,
+                                        size_t Len) {
+
+// icache invalidation for PPC and ARM.
+#if defined(__APPLE__)
+
+#  if (defined(__POWERPC__) || defined (__ppc__) || \
+       defined(_POWER) || defined(_ARCH_PPC) || defined(__arm__) || \
+       defined(__arm64__))
+  sys_icache_invalidate(const_cast<void *>(Addr), Len);
+#  endif
+
+#else
+
+#  if (defined(__POWERPC__) || defined (__ppc__) || \
+       defined(_POWER) || defined(_ARCH_PPC)) && defined(__GNUC__)
+  const size_t LineSize = 32;
+
+  const intptr_t Mask = ~(LineSize - 1);
+  const intptr_t StartLine = ((intptr_t) Addr) & Mask;
+  const intptr_t EndLine = ((intptr_t) Addr + Len + LineSize - 1) & Mask;
+
+  for (intptr_t Line = StartLine; Line < EndLine; Line += LineSize)
+    asm volatile("dcbf 0, %0" : : "r"(Line));
+  asm volatile("sync");
+
+  for (intptr_t Line = StartLine; Line < EndLine; Line += LineSize)
+    asm volatile("icbi 0, %0" : : "r"(Line));
+  asm volatile("isync");
+#  elif (defined(__arm__) || defined(__aarch64__) || defined(__mips__)) && \
+        defined(__GNUC__)
+  // FIXME: Can we safely always call this for __GNUC__ everywhere?
+  const char *Start = static_cast<const char *>(Addr);
+  const char *End = Start + Len;
+  __clear_cache(const_cast<char *>(Start), const_cast<char *>(End));
+#  endif
+
+#endif  // end apple
+
+  llvm::sys::ValgrindDiscardTranslations(Addr, Len);
+}
+
 } // anonymous namespace
 
 namespace llvm {
@@ -81,7 +106,7 @@ namespace sys {
 MemoryBlock
 Memory::allocateMappedMemory(size_t NumBytes,
                              const MemoryBlock *const NearBlock,
-                             unsigned PFlags,
+                             ProtectionMode Mode,
                              std::error_code &EC) {
   EC = std::error_code();
   if (NumBytes == 0)
@@ -100,7 +125,12 @@ Memory::allocateMappedMemory(size_t NumB
 #endif
   ; // Ends statement above
 
-  int Protect = getPosixProtectionFlags(PFlags);
+  int Protect = getPosixProtectionFlags(Mode);
+
+  // Allow swapping memory protection in future on NetBSD with PaX MPROTECT
+#if defined(__NetBSD__) && defined(PROT_MPROTECT)
+  Protect |= PROT_MPROTECT(PROT_READ | PROT_WRITE | PROT_EXEC);
+#endif
 
   // Use any near hint and the page size to set a page-aligned starting address
   uintptr_t Start = NearBlock ? reinterpret_cast<uintptr_t>(NearBlock->base()) +
@@ -112,7 +142,7 @@ Memory::allocateMappedMemory(size_t NumB
                       Protect, MMFlags, fd, 0);
   if (Addr == MAP_FAILED) {
     if (NearBlock) //Try again without a near hint
-      return allocateMappedMemory(NumBytes, nullptr, PFlags, EC);
+      return allocateMappedMemory(NumBytes, nullptr, Mode, EC);
 
     EC = std::error_code(errno, std::generic_category());
     return MemoryBlock();
@@ -122,8 +152,8 @@ Memory::allocateMappedMemory(size_t NumB
   Result.Address = Addr;
   Result.Size = NumPages*PageSize;
 
-  if (PFlags & MF_EXEC)
-    Memory::InvalidateInstructionCache(Result.Address, Result.Size);
+  if (Mode == ProtectionMode::MF_EXECUTABLE)
+    InvalidateInstructionCache(Result.Address, Result.Size);
 
   return Result;
 }
@@ -143,15 +173,12 @@ Memory::releaseMappedMemory(MemoryBlock 
 }
 
 std::error_code
-Memory::protectMappedMemory(const MemoryBlock &M, unsigned Flags) {
+Memory::protectMappedMemory(const MemoryBlock &M, ProtectionMode Mode) {
   static const size_t PageSize = Process::getPageSize();
   if (M.Address == nullptr || M.Size == 0)
     return std::error_code();
 
-  if (!Flags)
-    return std::error_code(EINVAL, std::generic_category());
-
-  int Protect = getPosixProtectionFlags(Flags);
+  int Protect = getPosixProtectionFlags(Mode);
 
   uintptr_t Start = alignAddr((uint8_t *)M.Address - PageSize + 1, PageSize);
   uintptr_t End = alignAddr((uint8_t *)M.Address + M.Size, PageSize);
@@ -160,179 +187,11 @@ Memory::protectMappedMemory(const Memory
   if (Result != 0)
     return std::error_code(errno, std::generic_category());
 
-  if (Flags & MF_EXEC)
-    Memory::InvalidateInstructionCache(M.Address, M.Size);
+  if (Mode == ProtectionMode::MF_EXECUTABLE)
+    InvalidateInstructionCache(M.Address, M.Size);
 
   return std::error_code();
 }
 
-/// AllocateRWX - Allocate a slab of memory with read/write/execute
-/// permissions.  This is typically used for JIT applications where we want
-/// to emit code to the memory then jump to it.  Getting this type of memory
-/// is very OS specific.
-///
-MemoryBlock
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
-}
-
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
-}
-
-bool Memory::setRangeWritable(const void *Addr, size_t Size) {
-#if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
-  kern_return_t kr = vm_protect(mach_task_self(), (vm_address_t)Addr,
-                                (vm_size_t)Size, 0,
-                                VM_PROT_READ | VM_PROT_WRITE);
-  return KERN_SUCCESS == kr;
-#else
-  return true;
-#endif
-}
-
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
-
-/// InvalidateInstructionCache - Before the JIT can run a block of code
-/// that has been emitted it must invalidate the instruction cache on some
-/// platforms.
-void Memory::InvalidateInstructionCache(const void *Addr,
-                                        size_t Len) {
-
-// icache invalidation for PPC and ARM.
-#if defined(__APPLE__)
-
-#  if (defined(__POWERPC__) || defined (__ppc__) || \
-       defined(_POWER) || defined(_ARCH_PPC) || defined(__arm__) || \
-       defined(__arm64__))
-  sys_icache_invalidate(const_cast<void *>(Addr), Len);
-#  endif
-
-#else
-
-#  if (defined(__POWERPC__) || defined (__ppc__) || \
-       defined(_POWER) || defined(_ARCH_PPC)) && defined(__GNUC__)
-  const size_t LineSize = 32;
-
-  const intptr_t Mask = ~(LineSize - 1);
-  const intptr_t StartLine = ((intptr_t) Addr) & Mask;
-  const intptr_t EndLine = ((intptr_t) Addr + Len + LineSize - 1) & Mask;
-
-  for (intptr_t Line = StartLine; Line < EndLine; Line += LineSize)
-    asm volatile("dcbf 0, %0" : : "r"(Line));
-  asm volatile("sync");
-
-  for (intptr_t Line = StartLine; Line < EndLine; Line += LineSize)
-    asm volatile("icbi 0, %0" : : "r"(Line));
-  asm volatile("isync");
-#  elif (defined(__arm__) || defined(__aarch64__) || defined(__mips__)) && \
-        defined(__GNUC__)
-  // FIXME: Can we safely always call this for __GNUC__ everywhere?
-  const char *Start = static_cast<const char *>(Addr);
-  const char *End = Start + Len;
-  __clear_cache(const_cast<char *>(Start), const_cast<char *>(End));
-#  endif
-
-#endif  // end apple
-
-  ValgrindDiscardTranslations(Addr, Len);
-}
-
 } // namespace sys
 } // namespace llvm
