$NetBSD$

--- lib/Support/Unix/Memory.inc.orig	2016-12-16 22:52:53.000000000 +0000
+++ lib/Support/Unix/Memory.inc
@@ -177,7 +177,16 @@ Memory::AllocateRWX(size_t NumBytes, con
   if (NumBytes == 0) return MemoryBlock();
 
   static const size_t PageSize = Process::getPageSize();
-  size_t NumPages = (NumBytes+PageSize-1)/PageSize;
+
+  static const size_t overhead =
+#if __NetBSD_Version__ - 0 >= 799007200
+  sizeof(void*)
+#else
+  0
+#endif
+  ;
+
+  size_t NumPages = (NumBytes+overhead+PageSize-1)/PageSize;
 
   int fd = -1;
 
@@ -195,6 +204,9 @@ Memory::AllocateRWX(size_t NumBytes, con
 #if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
   void *pa = ::mmap(start, PageSize*NumPages, PROT_READ|PROT_EXEC,
                     flags, fd, 0);
+#elif __NetBSD_Version__ - 0 >= 799007200
+  void *pa = ::mmap(start, PageSize*NumPages, PROT_READ | PROT_WRITE | PROT_MPROTECT(PROT_EXEC),
+                    flags, fd, 0);
 #else
   void *pa = ::mmap(start, PageSize*NumPages, PROT_READ|PROT_WRITE|PROT_EXEC,
                     flags, fd, 0);
@@ -223,19 +235,49 @@ Memory::AllocateRWX(size_t NumBytes, con
     MakeErrMsg(ErrMsg, "vm_protect RW failed");
     return MemoryBlock();
   }
+#elif __NetBSD_Version__ - 0 >= 799007200
+  void *codeseg = mremap(pa, PageSize*NumPages, NULL, PageSize*NumPages, MAP_REMAPDUP);
+  if (codeseg == MAP_FAILED) {
+    munmap(pa, PageSize*NumPages);
+
+    if (NearBlock) //Try again without a near hint
+      return AllocateRWX(NumBytes, nullptr);
+
+    MakeErrMsg(ErrMsg, "Can't allocate RWX Memory");
+    return MemoryBlock();
+  }
+  if (mprotect(codeseg, PageSize*NumPages, PROT_READ | PROT_EXEC) == -1) {
+    munmap(pa, PageSize*NumPages);
+    munmap(codeseg, PageSize*NumPages);
+    if (NearBlock) //Try again without a near hint
+      return AllocateRWX(NumBytes, nullptr);
+
+    MakeErrMsg(ErrMsg, "Can't allocate RWX Memory");
+    return MemoryBlock();
+  }
+  // Rembember code segment pointer, to be able to free it later
+  memcpy(pa, &codeseg, sizeof(void *));
 #endif
 
   MemoryBlock result;
-  result.Address = pa;
-  result.Size = NumPages*PageSize;
+  result.Address = (void *)((uintptr_t)pa + overhead);
+  result.Size = NumPages*PageSize - overhead;
 
   return result;
 }
 
 bool Memory::ReleaseRWX(MemoryBlock &M, std::string *ErrMsg) {
   if (M.Address == nullptr || M.Size == 0) return false;
+#if __NetBSD_Version__ - 0 >= 799007200
+  static const size_t overhead = sizeof(void *);
+  void *codeseg;
+  memcpy(&codeseg, (void *)((uintptr_t)M.Address - overhead), sizeof(void *));
+  if (0 != ::munmap(codeseg, M.Size + overhead) || 0 != ::munmap(M.Address, M.Size + overhead))
+    return MakeErrMsg(ErrMsg, "Can't release RWX Memory");
+#else
   if (0 != ::munmap(M.Address, M.Size))
     return MakeErrMsg(ErrMsg, "Can't release RWX Memory");
+#endif
   return false;
 }
 
