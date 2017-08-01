$NetBSD$

--- lib/Support/Unix/Memory.inc.orig	2017-07-05 18:38:14.000000000 +0000
+++ lib/Support/Unix/Memory.inc
@@ -82,7 +82,8 @@ MemoryBlock
 Memory::allocateMappedMemory(size_t NumBytes,
                              const MemoryBlock *const NearBlock,
                              unsigned PFlags,
-                             std::error_code &EC) {
+                             std::error_code &EC,
+                             unsigned MaxPFlags) {
   EC = std::error_code();
   if (NumBytes == 0)
     return MemoryBlock();
@@ -102,25 +103,103 @@ Memory::allocateMappedMemory(size_t NumB
 
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
   if (Start && Start % PageSize)
     Start += PageSize - Start % PageSize;
 
-  void *Addr = ::mmap(reinterpret_cast<void*>(Start), PageSize*NumPages,
-                      Protect, MMFlags, fd, 0);
+  const bool WXmapping = ((PFlags & (MF_WRITE | MF_EXEC)) == (MF_WRITE | MF_EXEC));
+ 
+  void *Addr;
+
+  if (WXmapping) {
+#if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
+    Addr = ::mmap(reinterpret_cast<void*>(Start), PageSize*NumPages,
+                  Protect & ~PROT_WRITE, MMFlags, fd, 0);
+#elif defined(__NetBSD__) && defined(PROT_MPROTECT)
+    Addr = ::mmap(reinterpret_cast<void*>(Start), PageSize*NumPages,
+                  Protect & ~PROT_EXEC, MMFlags, fd, 0);
+#else
+    Addr = ::mmap(reinterpret_cast<void*>(Start), PageSize*NumPages,
+                  Protect, MMFlags, fd, 0);
+#endif
+  } else {
+    Addr = ::mmap(reinterpret_cast<void*>(Start), PageSize*NumPages,
+                  Protect, MMFlags, fd, 0);
+  }
+
   if (Addr == MAP_FAILED) {
     if (NearBlock) //Try again without a near hint
-      return allocateMappedMemory(NumBytes, nullptr, PFlags, EC);
+      return allocateMappedMemory(NumBytes, nullptr, PFlags, EC, MaxPFlags);
 
     EC = std::error_code(errno, std::generic_category());
     return MemoryBlock();
   }
 
+#if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
+  if (WXmapping) {
+    kern_return_t kr = vm_protect(mach_task_self(), (vm_address_t)Addr,
+                                  (vm_size_t)(PageSize*NumPages), 0,
+                                  VM_PROT_READ | VM_PROT_EXECUTE | VM_PROT_COPY);
+    if (KERN_SUCCESS != kr) {
+      // is errno set?
+      EC = std::error_code(errno, std::generic_category());
+      return MemoryBlock();
+    }
+
+    kr = vm_protect(mach_task_self(), (vm_address_t)pa,
+                    (vm_size_t)(PageSize*NumPages), 0,
+                    VM_PROT_READ | VM_PROT_WRITE);
+    if (KERN_SUCCESS != kr) {
+      // is errno set?
+      EC = std::error_code(errno, std::generic_category());
+      return MemoryBlock();
+    }
+  }
+#elif defined(__NetBSD__) && defined(PROT_MPROTECT)
+  void *codeseg = nullptr;
+  if (WXmapping) {
+    codeseg =
+        ::mremap(Addr, PageSize * NumPages, NULL, PageSize * NumPages,
+                 MAP_REMAPDUP);
+    if (codeseg == MAP_FAILED) {
+      ::munmap(Addr, PageSize * NumPages);
+
+      if (NearBlock) // Try again without a near hint
+        return allocateMappedMemory(NumBytes, nullptr, PFlags, EC, MaxPFlags);
+
+      EC = std::error_code(errno, std::generic_category());
+      return MemoryBlock();
+    }
+    if (::mprotect(codeseg, PageSize * NumPages, PROT_READ | PROT_EXEC) == -1) {
+      ::munmap(Addr, PageSize * NumPages);
+      ::munmap(codeseg, PageSize * NumPages);
+      if (NearBlock) // Try again without a near hint
+        return allocateMappedMemory(NumBytes, nullptr, PFlags, EC, MaxPFlags);
+
+      EC = std::error_code(errno, std::generic_category());
+      return MemoryBlock();
+    }
+  }
+#endif
+
   MemoryBlock Result;
   Result.Address = Addr;
+#if defined(__NetBSD__) && defined(PROT_MPROTECT)
+  Result.AuxAddress = codeseg;
+#else
+  Result.AuxAddress = nullptr;
+#endif
   Result.Size = NumPages*PageSize;
+  Result.MaxProtection = MaxPFlags;
 
   if (PFlags & MF_EXEC)
     Memory::InvalidateInstructionCache(Result.Address, Result.Size);
