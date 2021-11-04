$NetBSD$

--- spur64src/vm/cogitX64SysV.c.orig	2021-02-18 16:42:20.999184653 +0000
+++ spur64src/vm/cogitX64SysV.c
@@ -22288,9 +22288,7 @@ dispatchConcretize(AbstractInstruction *
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
