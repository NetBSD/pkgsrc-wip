$NetBSD: patch-cppspec.c,v 1.1.1.1 2003/12/11 22:14:51 johnrshannon Exp $

--- gcc/cppspec.c.orig	2003-12-09 06:28:07.000000000 -0700
+++ gcc/cppspec.c
@@ -86,7 +86,7 @@ lang_specific_driver (int *in_argc, cons
      regularly.  Default to old behaviour here. XXX - move me to
      config/netbsd.h "DEFAULT_CPP_NEED_NO_GCC".  */
 #ifdef DEFAULT_CPP_NEED_NO_GCC
-  need_no_gcc = DEFAULT_CPP_NEED_NO_GCC;
+  int need_no_gcc = DEFAULT_CPP_NEED_NO_GCC;
 #endif
 
   /* First pass.  If we see an -S or -c, barf.  If we see an input file,
