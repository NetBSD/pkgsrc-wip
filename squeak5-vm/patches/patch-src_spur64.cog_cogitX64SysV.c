$NetBSD$

--- src/spur64.cog/cogitX64SysV.c.orig	2022-06-02 14:10:44.000000000 +0000
+++ src/spur64.cog/cogitX64SysV.c
@@ -22979,9 +22979,7 @@ dispatchConcretize(AbstractInstruction *
 			((self_in_dispatchConcretize->operands))[2] = 0;
 			return savedSize1;
 		}
-		if ((reg20 == RAX)
-		 || ((reg20 == RBP)
-		 || (reg20 == RSP))) {
+		if (reg20 == RAX) {
 			offset38 = 0;
 		}
 		else {
