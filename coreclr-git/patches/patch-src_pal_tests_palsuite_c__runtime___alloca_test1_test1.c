$NetBSD$

--- src/pal/tests/palsuite/c_runtime/_alloca/test1/test1.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/tests/palsuite/c_runtime/_alloca/test1/test1.c
@@ -30,7 +30,7 @@ int __cdecl main(int argc, char **argv)
 
 
     /* check that _alloca really gives us addressable memory */
-    testA = (char *)_alloca(20 * sizeof(char));
+    testA = (char *)Alloca(20 * sizeof(char));
     if (testA == NULL)
     {
         Fail ("The call to _alloca failed\n");
