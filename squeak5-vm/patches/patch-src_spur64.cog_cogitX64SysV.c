$NetBSD$

--- src/spur64.cog/cogitX64SysV.c.orig	2026-06-27 09:13:44.000000000 +0000
+++ src/spur64.cog/cogitX64SysV.c
@@ -24484,9 +24484,7 @@ l2:
 		   an interrupt is delivered immediately after that point.  See mail threads beginning with
 		   http://lists.squeakfoundation.org/pipermail/vm-dev/2019-September/031428.html
 		   http://lists.squeakfoundation.org/pipermail/vm-dev/2019-October/031499.html */
-		if ((reg == RAX)
-		 || ((reg == RBP)
-		 || (reg == RSP))) {
+		if (reg == RAX) {
 			offset1 = 0;
 		}
 		else {
