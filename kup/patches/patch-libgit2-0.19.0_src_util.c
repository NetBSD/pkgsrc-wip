$NetBSD: patch-libgit2-0.19.0_src_util.c,v 1.1 2014/08/10 11:21:07 thomasklausner Exp $

NetBSD does not provide qsort_r().
Already fixed in libgit2 upstream.

--- libgit2-0.19.0/src/util.c.orig	2013-06-24 22:14:45.000000000 +0000
+++ libgit2-0.19.0/src/util.c
@@ -707,7 +707,7 @@ static int GIT_STDLIB_CALL git__qsort_r_
 void git__qsort_r(
 	void *els, size_t nel, size_t elsize, git__sort_r_cmp cmp, void *payload)
 {
-#if defined(__MINGW32__) || defined(__OpenBSD__) || defined(AMIGA) || \
+#if defined(__MINGW32__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(AMIGA) || \
 	defined(__gnu_hurd__) || \
 	(__GLIBC__ == 2 && __GLIBC_MINOR__ < 8)
 	git__insertsort_r(els, nel, elsize, NULL, cmp, payload);
