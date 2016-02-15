$NetBSD$

--- src/jit/jiteh.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/jit/jiteh.cpp
@@ -3032,7 +3032,7 @@ void                Compiler::fgVerifyHa
 
     // blockNumMap[old block number] => new block number
     size_t blockNumBytes = (bbNumMax + 1) * sizeof(unsigned);
-    unsigned* blockNumMap = (unsigned*)_alloca(blockNumBytes);
+    unsigned* blockNumMap = (unsigned*)Alloca(blockNumBytes);
     memset(blockNumMap, 0, blockNumBytes);
 
     BasicBlock* block;
@@ -3069,8 +3069,8 @@ void                Compiler::fgVerifyHa
     // over all blocks and verify that only handler begin blocks have bbCatchTyp == BBCT_NONE, and some other things.
 
     size_t blockBoolSetBytes = (bbNumMax + 1) * sizeof(bool);
-    bool* blockTryBegSet = (bool*)_alloca(blockBoolSetBytes);
-    bool* blockHndBegSet = (bool*)_alloca(blockBoolSetBytes);
+    bool* blockTryBegSet = (bool*)Alloca(blockBoolSetBytes);
+    bool* blockHndBegSet = (bool*)Alloca(blockBoolSetBytes);
     for (unsigned i = 0; i <= bbNumMax; i++)
     {
         blockTryBegSet[i] = false;
@@ -3390,8 +3390,8 @@ void                Compiler::fgVerifyHa
     // a previously processed handler, so we ignore it.
 
     size_t blockIndexBytes = (bbNumMax + 1) * sizeof(unsigned short);
-    unsigned short* blockTryIndex = (unsigned short*)_alloca(blockIndexBytes);
-    unsigned short* blockHndIndex = (unsigned short*)_alloca(blockIndexBytes);
+    unsigned short* blockTryIndex = (unsigned short*)Alloca(blockIndexBytes);
+    unsigned short* blockHndIndex = (unsigned short*)Alloca(blockIndexBytes);
     memset(blockTryIndex, 0, blockIndexBytes);
     memset(blockHndIndex, 0, blockIndexBytes);
 
