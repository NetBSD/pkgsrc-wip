$NetBSD$

--- include/llvm/ExecutionEngine/SectionMemoryManager.h.orig	2017-07-05 18:41:32.000000000 +0000
+++ include/llvm/ExecutionEngine/SectionMemoryManager.h
@@ -114,7 +114,7 @@ private:
                            unsigned Alignment);
 
   std::error_code applyMemoryGroupPermissions(MemoryGroup &MemGroup,
-                                              unsigned Permissions);
+                                              std::error_code (*fn)(const llvm::sys::MemoryBlock &));
 
   MemoryGroup CodeMem;
   MemoryGroup RWDataMem;
