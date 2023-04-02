$NetBSD$

--- libgcc/libgcov.h.orig	2022-08-19 08:09:54.728689966 +0000
+++ libgcc/libgcov.h
@@ -45,6 +45,7 @@
 #include "libgcc_tm.h"
 #include "gcov.h"
 
+#undef HAVE_SYS_MMAN_H
 #if HAVE_SYS_MMAN_H
 #include <sys/mman.h>
 #endif
