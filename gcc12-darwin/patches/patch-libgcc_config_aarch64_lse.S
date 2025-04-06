$NetBSD$

Fix https://github.com/iains/gcc-12-branch/issues/25
Patch from https://github.com/iains/gcc-12-branch/commit/914cec3

--- libgcc/config/aarch64/lse.S.orig	2025-04-04 11:12:22.678754559 +0000
+++ libgcc/config/aarch64/lse.S
@@ -197,9 +197,9 @@ see the files COPYING3 and COPYING.RUNTI
 	.text
 	.balign	16
 	.private_extern	_\name
-	.cfi_startproc
 _\name:
 	BTI_C
+	.cfi_startproc
 .endm
 
 .macro	ENDFN name
