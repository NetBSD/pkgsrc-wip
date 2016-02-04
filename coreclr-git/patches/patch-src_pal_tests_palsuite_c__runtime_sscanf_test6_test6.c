$NetBSD$

--- src/pal/tests/palsuite/c_runtime/sscanf/test6/test6.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/c_runtime/sscanf/test6/test6.c
@@ -18,6 +18,7 @@
 
 int __cdecl main(int argc, char *argv[])
 {
+    int n65535 = 65535; /* Walkaround compiler strictness */
 
     if (PAL_Initialize(argc, argv))
     {
@@ -29,7 +30,7 @@ int __cdecl main(int argc, char *argv[])
     DoNumTest("-1", "%o", -1);
     DoNumTest("0x1234", "%o", 0);
     DoNumTest("012", "%o", 10);
-    DoShortNumTest("-1", "%ho", 65535);
+    DoShortNumTest("-1", "%ho", n65535);
     DoShortNumTest("200000", "%ho", 0);
     DoNumTest("-1", "%lo", -1);
     DoNumTest("200000", "%lo", 65536);
