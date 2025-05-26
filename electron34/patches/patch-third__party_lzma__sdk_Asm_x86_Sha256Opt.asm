$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/Asm/x86/Sha256Opt.asm.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/Asm/x86/Sha256Opt.asm
@@ -1,5 +1,5 @@
 ; Sha256Opt.asm -- SHA-256 optimized code for SHA-256 x86 hardware instructions
-; 2022-04-17 : Igor Pavlov : Public domain
+; 2024-06-16 : Igor Pavlov : Public domain
 
 include 7zAsm.asm
 
@@ -20,7 +20,7 @@ endif
 EXTRN   K_CONST:xmmword
 @
 
-CONST   SEGMENT
+CONST   SEGMENT READONLY
 
 align 16
 Reverse_Endian_Mask db 3,2,1,0, 7,6,5,4, 11,10,9,8, 15,14,13,12
