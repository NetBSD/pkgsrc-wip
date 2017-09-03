$NetBSD$

--- target/m68k/fpu_helper.c.orig	2017-08-25 15:26:31.000000000 +0000
+++ target/m68k/fpu_helper.c
@@ -24,35 +24,6 @@
 #include "exec/exec-all.h"
 #include "exec/cpu_ldst.h"
 
-/* Undefined offsets may be different on various FPU.
- * On 68040 they return 0.0 (floatx80_zero)
- */
-
-static const floatx80 fpu_rom[128] = {
-    [0x00] = floatx80_pi,                                   /* Pi */
-    [0x0b] = make_floatx80(0x3ffd, 0x9a209a84fbcff798ULL),  /* Log10(2) */
-    [0x0c] = make_floatx80(0x4000, 0xadf85458a2bb4a9aULL),  /* e        */
-    [0x0d] = make_floatx80(0x3fff, 0xb8aa3b295c17f0bcULL),  /* Log2(e)  */
-    [0x0e] = make_floatx80(0x3ffd, 0xde5bd8a937287195ULL),  /* Log10(e) */
-    [0x0f] = floatx80_zero,                                 /* Zero     */
-    [0x30] = floatx80_ln2,                                  /* ln(2)    */
-    [0x31] = make_floatx80(0x4000, 0x935d8dddaaa8ac17ULL),  /* ln(10)   */
-    [0x32] = floatx80_one,                                  /* 10^0     */
-    [0x33] = make_floatx80(0x4002, 0xa000000000000000ULL),  /* 10^1     */
-    [0x34] = make_floatx80(0x4005, 0xc800000000000000ULL),  /* 10^2     */
-    [0x35] = make_floatx80(0x400c, 0x9c40000000000000ULL),  /* 10^4     */
-    [0x36] = make_floatx80(0x4019, 0xbebc200000000000ULL),  /* 10^8     */
-    [0x37] = make_floatx80(0x4034, 0x8e1bc9bf04000000ULL),  /* 10^16    */
-    [0x38] = make_floatx80(0x4069, 0x9dc5ada82b70b59eULL),  /* 10^32    */
-    [0x39] = make_floatx80(0x40d3, 0xc2781f49ffcfa6d5ULL),  /* 10^64    */
-    [0x3a] = make_floatx80(0x41a8, 0x93ba47c980e98ce0ULL),  /* 10^128   */
-    [0x3b] = make_floatx80(0x4351, 0xaa7eebfb9df9de8eULL),  /* 10^256   */
-    [0x3c] = make_floatx80(0x46a3, 0xe319a0aea60e91c7ULL),  /* 10^512   */
-    [0x3d] = make_floatx80(0x4d48, 0xc976758681750c17ULL),  /* 10^1024  */
-    [0x3e] = make_floatx80(0x5a92, 0x9e8b3b5dc53d5de5ULL),  /* 10^2048  */
-    [0x3f] = make_floatx80(0x7525, 0xc46052028a20979bULL),  /* 10^4096  */
-};
-
 int32_t HELPER(reds32)(CPUM68KState *env, FPReg *val)
 {
     return floatx80_to_int32(val->d, &env->fp_status);
@@ -387,7 +358,84 @@ void HELPER(ftst)(CPUM68KState *env, FPR
 
 void HELPER(fconst)(CPUM68KState *env, FPReg *val, uint32_t offset)
 {
-    val->d = fpu_rom[offset];
+    floatx80 tmp;
+
+    /* Undefined offsets may be different on various FPU.
+     * On 68040 they return 0.0 (floatx80_zero)
+     */
+    switch(offset) {
+    case 0x00:
+        tmp = floatx80_pi;                                   /* Pi */
+        break;
+    case 0x0b:
+        tmp = make_floatx80(0x3ffd, 0x9a209a84fbcff798ULL);  /* Log10(2) */
+        break;
+    case 0x0c:
+        tmp = make_floatx80(0x4000, 0xadf85458a2bb4a9aULL);  /* e        */
+        break;
+    case 0x0d:
+        tmp = make_floatx80(0x3fff, 0xb8aa3b295c17f0bcULL);  /* Log2(e)  */
+        break;
+    case 0x0e:
+        tmp = make_floatx80(0x3ffd, 0xde5bd8a937287195ULL);  /* Log10(e) */
+        break;
+    case 0x0f:
+        tmp = floatx80_zero;                                 /* Zero     */
+        break;
+    case 0x30:
+        tmp = floatx80_ln2;                                  /* ln(2)    */
+        break;
+    case 0x31:
+        tmp = make_floatx80(0x4000, 0x935d8dddaaa8ac17ULL);  /* ln(10)   */
+        break;
+    case 0x32:
+        tmp = floatx80_one;                                  /* 10^0     */
+        break;
+    case 0x33:
+        tmp = make_floatx80(0x4002, 0xa000000000000000ULL);  /* 10^1     */
+        break;
+    case 0x34:
+        tmp = make_floatx80(0x4005, 0xc800000000000000ULL);  /* 10^2     */
+        break;
+    case 0x35:
+        tmp = make_floatx80(0x400c, 0x9c40000000000000ULL);  /* 10^4     */
+        break;
+    case 0x36:
+        tmp = make_floatx80(0x4019, 0xbebc200000000000ULL);  /* 10^8     */
+        break;
+    case 0x37:
+        tmp = make_floatx80(0x4034, 0x8e1bc9bf04000000ULL);  /* 10^16    */
+        break;
+    case 0x38:
+        tmp = make_floatx80(0x4069, 0x9dc5ada82b70b59eULL);  /* 10^32    */
+        break;
+    case 0x39:
+        tmp = make_floatx80(0x40d3, 0xc2781f49ffcfa6d5ULL);  /* 10^64    */
+        break;
+    case 0x3a:
+        tmp = make_floatx80(0x41a8, 0x93ba47c980e98ce0ULL);  /* 10^128   */
+        break;
+    case 0x3b:
+        tmp = make_floatx80(0x4351, 0xaa7eebfb9df9de8eULL);  /* 10^256   */
+        break;
+    case 0x3c:
+        tmp = make_floatx80(0x46a3, 0xe319a0aea60e91c7ULL);  /* 10^512   */
+        break;
+    case 0x3d:
+        tmp = make_floatx80(0x4d48, 0xc976758681750c17ULL);  /* 10^1024  */
+        break;
+    case 0x3e:
+        tmp = make_floatx80(0x5a92, 0x9e8b3b5dc53d5de5ULL);  /* 10^2048  */
+        break;
+    case 0x3f:
+        tmp = make_floatx80(0x7525, 0xc46052028a20979bULL);  /* 10^4096  */
+        break;
+    default:
+        tmp = floatx80_zero;
+        break;
+    }
+
+    val->d = tmp;
 }
 
 typedef int (*float_access)(CPUM68KState *env, uint32_t addr, FPReg *fp,
