$NetBSD: patch-runtime_typedefs.h,v 1.2 2014/07/22 07:44:55 fhajny Exp $

SunOS has off64_t defined.
--- runtime/typedefs.h.orig	2014-03-25 20:37:44.000000000 +0000
+++ runtime/typedefs.h
@@ -157,7 +157,9 @@ typedef enum {
 } fiop_t;
 
 #ifndef HAVE_LSEEK64
+# ifndef __sun
 	typedef off_t off64_t;
+# endif
 #endif
 
 
