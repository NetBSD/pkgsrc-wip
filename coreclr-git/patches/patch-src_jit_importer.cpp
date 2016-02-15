$NetBSD$

--- src/jit/importer.cpp.orig	2016-02-12 01:41:34.000000000 +0000
+++ src/jit/importer.cpp
@@ -8470,7 +8470,7 @@ GenTreePtr Compiler::impCastClassOrIsIns
 #define assertImp(cond)                                                        \
             do { if (!(cond)) {                                                \
                 const int cchAssertImpBuf = 600;                               \
-                char *assertImpBuf = (char*)alloca(cchAssertImpBuf);           \
+                char *assertImpBuf = (char*)Alloca(cchAssertImpBuf);           \
                 _snprintf_s(assertImpBuf, cchAssertImpBuf, cchAssertImpBuf - 1,\
                         "%s : Possibly bad IL with CEE_%s at offset %04Xh (op1=%s op2=%s stkDepth=%d)", \
                         #cond, impCurOpcName, impCurOpcOffs,                   \
