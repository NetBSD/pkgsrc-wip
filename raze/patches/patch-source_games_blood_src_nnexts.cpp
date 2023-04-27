$NetBSD$

--- source/games/blood/src/nnexts.cpp.orig	2023-01-07 18:45:29.000000000 +0000
+++ source/games/blood/src/nnexts.cpp
@@ -4203,12 +4203,12 @@ bool condCheckSector(DBloodActor* aCond,
 			case kSectorSlide:
 				if (cond == 55)// 60)
 				{
-					h = max(abs(pXSect->onFloorZ - pXSect->offFloorZ), 1 / 256.);
+					h = std::max(pXSect->onFloorZ - pXSect->offFloorZ, 1 / 256.);
 					curH = abs(pSect->floorz - pXSect->offFloorZ);
 				}
 				else
 				{
-					h = max(abs(pXSect->onCeilZ - pXSect->offCeilZ), 1 / 256.);
+					h = std::max(pXSect->onCeilZ - pXSect->offCeilZ, 1 / 256.);
 					curH = abs(pSect->ceilingz - pXSect->offCeilZ);
 				}
 				return condCmp(int((kPercFull * curH) / h), arg1, arg2, cmpOp);
