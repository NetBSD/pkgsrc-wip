$NetBSD$

--- lib/Support/Unix/Memory.inc.orig	2016-12-16 22:52:53.000000000 +0000
+++ lib/Support/Unix/Memory.inc
@@ -195,9 +195,10 @@ Memory::AllocateRWX(size_t NumBytes, con
 #if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
   void *pa = ::mmap(start, PageSize*NumPages, PROT_READ|PROT_EXEC,
                     flags, fd, 0);
-#else
-  void *pa = ::mmap(start, PageSize*NumPages, PROT_READ|PROT_WRITE|PROT_EXEC,
-                    flags, fd, 0);
+#elif defined(__NetBSD__) && defined(PROT_MPROTECT)
+  void *pa =
+      ::mmap(start, PageSize * NumPages,
+             PROT_READ | PROT_WRITE | PROT_MPROTECT(PROT_EXEC), flags, fd, 0);
 #endif
   if (pa == MAP_FAILED) {
     if (NearBlock) //Try again without a near hint
@@ -223,10 +224,35 @@ Memory::AllocateRWX(size_t NumBytes, con
     MakeErrMsg(ErrMsg, "vm_protect RW failed");
     return MemoryBlock();
   }
+#elif defined(__NetBSD__) && defined(PROT_MPROTECT)
+  void *codeseg =
+      ::mremap(pa, PageSize * NumPages, NULL, PageSize * NumPages,
+               MAP_REMAPDUP);
+  if (codeseg == MAP_FAILED) {
+    ::munmap(pa, PageSize * NumPages);
+
+    if (NearBlock) // Try again without a near hint
+      return AllocateRWX(NumBytes, nullptr);
+
+    MakeErrMsg(ErrMsg, "Can't allocate RWX Memory");
+    return MemoryBlock();
+  }
+  if (::mprotect(codeseg, PageSize * NumPages, PROT_READ | PROT_EXEC) == -1) {
+    ::munmap(pa, PageSize * NumPages);
+    ::munmap(codeseg, PageSize * NumPages);
+    if (NearBlock) // Try again without a near hint
+      return AllocateRWX(NumBytes, nullptr);
+
+    MakeErrMsg(ErrMsg, "Can't allocate RWX Memory");
+    return MemoryBlock();
+  }
 #endif
 
   MemoryBlock result;
   result.Address = pa;
+#if defined(__NetBSD__) && defined(PROT_MPROTECT)
+  result.SecondaryAddress = codeseg;
+#endif
   result.Size = NumPages*PageSize;
 
   return result;
@@ -236,6 +262,9 @@ bool Memory::ReleaseRWX(MemoryBlock &M, 
   if (M.Address == nullptr || M.Size == 0) return false;
   if (0 != ::munmap(M.Address, M.Size))
     return MakeErrMsg(ErrMsg, "Can't release RWX Memory");
+  if (M.SecondaryAddress)
+    if (0 != ::munmap(M.SecondaryAddress, M.Size))
+      return MakeErrMsg(ErrMsg, "Can't release RWX Memory");
   return false;
 }
 
