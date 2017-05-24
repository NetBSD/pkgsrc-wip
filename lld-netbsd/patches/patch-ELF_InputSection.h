$NetBSD$

--- ELF/InputSection.h.orig	2017-05-24 01:57:45.000000000 +0000
+++ ELF/InputSection.h
@@ -18,6 +18,7 @@
 #include "llvm/ADT/DenseSet.h"
 #include "llvm/ADT/TinyPtrVector.h"
 #include "llvm/Object/ELF.h"
+#include "llvm/Support/Threading.h"
 #include <mutex>
 
 namespace lld {
@@ -248,7 +249,7 @@ private:
   std::vector<uint32_t> Hashes;
 
   mutable llvm::DenseMap<uint64_t, uint64_t> OffsetMap;
-  mutable std::once_flag InitOffsetMap;
+  mutable llvm::once_flag InitOffsetMap;
 
   llvm::DenseSet<uint64_t> LiveOffsets;
 };
