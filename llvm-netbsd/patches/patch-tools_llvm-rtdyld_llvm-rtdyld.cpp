$NetBSD$

--- tools/llvm-rtdyld/llvm-rtdyld.cpp.orig	2017-07-20 19:13:57.000000000 +0000
+++ tools/llvm-rtdyld/llvm-rtdyld.cpp
@@ -178,10 +178,10 @@ public:
   void deregisterEHFrames() override {}
 
   void preallocateSlab(uint64_t Size) {
-    std::string Err;
-    sys::MemoryBlock MB = sys::Memory::AllocateRWX(Size, nullptr, &Err);
+    std::error_code EC;
+    sys::MemoryBlock MB = sys::Memory::allocateMappedMemory(Size, nullptr, sys::Memory::ProtectionMode::MF_WRITABLE, EC);
     if (!MB.base())
-      report_fatal_error("Can't allocate enough memory: " + Err);
+      report_fatal_error("Can't allocate enough memory");
 
     PreallocSlab = MB;
     UsePreallocation = true;
@@ -222,10 +222,10 @@ uint8_t *TrivialMemoryManager::allocateC
   if (UsePreallocation)
     return allocateFromSlab(Size, Alignment, true /* isCode */);
 
-  std::string Err;
-  sys::MemoryBlock MB = sys::Memory::AllocateRWX(Size, nullptr, &Err);
+  std::error_code EC;
+  sys::MemoryBlock MB = sys::Memory::allocateMappedMemory(Size, nullptr, sys::Memory::ProtectionMode::MF_WRITABLE, EC);
   if (!MB.base())
-    report_fatal_error("MemoryManager allocation failed: " + Err);
+    report_fatal_error("MemoryManager allocation failed");
   FunctionMemory.push_back(MB);
   return (uint8_t*)MB.base();
 }
@@ -242,10 +242,10 @@ uint8_t *TrivialMemoryManager::allocateD
   if (UsePreallocation)
     return allocateFromSlab(Size, Alignment, false /* isCode */);
 
-  std::string Err;
-  sys::MemoryBlock MB = sys::Memory::AllocateRWX(Size, nullptr, &Err);
+  std::error_code EC;
+  sys::MemoryBlock MB = sys::Memory::allocateMappedMemory(Size, nullptr, sys::Memory::ProtectionMode::MF_WRITABLE, EC);
   if (!MB.base())
-    report_fatal_error("MemoryManager allocation failed: " + Err);
+    report_fatal_error("MemoryManager allocation failed");
   DataMemory.push_back(MB);
   return (uint8_t*)MB.base();
 }
@@ -453,9 +453,10 @@ static int executeInput() {
 
     // Make sure the memory is executable.
     // setExecutable will call InvalidateInstructionCache.
-    std::string ErrorStr;
-    if (!sys::Memory::setExecutable(FM, &ErrorStr))
-      ErrorAndExit("unable to mark function executable: '" + ErrorStr + "'");
+    std::error_code EC;
+    EC = sys::Memory::protectMappedMemory(FM, sys::Memory::ProtectionMode::MF_EXECUTABLE);
+    if (EC)
+      ErrorAndExit("unable to mark function executable");
   }
 
   // Dispatch to _main().
