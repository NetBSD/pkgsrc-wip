$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/threadasm.S.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/threadasm.S
@@ -13,7 +13,7 @@
  *          http://www.boost.org/LICENSE_1_0.txt)
  */
 
-#if (defined(__linux__) || defined(__FreeBSD__)) && defined(__ELF__)
+#if (defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)) && defined(__ELF__)
 /*
  * Mark the resulting object file as not requiring execution permissions on
  * stack memory. The absence of this section would mark the whole resulting
