$NetBSD$

--- target/m68k/fpu_helper.c.orig	2017-09-11 11:41:44.065985219 +0000
+++ target/m68k/fpu_helper.c
@@ -29,7 +29,7 @@
  */
 
 static const floatx80 fpu_rom[128] = {
-    [0x00] = make_floatx80_init(0x4000, 0xc90fdaa22168c235ULL),  /* Pi       */
+    [0x00] = make_floatx80_init(0x4000, 0x0c90fdaa22168c235LL),  /* Pi       */
     [0x0b] = make_floatx80_init(0x3ffd, 0x9a209a84fbcff798ULL),  /* Log10(2) */
     [0x0c] = make_floatx80_init(0x4000, 0xadf85458a2bb4a9aULL),  /* e        */
     [0x0d] = make_floatx80_init(0x3fff, 0xb8aa3b295c17f0bcULL),  /* Log2(e)  */
