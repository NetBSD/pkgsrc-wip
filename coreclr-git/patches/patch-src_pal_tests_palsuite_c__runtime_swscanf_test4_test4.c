$NetBSD$

--- src/pal/tests/palsuite/c_runtime/swscanf/test4/test4.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/c_runtime/swscanf/test4/test4.c
@@ -19,6 +19,7 @@
 
 int __cdecl main(int argc, char *argv[])
 {
+    int n65535 = 65535; /* Walkaround compiler strictness */
 
     if (PAL_Initialize(argc, argv))
     {
@@ -30,7 +31,7 @@ int __cdecl main(int argc, char *argv[])
     DoNumTest(convert("-1"), convert("%d"), -1);
     DoNumTest(convert("0x1234"), convert("%d"), 0);
     DoNumTest(convert("012"), convert("%d"), 12);
-    DoShortNumTest(convert("-1"), convert("%hd"), 65535);
+    DoShortNumTest(convert("-1"), convert("%hd"), n65535);
     DoShortNumTest(convert("65536"), convert("%hd"), 0);
     DoNumTest(convert("-1"), convert("%ld"), -1);
     DoNumTest(convert("65536"), convert("%ld"), 65536);
