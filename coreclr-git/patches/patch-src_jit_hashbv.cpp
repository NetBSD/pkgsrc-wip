$NetBSD$

--- src/jit/hashbv.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/jit/hashbv.cpp
@@ -530,7 +530,7 @@ void hashBv::Resize(int newSize)
 
     hashBvNode ** newNodes = this->getNewVector(newSize);
 
-    hashBvNode *** insertionPoints = (hashBvNode ***) alloca(sizeof(hashBvNode *)* newSize);
+    hashBvNode *** insertionPoints = (hashBvNode ***) Alloca(sizeof(hashBvNode *)* newSize);
     memset(insertionPoints, 0, sizeof(hashBvNode *)* newSize);
 
     for (int i=0; i<newSize; i++)
@@ -1223,7 +1223,7 @@ template <typename Action> bool hashBv::
     hashBvNode *** cursors;
     int shiftFactor = this->log2_hashSize - other->log2_hashSize;
     int expansionFactor = hts/ots;
-    cursors = (hashBvNode ***) alloca(expansionFactor*sizeof(void*));
+    cursors = (hashBvNode ***) Alloca(expansionFactor*sizeof(void*));
 
     for (int h=0; h<other->hashtable_size(); h++)
     {
