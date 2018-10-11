$NetBSD$

--- test/msan/dtls_test.c.orig	2018-08-21 21:25:23.000000000 +0000
+++ test/msan/dtls_test.c
@@ -8,6 +8,9 @@
 
    XFAIL: FreeBSD
    UNSUPPORTED: powerpc
+
+   // Reports use-of-uninitialized-value, not analyzed
+   XFAIL: netbsd
 */
 
 #ifndef BUILD_SO
