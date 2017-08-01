$NetBSD$

--- include/llvm/Support/Memory.h.orig	2017-07-05 18:41:26.000000000 +0000
+++ include/llvm/Support/Memory.h
@@ -28,14 +28,16 @@ namespace sys {
   /// @brief Memory block abstraction.
   class MemoryBlock {
   public:
-    MemoryBlock() : Address(nullptr), Size(0) { }
-    MemoryBlock(void *addr, size_t size) : Address(addr), Size(size) { }
+    MemoryBlock() : Address(nullptr), AuxAddress(nullptr), Size(0) { }
+    MemoryBlock(void *addr, size_t size) : Address(addr), AuxAddress(nullptr), Size(size) { }
     void *base() const { return Address; }
     size_t size() const { return Size; }
 
   private:
     void *Address;    ///< Address of first byte of memory area
+    void *AuxAddress; ///< Auxilary Address of first byte of memory area, this is required implementation detail on some platforms
     size_t Size;      ///< Size, in bytes of the memory area
+    int MaxProtection;///< Maximum allowable Protection, of memory area
     friend class Memory;
   };
 
@@ -61,13 +63,15 @@ namespace sys {
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
@@ -78,7 +82,8 @@ namespace sys {
     static MemoryBlock allocateMappedMemory(size_t NumBytes,
                                             const MemoryBlock *const NearBlock,
                                             unsigned Flags,
-                                            std::error_code &EC);
+                                            std::error_code &EC,
+                                            unsigned MaxFlags = 0);
 
     /// This method releases a block of memory that was allocated with the
     /// allocateMappedMemory method. It should not be used to release any
@@ -102,6 +107,9 @@ namespace sys {
     /// with the operating system (i.e. MF_READ | MF_WRITE on Windows) and the
     /// target architecture (i.e. MF_WRITE -> MF_READ | MF_WRITE on i386).
     ///
+    /// The specified \p Flags parameter must by allowed by the maximal
+    /// protection block of the memory.
+    ///
     /// \r error_success if the function was successful, or an error_code
     /// describing the failure if an error occurred.
     ///
@@ -132,6 +140,27 @@ namespace sys {
     /// @brief Release Read/Write/Execute memory.
     static bool ReleaseRWX(MemoryBlock &block, std::string *ErrMsg = nullptr);
 
+    /// This method allocates a block of Read/Write and future option for
+    /// Executable memory that is
+    /// suitable for executing dynamically generated code (e.g. JIT). An
+    /// attempt to allocate \p NumBytes bytes of virtual memory is made.
+    /// \p NearBlock may point to an existing allocation in which case
+    /// an attempt is made to allocate more memory near the existing block.
+    ///
+    /// This function should be combined with makeExecutable.
+    ///
+    /// \r a non-null MemoryBlock if the function was successful,
+    /// otherwise a null MemoryBlock is with \p EC describing the error.
+    ///
+    /// @brief Allocate Read/Write with future option for Execute memory.
+    static MemoryBlock allocateJITExecutableMemory(size_t NumBytes,
+                                                   const MemoryBlock *NearBlock,
+                                                   std::error_code &EC);
+
+    /// makeExecutable - Mark the page containing a range of addresses
+    /// as executable.
+    static std::error_code makeExecutable(const MemoryBlock &Block);
+
     /// InvalidateInstructionCache - Before the JIT can run a block of code
     /// that has been emitted it must invalidate the instruction cache on some
     /// platforms.
