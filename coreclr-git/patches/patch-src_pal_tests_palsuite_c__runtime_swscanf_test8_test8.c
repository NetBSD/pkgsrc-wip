$NetBSD$

--- src/pal/tests/palsuite/c_runtime/swscanf/test8/test8.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/c_runtime/swscanf/test8/test8.c
@@ -19,6 +19,8 @@
 
 int __cdecl main(int argc, char *argv[])
 {
+    int n65535 = 65535; /* Walkaround compiler strictness */
+
     if (PAL_Initialize(argc, argv))
     {
         return FAIL;
@@ -29,7 +31,7 @@ int __cdecl main(int argc, char *argv[])
     DoNumTest(convert("-1"), convert("%u"), -1);
     DoNumTest(convert("0x1234"), convert("%u"), 0);
     DoNumTest(convert("012"), convert("%u"), 12);
-    DoShortNumTest(convert("-1"), convert("%hu"), 65535);
+    DoShortNumTest(convert("-1"), convert("%hu"), n65535);
     DoShortNumTest(convert("65536"), convert("%hu"), 0);
     DoNumTest(convert("-1"), convert("%lu"), -1);
     DoNumTest(convert("65536"), convert("%lu"), 65536);
