$NetBSD$

--- include/llvm/ExecutionEngine/SectionMemoryManager.h.orig	2017-07-05 18:41:32.000000000 +0000
+++ include/llvm/ExecutionEngine/SectionMemoryManager.h
@@ -76,15 +76,6 @@ public:
   /// \returns true if an error occurred, false otherwise.
   bool finalizeMemory(std::string *ErrMsg = nullptr) override;
 
-  /// \brief Invalidate instruction cache for code sections.
-  ///
-  /// Some platforms with separate data cache and instruction cache require
-  /// explicit cache flush, otherwise JIT code manipulations (like resolved
-  /// relocations) will get to the data cache but not to the instruction cache.
-  ///
-  /// This method is called from finalizeMemory.
-  virtual void invalidateInstructionCache();
-
 private:
   struct FreeMemBlock {
     // The actual block of free memory
@@ -114,7 +105,7 @@ private:
                            unsigned Alignment);
 
   std::error_code applyMemoryGroupPermissions(MemoryGroup &MemGroup,
-                                              unsigned Permissions);
+                                              sys::Memory::ProtectionMode Mode);
 
   MemoryGroup CodeMem;
   MemoryGroup RWDataMem;
