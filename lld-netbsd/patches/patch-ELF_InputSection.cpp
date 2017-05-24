$NetBSD$

--- ELF/InputSection.cpp.orig	2017-05-24 01:57:45.000000000 +0000
+++ ELF/InputSection.cpp
@@ -23,6 +23,7 @@
 #include "llvm/Support/Compression.h"
 #include "llvm/Support/Endian.h"
 #include "llvm/Support/Path.h"
+#include "llvm/Support/Threading.h"
 #include <mutex>
 
 using namespace llvm;
@@ -866,7 +867,7 @@ const SectionPiece *MergeInputSection::g
 // it is not just an addition to a base output offset.
 uint64_t MergeInputSection::getOffset(uint64_t Offset) const {
   // Initialize OffsetMap lazily.
-  std::call_once(InitOffsetMap, [&] {
+  llvm::call_once(InitOffsetMap, [&] {
     OffsetMap.reserve(Pieces.size());
     for (const SectionPiece &Piece : Pieces)
       OffsetMap[Piece.InputOff] = Piece.OutputOff;
