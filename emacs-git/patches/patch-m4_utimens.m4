$NetBSD$

NetBSD utimens fix from gnulib

--- m4/utimens.m4.orig	2024-06-24 08:03:06.000000000 +0000
+++ m4/utimens.m4
@@ -1,5 +1,5 @@
 # utimens.m4
-# serial 16
+# serial 17
 dnl Copyright (C) 2003-2024 Free Software Foundation, Inc.
 dnl This file is free software; the Free Software Foundation
 dnl gives unlimited permission to copy and/or distribute it,
@@ -16,6 +16,7 @@ AC_DEFUN([gl_UTIMENS],
   gl_CHECK_FUNCS_ANDROID([lutimes], [[#include <sys/time.h>]])
   gl_CHECK_FUNCS_ANDROID([futimens], [[#include <sys/stat.h>]])
   gl_CHECK_FUNCS_ANDROID([utimensat], [[#include <sys/stat.h>]])
+  AC_CHECK_FUNCS_ONCE([utimens lutimens])
 
   if test $ac_cv_func_futimens = no && test $ac_cv_func_futimesat = yes; then
     dnl FreeBSD 8.0-rc2 mishandles futimesat(fd,NULL,time).  It is not
