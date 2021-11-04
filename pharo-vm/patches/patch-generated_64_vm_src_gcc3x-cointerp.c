$NetBSD$

Avoid conflict with clone(2)

--- generated/64/vm/src/gcc3x-cointerp.c.orig	2021-10-11 14:05:24.000000000 +0000
+++ generated/64/vm/src/gcc3x-cointerp.c
@@ -1068,7 +1068,7 @@ extern sqInt classTagForClass(sqInt clas
 extern sqInt classUnsafeAlien(void);
 static void clearLeakMapAndMapAccessibleFreeSpace(void);
 static sqInt NoDbgRegParms cloneInOldSpaceforPinning(sqInt objOop, sqInt forPinning);
-extern sqInt clone(sqInt objOop);
+extern sqInt sqClone(sqInt objOop);
 extern sqInt compactClassIndexOf(sqInt objOop);
 static sqInt NoDbgRegParms copyObjtoAddrstopAtsavedFirstFieldsindex(sqInt objOop, sqInt segAddr, sqInt endSeg, sqInt savedFirstFields, sqInt i);
 extern void countMarkedAndUnmarkdObjects(sqInt printFlags);
@@ -46834,7 +46834,7 @@ cloneInOldSpaceforPinning(sqInt objOop, 
 
 	/* SpurMemoryManager>>#clone: */
 sqInt
-clone(sqInt objOop)
+sqClone(sqInt objOop)
 {   DECL_MAYBE_SQ_GLOBAL_STRUCT
     sqInt classIndex;
     sqInt classIndex1;
@@ -54408,14 +54408,14 @@ outOfPlaceBecomeandcopyHashFlag(sqInt ob
 
 	clone1 = (((longAt(obj1)) & (classIndexMask())) == ClassMethodContextCompactIndex
 		? cloneContext(obj1)
-		: clone(obj1));
+		: sqClone(obj1));
 	if (!(clone1)) {
 		error("Not enough space to copy the objects in two-way become. This should have been detected before");
 		return;
 	}
 	clone2 = (((longAt(obj2)) & (classIndexMask())) == ClassMethodContextCompactIndex
 		? cloneContext(obj2)
-		: clone(obj2));
+		: sqClone(obj2));
 	if (!(clone2)) {
 		error("Not enough space to copy the objects in two-way become. This should have been detected before");
 		return;
@@ -75825,7 +75825,7 @@ primitiveClone(void)
 		else {
 			if ((GIV(argumentCount) == 0)
 			 || (!(((longAt(rcvr)) & ((classIndexMask()) - (isForwardedObjectClassIndexPun()))) == 0))) {
-				newCopy = clone(rcvr);
+				newCopy = sqClone(rcvr);
 			}
 			else {
 				newCopy = 0;
