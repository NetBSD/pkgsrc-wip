$NetBSD$

--- unbuffered_file.cc.orig	2015-09-16 07:28:04.000000000 +0000
+++ unbuffered_file.cc
@@ -13,7 +13,7 @@
 #include "unbuffered_file.hh"
 
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__) || defined(__FreeBSD__)
 #define lseek64 lseek
 #endif
 
@@ -24,7 +24,7 @@ UnbufferedFile::UnbufferedFile( char con
 
   int flags = ( mode == WriteOnly ? ( O_WRONLY | O_CREAT | O_TRUNC ) :
                                     O_RDONLY );
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__NetBSD__) && !defined(__FreeBSD__) 
   flags |= O_LARGEFILE;
 #endif
   fd = open( fileName, flags, 0666 );
