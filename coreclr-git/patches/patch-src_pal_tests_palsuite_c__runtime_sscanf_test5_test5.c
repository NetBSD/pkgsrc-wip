$NetBSD$

--- src/pal/tests/palsuite/c_runtime/sscanf/test5/test5.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/c_runtime/sscanf/test5/test5.c
@@ -18,6 +18,8 @@
 
 int __cdecl main(int argc, char *argv[])
 {
+    int n65535 = 65535; /* Walkaround compiler strictness */
+
     if (PAL_Initialize(argc, argv))
     {
         return FAIL;
@@ -28,7 +30,7 @@ int __cdecl main(int argc, char *argv[])
     DoNumTest("-1", "%i", -1);
     DoNumTest("0x1234", "%i", 0x1234);
     DoNumTest("012", "%i", 10);
-    DoShortNumTest("-1", "%hi", 65535);
+    DoShortNumTest("-1", "%hi", n65535);
     DoShortNumTest("65536", "%hi", 0);
     DoNumTest("-1", "%li", -1);
     DoNumTest("65536", "%li", 65536);
