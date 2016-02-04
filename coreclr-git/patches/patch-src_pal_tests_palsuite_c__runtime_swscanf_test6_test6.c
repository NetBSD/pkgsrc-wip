$NetBSD$

--- src/pal/tests/palsuite/c_runtime/swscanf/test6/test6.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/c_runtime/swscanf/test6/test6.c
@@ -19,6 +19,8 @@
 
 int __cdecl main(int argc, char *argv[])
 {
+    int n65535 = 65535; /* Walkaround compiler strictness */
+
     if (PAL_Initialize(argc, argv))
     {
         return FAIL;
@@ -29,7 +31,7 @@ int __cdecl main(int argc, char *argv[])
     DoNumTest(convert("-1"), convert("%o"), -1);
     DoNumTest(convert("0x1234"), convert("%o"), 0);
     DoNumTest(convert("012"), convert("%o"), 10);
-    DoShortNumTest(convert("-1"), convert("%ho"), 65535);
+    DoShortNumTest(convert("-1"), convert("%ho"), n65535);
     DoShortNumTest(convert("200000"), convert("%ho"), 0);
     DoNumTest(convert("-1"), convert("%lo"), -1);
     DoNumTest(convert("200000"), convert("%lo"), 65536);
