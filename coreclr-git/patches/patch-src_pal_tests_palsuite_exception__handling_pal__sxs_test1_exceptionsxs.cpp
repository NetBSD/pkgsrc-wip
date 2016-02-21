$NetBSD$

--- src/pal/tests/palsuite/exception_handling/pal_sxs/test1/exceptionsxs.cpp.orig	2016-02-02 01:31:09.000000000 +0000
+++ src/pal/tests/palsuite/exception_handling/pal_sxs/test1/exceptionsxs.cpp
@@ -20,7 +20,7 @@ extern "C" int DllTest2();
 
 int main(int argc, char *argv[])
 {
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
     if (0 != InitializeDllTest1())
     {
         return 1;
