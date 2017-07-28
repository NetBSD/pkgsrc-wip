$NetBSD$

--- include/llvm/Support/Memory.h.orig	2017-07-05 18:41:26.000000000 +0000
+++ include/llvm/Support/Memory.h
@@ -36,6 +36,7 @@ namespace sys {
   private:
     void *Address;    ///< Address of first byte of memory area
     size_t Size;      ///< Size, in bytes of the memory area
+    int MaxProtection;///< Maximum allowable Protection, of memory area
     friend class Memory;
   };
 
@@ -61,16 +62,20 @@ namespace sys {
     /// \p Flags is used to set the initial protection flags for the block
     /// of the memory.
     /// \p EC [out] returns an object describing any error that occurs.
+    /// \p MaxFlags is used to set the maximal protection flags for the block
+    /// of the memory. This value is OR'ed with \p Flags.
     ///
     /// This method may allocate more than the number of bytes requested.  The
     /// actual number of bytes allocated is indicated in the returned
     /// MemoryBlock.
     ///
     /// The start of the allocated block must be aligned with the
-    /// system allocation granularity (64K on Windows, page size on Linux).
+    /// system allocation granularity (64K on Windows, page size on Linux, etc).
     /// If the address following \p NearBlock is not so aligned, it will be
     /// rounded up to the next allocation granularity boundary.
     ///
+    /// For security reasons MF_WRITE | MF_EXEC mapping is prohibited.
+    ///
     /// \r a non-null MemoryBlock if the function was successful,
     /// otherwise a null MemoryBlock is with \p EC describing the error.
     ///
@@ -78,7 +83,7 @@ namespace sys {
     static MemoryBlock allocateMappedMemory(size_t NumBytes,
                                             const MemoryBlock *const NearBlock,
                                             unsigned Flags,
-                                            std::error_code &EC);
+                                            std::error_code &EC, unsigned MaxFlags = 0);
 
     /// This method releases a block of memory that was allocated with the
     /// allocateMappedMemory method. It should not be used to release any
@@ -102,6 +107,11 @@ namespace sys {
     /// with the operating system (i.e. MF_READ | MF_WRITE on Windows) and the
     /// target architecture (i.e. MF_WRITE -> MF_READ | MF_WRITE on i386).
     ///
+    /// The specified \p Flags parameter must by allowed by maximal protection
+    /// block of the memory.
+    ///
+    /// For security reasons MF_WRITE | MF_EXEC mapping is prohibited.
+    ///
     /// \r error_success if the function was successful, or an error_code
     /// describing the failure if an error occurred.
     ///
