$NetBSD$

--- src/pal/tests/palsuite/c_runtime/sscanf/test4/test4.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/c_runtime/sscanf/test4/test4.c
@@ -19,6 +19,8 @@
 
 int __cdecl main(int argc, char *argv[])
 {
+    int n65535 = 65535; /* Walkaround compiler strictness */
+
     if (PAL_Initialize(argc, argv))
     {
         return FAIL;
@@ -29,7 +31,7 @@ int __cdecl main(int argc, char *argv[])
     DoNumTest("-1", "%d", -1);
     DoNumTest("0x1234", "%d", 0);
     DoNumTest("012", "%d", 12);
-    DoShortNumTest("-1", "%hd", 65535);
+    DoShortNumTest("-1", "%hd", n65535);
     DoShortNumTest("65536", "%hd", 0);
     DoNumTest("-1", "%ld", -1);
     DoNumTest("65536", "%ld", 65536);
