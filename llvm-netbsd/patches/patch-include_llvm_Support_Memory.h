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
@@ -109,51 +119,38 @@ namespace sys {
     static std::error_code protectMappedMemory(const MemoryBlock &Block,
                                                unsigned Flags);
 
-    /// This method allocates a block of Read/Write/Execute memory that is
+    /// This method allocates a block of memory that is
     /// suitable for executing dynamically generated code (e.g. JIT). An
     /// attempt to allocate \p NumBytes bytes of virtual memory is made.
     /// \p NearBlock may point to an existing allocation in which case
     /// an attempt is made to allocate more memory near the existing block.
     ///
-    /// On success, this returns a non-null memory block, otherwise it returns
-    /// a null memory block and fills in *ErrMsg.
+    /// The reserved memory block is Writable (MF_READ | MF_WRITE). In
+    /// order to toggle it between writable and executable, one has to use
+    /// setWritable and setExecutable methods.
     ///
-    /// @brief Allocate Read/Write/Execute memory.
-    static MemoryBlock AllocateRWX(size_t NumBytes,
+    /// This function is a utility wrapper for allocateMappedMemory.
+    ///
+    /// \r a non-null MemoryBlock if the function was successful,
+    /// otherwise a null MemoryBlock is with \p EC describing the error.
+    ///
+    /// @brief Allocate mapped memory suitable for JIT code.
+    static MemoryBlock AllocateJIT(size_t NumBytes,
                                    const MemoryBlock *NearBlock,
-                                   std::string *ErrMsg = nullptr);
-
-    /// This method releases a block of Read/Write/Execute memory that was
-    /// allocated with the AllocateRWX method. It should not be used to
-    /// release any memory block allocated any other way.
-    ///
-    /// On success, this returns false, otherwise it returns true and fills
-    /// in *ErrMsg.
-    /// @brief Release Read/Write/Execute memory.
-    static bool ReleaseRWX(MemoryBlock &block, std::string *ErrMsg = nullptr);
+                                   std::error_code &EC);
 
     /// InvalidateInstructionCache - Before the JIT can run a block of code
     /// that has been emitted it must invalidate the instruction cache on some
     /// platforms.
     static void InvalidateInstructionCache(const void *Addr, size_t Len);
 
+    /// setExecutable - Before the JIT can write a block of code, it has to be
+    /// given read and write privilege.
+    static std::error_code setWritable(const MemoryBlock &M);
+
     /// setExecutable - Before the JIT can run a block of code, it has to be
-    /// given read and executable privilege. Return true if it is already r-x
-    /// or the system is able to change its previlege.
-    static bool setExecutable(MemoryBlock &M, std::string *ErrMsg = nullptr);
-
-    /// setWritable - When adding to a block of code, the JIT may need
-    /// to mark a block of code as RW since the protections are on page
-    /// boundaries, and the JIT internal allocations are not page aligned.
-    static bool setWritable(MemoryBlock &M, std::string *ErrMsg = nullptr);
-
-    /// setRangeExecutable - Mark the page containing a range of addresses
-    /// as executable.
-    static bool setRangeExecutable(const void *Addr, size_t Size);
-
-    /// setRangeWritable - Mark the page containing a range of addresses
-    /// as writable.
-    static bool setRangeWritable(const void *Addr, size_t Size);
+    /// given read and executable privilege.
+    static std::error_code setExecutable(const MemoryBlock &M);
   };
 
   /// Owning version of MemoryBlock.
