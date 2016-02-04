$NetBSD$

--- src/pal/tests/palsuite/c_runtime/sscanf/test7/test7.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/c_runtime/sscanf/test7/test7.c
@@ -18,6 +18,8 @@
 
 int __cdecl main(int argc, char *argv[])
 {
+    int n65535 = 65535; /* Walkaround compiler strictness */
+
     if (PAL_Initialize(argc, argv))
     {
         return FAIL;
@@ -28,7 +30,7 @@ int __cdecl main(int argc, char *argv[])
     DoNumTest("-1", "%x", -1);
     DoNumTest("0x1234", "%x", 0x1234);
     DoNumTest("012", "%x", 0x12);
-    DoShortNumTest("-1", "%hx", 65535);
+    DoShortNumTest("-1", "%hx", n65535);
     DoShortNumTest("10000", "%hx", 0);
     DoNumTest("-1", "%lx", -1);
     DoNumTest("10000", "%lx", 65536);
