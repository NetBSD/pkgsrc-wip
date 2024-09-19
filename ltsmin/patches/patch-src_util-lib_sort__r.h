$NetBSD$

NetBSD does not support qsort_r

Upstream: https://github.com/utwente-fmt/ltsmin/issues/203

--- src/util-lib/sort_r.h.orig	2018-07-03 19:28:10.000000000 +0000
+++ src/util-lib/sort_r.h
@@ -182,7 +182,7 @@ static _SORT_R_INLINE void sort_r_simple
   {
     #if defined _SORT_R_LINUX
 
-      #if defined __GLIBC__ && ((__GLIBC__ < 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ < 8))
+      #if defined __GLIBC__ && ((__GLIBC__ < 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ < 8)) || defined __NetBSD__
 
         /* no qsort_r in glibc before 2.8, need to use nested qsort */
         sort_r_simple(base, nel, width, compar, arg);
