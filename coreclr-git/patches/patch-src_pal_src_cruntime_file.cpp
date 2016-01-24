$NetBSD$

--- src/pal/src/cruntime/file.cpp.orig	2016-01-18 21:51:39.000000000 +0000
+++ src/pal/src/cruntime/file.cpp
@@ -841,7 +841,7 @@ PAL_fgetpos (
     PAL_fpos_t *pos
 )
 {
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__NetBSD__)
     // TODO: implement for Linux if required
     ASSERT(FALSE);
     return -1;
@@ -887,7 +887,7 @@ PAL_fsetpos (
     const PAL_fpos_t *pos
 )
 {
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__NetBSD__)
     // TODO: implement for Linux if required
     ASSERT(FALSE);
     return  -1;
